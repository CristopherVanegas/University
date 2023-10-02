import express from 'express';

const router = express.Router(); //Crear el enrutador

import checkAuth from '../middleware/checkAuth.js'; //Importar el middleware

//Importar el controlador
import { registrar, autenticar, cambiarCorreo, cambiarPassword, trabajaConNosotros } from '../controllers/usuarioController.js';

//Routing
router.post('/registrar', registrar); //Crear un usuario
router.post('/login', autenticar); //Obtener todos los usuarios
router.post('/cambiar-correo', checkAuth, cambiarCorreo); //Cambiar correo
router.post('/cambiar-password', checkAuth, cambiarPassword); //Cambiar password
router.post('/trabaja-con-nosotros', checkAuth, trabajaConNosotros ) //Trabaja con nosotros

export default router; //Exportar el enrutador