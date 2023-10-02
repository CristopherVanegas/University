//Importar express (servidor), dotenv(varibles de entorno) y cors
import express from "express";
import dotenv from "dotenv";
import cors from "cors";

//Importar las rutas
import usuarioRoutes from "./routes/usuarioRoutes.js";
import productoRoutes from "./routes/productoRoutes.js";
import ordenRoutes from "./routes/ordenRoutes.js";

dotenv.config({ path: "./.env" });

const app = express(); //Crear el servidor
app.use(express.json()) //Para que express pueda leer los datos que se envian desde el fronted

//Configurar CORS
const whiteList = ['http://localhost:3000', 'http://172.29.160.1:3000/', 'http://localhost:3001', 'http://192.168.100.18:3001, http://localhost:3002']; //Fronted permitidos

const corsOption = {
    origin: function (origin, callback) { //El origin detecta que fronted esta realizando la peticion
        if (whiteList.indexOf(origin) !== -1 || !origin) { //Si el origin que hace la peticion esta en whiteList entonces puede hacer la consulta a la API
            callback(null, true); //Damos acceso
        } else {
            //No esta permitido
            callback(new Error("Error de Cors"))
        }
    }
}

app.use(cors(corsOption)) //Le decimos a express que use cors

//Routing
app.use("/api/usuarios", usuarioRoutes); //Ruta para los usuarios
app.use("/api/productos", productoRoutes); //Ruta para los productos
app.use("/api/ordenes", ordenRoutes); //Ruta para los pedidos

const PORT = process.env.PORT || 5000; //Puerto de la API

app.listen(PORT, () => { //Levantar el servidor
    console.log(`Servidor corriendo en el puerto ${PORT}`);
});