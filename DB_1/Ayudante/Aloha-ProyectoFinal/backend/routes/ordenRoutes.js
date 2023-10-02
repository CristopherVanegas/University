import express from 'express';

const router = express.Router(); //Crear el enrutador

import checkAuth from '../middleware/checkAuth.js'; //Importar el middleware

//Importar el controlador
import { crearOrden, obtenerOrden, obtenerOrdenes, cambiarEstadoOrden } from '../controllers/ordenController.js';

//Routing
router.post('/crear-orden', checkAuth, crearOrden); //Crear una orden
router.get('/', checkAuth, obtenerOrdenes); //Obtener todas las ordenes
router.get('/:id', obtenerOrden); //Obtener UNA orden por su ID

router.post('/cambiar-estado/:id', checkAuth, cambiarEstadoOrden); //Cambiar el estado de una orden por su ID

export default router; //Exportar el enrutador