import jwt from "jsonwebtoken"
import conectarDB from "../config/db.js";

const checkAuth = async (req, res, next) => {
    let token;
  
    if(req.headers.authorization && req.headers.authorization.startsWith("Bearer")){
        try {
            token = req.headers.authorization.split(" ")[1];
            const decoded = jwt.verify(token, process.env.JWT_SECRET);

            const usuario = await conectarDB(`SELECT id_usuario, email, nombre FROM usuario WHERE id_usuario = '${decoded.id}'`);
            
            if (usuario.length === 0) {
                // Si el usuario no se encuentra en la base de datos, retornamos un error 404
                return res.status(404).json({ msg: "Usuario no encontrado" });
            }

            req.usuario = usuario[0]; // Tomamos el primer usuario del array (si solo esperas un usuario)
            return next();
        } catch (error) {
            return res.status(500).json({ msg: "Hubo un error al verificar el token" });
        }
    }

    if(!token){
        const error = new Error("Token no válido");
        return res.status(401).json({ msg: error.message });
    }
}

export default checkAuth;
