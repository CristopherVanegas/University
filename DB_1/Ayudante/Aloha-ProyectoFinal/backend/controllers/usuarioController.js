import bcrypt from 'bcrypt';

import generarJWT from '../helpers/generarJWT.js';
import conectarDB from '../config/db.js';

const registrar = async (req, res) => {
    try {

        //Extraer email y password del body
        const { email, nombre, apellido, telefono } = req.body; //Extraer los datos del body
        var { password } = req.body;

        const existeUsuario = await conectarDB(`SELECT * FROM usuario WHERE email = '${email}'`)

        //Buscar si el usuario ya esta registrado
        if (existeUsuario.length > 0) {
            const error = new Error("Usuario ya registrado")
            return res.status(400).json({ msg: error.message })
        }

        const salt = await bcrypt.genSalt(10); //Generar el salt
        password = await bcrypt.hash(password, salt); //Encriptar el password

        //Crear el usuario
        const usuario = await conectarDB(`INSERT INTO usuario (nombre, apellido, email, password, telefono) VALUES ('${nombre}', '${apellido}', '${email}', '${password}', '${telefono}') RETURNING *`)

        const token = generarJWT(usuario.id_usuario)

        res.json({ msg: 'Usuario Creado Correctamente', usuario, token })

    } catch (error) {
        console.log(error);
    }
}

const autenticar = async (req, res) => {

    const { email, password } = req.body;
    
    //Comprobar si el usuario existe
    const existeUsuario = await conectarDB(`SELECT * FROM usuario WHERE email = '${email}'`)

    //Buscar si el usuario ya esta registrado
    if (existeUsuario.length == 0) {
        const error = new Error("El usuario no exsite")
        return res.status(400).json({ msg: error.message })
    }

    //Comprobar su password
    const usuario = existeUsuario[0];

    //Desencriptar el password y compararlo con el que se envia en el body
    if (await bcrypt.compare(password, usuario.password)) {

        //Generar el JWT
        const token = generarJWT(usuario.id_usuario)

        res.json({ msg: 'Usuario autenticado correctamente', usuario, token })
    }
    else {
        const error = new Error('Contraseña incorecta')
        return res.status(403).json({ msg: error.message })
    }
}

const cambiarCorreo = async (req, res) => {
    const { email, nuevoCorreo } = req.body;

    // Equivalencia
    // const email = req.body.email;
    // const nuevoCorreo = req.body.nuevoCorreo;

    try {
        const existeUsuario = await conectarDB(`SELECT * FROM usuario WHERE email = '${email}'`) // Devuelve un array con el usuario y si no existe devuelve un array vacio

        //Buscar si el usuario existe
        if (existeUsuario.length == 0) {
            const error = new Error("Hubo un error al actualizar el correo")
            return res.status(400).json({ msg: error.message })
        }

        // Actualizamos el correo del usuario
        await conectarDB(`UPDATE usuario SET email = '${nuevoCorreo}' WHERE email = '${email}'`)

        res.json({ msg: "Correo cambiado correctamente" }); //Enviar respuesta
    } catch (error) {
        console.log(error);
    }
};

const cambiarPassword = async (req, res) => {
    const { email, password, nuevoPassword } = req.body;

    try {
        const existeUsuario = await conectarDB(`SELECT * FROM usuario WHERE email = '${email}'`)

        //Buscar si el usuario ya esta registrado
        if (existeUsuario.length == 0) {
            const error = new Error("Hubo un error al actualizar la contraseña")
            return res.status(400).json({ msg: error.message })
        }

        //Comprobar su password
        const usuario = existeUsuario[0];

        //Desencriptar el password y compararlo con el que se envia en el body
        if (await bcrypt.compare(password, usuario.password)) {

            const salt = await bcrypt.genSalt(10); //Generar el salt
            const nuevoPasswordEncriptado = await bcrypt.hash(nuevoPassword, salt); //Encriptar el password

            // Actualizamos el correo del usuario
            await conectarDB(`UPDATE usuario SET password = '${nuevoPasswordEncriptado}' WHERE email = '${email}'`)

            res.json({ msg: "Contraseña cambiada correctamente" });
        }
        else {
            const error = new Error('Contraseña incorecta')
            return res.status(403).json({ msg: error.message })
        }
    }
    catch (error) {
        console.log(error);
    }
}

const trabajaConNosotros = async (req, res) => {
    const { email, experiencia } = req.body;
    let { detalleExperiencia } = req.body;
    
    if(experiencia == false) detalleExperiencia = "sin experiencia";

    try {

        // Validar que la experiencia sea valida si es que tiene experiencia
        if (experiencia == true && detalleExperiencia != "cocina" && detalleExperiencia != "mesero" && detalleExperiencia != "cajero" && detalleExperiencia != "todas") {
            const error = new Error("La experiencia no es valida")
            return res.status(400).json({ msg: error.message })
        }

        // Buscar el id del usuario
        const existeUsuario = await conectarDB(`SELECT id_usuario FROM usuario WHERE email = '${email}'`)
        const id_usuario = existeUsuario[0]

        //Buscar si el usuario ya esta registrado
        const existePostulacion = await conectarDB(`SELECT * FROM postulacion WHERE id_usuario = '${id_usuario}'`)

        // Si ya existe una postulacion, no se puede volver a postular
        if (existePostulacion.length > 0) {
            const error = new Error("Ya has enviado tu solicitud antes, por favor espera a que te contactemos")
            return res.status(400).json({ msg: error.message })
        }

        // Guardar la postulacion
        await conectarDB(`INSERT INTO postulacion (id_usuario, experiencia, detalle_experiencia) VALUES ('${id_usuario}', '${experiencia}', '${detalleExperiencia}')`)

        res.json({ msg: "Solicitud recibida correctamente, ahora envía tu CV por email" });
    } catch (error) {
        console.log(error);
    }
}

export { registrar, autenticar, cambiarCorreo, cambiarPassword, trabajaConNosotros };