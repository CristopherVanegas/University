import conectarDB from '../config/db.js';

const obtenerProductos = async (req, res) => {
    try {
        // Obtener los productos y el nombre de la categoria que esta relacionada con el producto
        const productos = await conectarDB(`SELECT producto.id_producto, producto.nombre, producto.descripcion, producto.precio, producto.imagen, categoria.nombre AS categoria FROM producto INNER JOIN categoria ON producto.id_categoria = categoria.id_categoria`);

        res.json(productos);

    } catch (error) {
        console.log(error);
        res.status(500).json({ msg: "Hubo un error al obtener los productos" });
    }
}

const crearNuevoProducto = async (req, res) => {
    const { nombre, descripcion, precio, imagen, id_categoria } = req.body;

    try {
        const existeProducto = await conectarDB(`SELECT * FROM producto WHERE nombre = '${nombre}'`)

        //Buscar si el producto ya esta registrado
        if (existeProducto.length != 0) {
            const error = new Error("El producto ya existe")
            return res.status(400).json({ msg: error.message })
        }

        // Crear el producto
        await conectarDB(`INSERT INTO producto (nombre, descripcion, precio, imagen, id_categoria) VALUES ('${nombre}', '${descripcion}', '${precio}', '${imagen}', '${id_categoria}')`)

        res.json({ msg: "Producto creado correctamente" });
    } catch (error) {
        console.log(error);
        res.status(500).json({ msg: "Hubo un error al crear el producto" });
    }
}

const actualizarProducto = async (req, res) => {
    const { nombre, descripcion, precio, imagen, id_categoria } = req.body;
    const { id } = req.params;

    try {
        const existeProducto = await conectarDB(`SELECT * FROM producto WHERE id_producto = '${id}'`)

        //Buscar si el producto ya esta registrado
        if (existeProducto.length == 0) {
            const error = new Error("El producto no existe")
            return res.status(400).json({ msg: error.message })
        }

        // Crear el producto
        await conectarDB(`UPDATE producto SET nombre = '${nombre}', descripcion = '${descripcion}', precio = '${precio}', imagen = '${imagen}', id_categoria = '${id_categoria}' WHERE id_producto = '${id}'`)

        res.json({ msg: "Producto actualizado correctamente" });
    } catch (error) {
        console.log(error);
        res.status(500).json({ msg: "Hubo un error al actualizar el producto" });
    }
}

export { obtenerProductos, crearNuevoProducto, actualizarProducto };