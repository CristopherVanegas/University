import express from 'express';

const router = express.Router(); //Crear el enrutador

import checkAuth from '../middleware/checkAuth.js'; //Importar el middleware

//Importar el controlador
import { obtenerProductos, crearNuevoProducto } from '../controllers/productoController.js';

//Routing
router.get('/', obtenerProductos); //Obtener todos los productos
router.post('/crear-producto', checkAuth, crearNuevoProducto); //Crear un nuevo producto

export default router; //Exportar el enrutador