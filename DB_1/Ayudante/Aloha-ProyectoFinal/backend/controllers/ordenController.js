import conectarDB from "../config/db.js";
import locales from "../helpers/locales.js";

const crearOrden = async (req, res) => {
    try {

        // Obtener los datos del cuerpo de la petición
        const { email, total, productos, localComercial } = req.body;

        const id_sucursal = locales(localComercial);

        //Comprobar que tenga productos la orden
        if (productos.length <= 0) {
            const error = new Error('Hubo un error con la orden, tiene 0 productos');
            return res.status(404).json({ msg: error.message })
        }

        // Buscar el usuario por su ID
        const existeUsuario = await conectarDB(`SELECT id_usuario FROM usuario WHERE email = '${email}'`)

        const id_usuario = existeUsuario[0].id_usuario;

        //Usuario no encontrado
        if (!existeUsuario) {
            const error = new Error('El usuario no exsite');
            return res.status(404).json({ msg: error.message })
        }

        // Crear la orden
        let orden;

        try {
            orden = await conectarDB(`INSERT INTO orden (id_usuario, id_sucursal, valor_total, estado) VALUES ('${id_usuario}', '${id_sucursal}', '${total}', 'Creada') RETURNING *`);

        } catch (error) {
            error = new Error('Hubo un error con la orden, no se pudo guardar la orden');
            return res.status(404).json({ msg: error.message })
        }

        // productos es un array de objetos, entonces neceisto crear un nuevoDetalleOrden por cada objeto

        let nuevoDetalleOrden = {};

        // Recorrer el array de productos para crear el detalle de la orden de cada producto
        productos.forEach(async (producto) => {
            const { id_producto, cantidad, precio } = producto; // Desestructurar el objeto producto

            // Crear el detalle de la orden
            try {
                nuevoDetalleOrden = await conectarDB(`INSERT INTO detalle_orden (id_producto, cantidad, subtotal, id_orden) VALUES ('${id_producto}', '${cantidad}', '${precio * cantidad}', '${orden[0].id_orden}') RETURNING *`);

            } catch (error) {
                error = new Error('Hubo un error con la orden, no se pudo guardar el detalle de la orden');
                return res.status(404).json({ msg: error.message })
            }
        })

        // Devolver la orden guardado como respuesta
        res.status(200).json({ msg: 'Orden creado correctamente', orden: orden[0] });

    } catch (error) {
        console.log(error);
        res.status(500).json({ error: error.message });
    }
};

const obtenerOrden = async (req, res) => {
    try {

        const { id } = req.params;

        const orden = await conectarDB(`SELECT * FROM orden WHERE id_orden = '${id}'`);

        if (!orden[0].id_orden) {
            return res.status(404).json({ msg: 'No existe la orden' });
        }

        res.status(200).json(orden[0]);

    } catch (error) {
        console.log(error);
        res.status(500).json({ error: error.message });
    }
}

const obtenerOrdenes = async (req, res) => {

    if(req.usuario.email !== process.env.ADMIN_EMAIL){
        return res.status(401).json({ msg: "No tienes permisos para realizar esta acción" });
    }

    try {
        // Traigo todo lo que necesito de la orden y lo que no (detalle_orden.subtotal, producto.imagen, producto.precio, producto.descripcion, sucursal.direccion, sucursal.telefono, sucursal.email)

        const ordenes = await conectarDB(`
            SELECT
                orden.id_orden,
                orden.valor_total,
                orden.estado,
                sucursal.nombre AS nombre_sucursal,
                usuario.nombre AS nombre_usuario,
                ARRAY_AGG(
                    JSON_BUILD_OBJECT( -- Creo un objeto JSON con los datos que necesito
                        'nombre', producto.nombre,
                        'cantidad', detalle_orden.cantidad
                    )
                ) AS productos
            
            FROM orden
            
            INNER JOIN detalle_orden ON orden.id_orden = detalle_orden.id_orden
            INNER JOIN producto ON detalle_orden.id_producto = producto.id_producto
            INNER JOIN sucursal ON orden.id_sucursal = sucursal.id_sucursal
            INNER JOIN usuario ON orden.id_usuario = usuario.id_usuario

            GROUP BY orden.id_orden, orden.valor_total, orden.estado, sucursal.nombre, usuario.nombre --  La cláusula "GROUP BY" asegura que los resultados se agrupen por orden para que cada orden tenga su propio array de productos.

            ORDER BY orden.id_orden DESC
        `);

        // if (ordenes.length <= 0) {
        //     return res.status(404).json({ msg: 'No existen ordenes' });
        // }

        res.status(200).json(ordenes);

    } catch (error) {
        console.log(error);
        res.status(500).json({ error: error.message });
    }
}

const cambiarEstadoOrden = async (req, res) => {

    if(req.usuario.email !== process.env.ADMIN_EMAIL){
        return res.status(401).json({ msg: "No tienes permisos para realizar esta acción" });
    }
    
    try {
        const { id } = req.params;
        const { estado } = req.body;

        const orden = await conectarDB(`SELECT * FROM orden WHERE id_orden = '${id}'`);

        if (!orden[0].id_orden) {
            return res.status(404).json({ msg: 'No existe la orden' });
        }

        await conectarDB(`UPDATE orden SET estado = '${estado}' WHERE id_orden = '${id}'`);

        res.status(200).json({ msg: 'Estado de la orden actualizado correctamente' });

    } catch (error) {
        console.log(error);
        res.status(500).json({ error: error.message });
    }
}

export { crearOrden, obtenerOrden, obtenerOrdenes, cambiarEstadoOrden }