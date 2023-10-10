<?php
    require_once("../Modelo/TablasBD.php");
    
    $Obj_Tabla = new TablasBD();

    switch($_POST['Opcion']){

        case 'CONSULTAR_USUARIO':

            // > CONSULTAR_USUARIO: Muestra en una tabla los usuarios registrados. [Función para administradores].
            // > Es llamado por Administrador.html en [Vista].
            $Datos = $Obj_Tabla->ObtenerTotalDatos("usuario");
            $Tabla = "";

            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Nombre_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Apellido_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Correo_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Rol_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Telefono_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Direccion_Usuario']."</td>";
            }

            echo $Tabla;
            break;

        case 'INSERTAR_USUARIO':
                
            // > INSERTAR_USUARIO: Recibe los parámetros del formulario y los ingresa en la Base de Datos.
            // > Es llamado por RegistroUsuario.html en [Vista].
            $Datos['Nombre_Usuario'] = $_POST['NOMBRE'];
            $Datos['Apellido_Usuario'] = $_POST['APELLIDO'];
            $Datos['User_Usuario'] = $_POST['USUARIO'];
            $Datos['Contrasenia_Usuario'] = $_POST['CONTRASENIA'];
            $Datos['Correo_Usuario'] = $_POST['CORREO'];
            $Datos['Rol_Usuario'] = $_POST['ROL'];
            $Datos['FechaCreacion_Usuario'] = date("Y-m-d");
            $Datos['Tarjeta_Usuario'] = $_POST['TARJETA'];
            $Datos['Telefono_Usuario'] = $_POST['TELEFONO'];
            $Datos['Direccion_Usuario'] = $_POST['DIRECCION'];
            echo ($Obj_Tabla->InsertarDatosTabla("usuario", $Datos));
            break;
        
        case 'ACTUALIZAR_USUARIO':

            // > ACTUALIZAR_USUARIO: Recibe los parámetros del formulario a actualizar.
            // > Es llamado por ActualizarUsuario.html en [Vista].
            
            $ID_DatoEliminar = $_POST['USUARIO_ACTUALIZAR'];
            $Rol_Usuario = $_POST['ROL'];

            echo ($Obj_Tabla->ActualizarDato("usuario", "Rol_Usuario", $Rol_Usuario, $ID_DatoEliminar));
            break;

        case 'CONSULTAR_CIUDAD_ORIGEN':
            // > CONSULTAR_CIUDAD_ORIGEN: Recibe los parámetros del formulario y los ingresa en la Base de Datos.
            // > Es llamado por CiudadesRegistradas.html [Vista -> Administrador].
            $Datos = $Obj_Tabla->ObtenerTotalDatos("origen_viaje");
            $Tabla = "";

            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_OrigenViaje']."</td>";
                $Tabla.=   "<td>".$Fila['Ciudad_Origen']."</td>";
                $Tabla.=   "<td>".$Fila['Pais_Origen']."</td>";
                $Tabla.=   "<td>".$Fila['Aeropuerto_Origen']."</td>";
                $Tabla.=   "<td>"."Ciudad de Origen"."</td>";
            }

            echo $Tabla;
            break;

        case 'CONSULTAR_CIUDAD_DESTINO':
            // > CONSULTAR_CIUDAD_DESTINO: Recibe los parámetros del formulario y los ingresa en la Base de Datos.
            // > Es llamado por CiudadesRegistradas.html [Vista -> Administrador].
            $Datos = $Obj_Tabla->ObtenerTotalDatos("destino_viaje");
            $Tabla = "";

            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_DestinoViaje']."</td>";
                $Tabla.=   "<td>".$Fila['Ciudad_Destino']."</td>";
                $Tabla.=   "<td>".$Fila['Pais_Destino']."</td>";
                $Tabla.=   "<td>".$Fila['Aeropuerto_Destino']."</td>";
                $Tabla.=   "<td>"."Ciudad de Destino"."</td>";
            }

            echo $Tabla;
            break;

        case 'INSERTAR_CIUDAD':
            // > INSERTAR_CIUDAD: Inserta en la Base de Datos una Ciudad de Origen, o una Ciudad de Destino.
            // > Es llamado por RegistrarCiudad.html en [Vista].
            $Identificador = $_POST['IDENTIFICADOR'];

            if($Identificador == 'ORIGEN'){
                $Datos['Ciudad_Origen'] = $_POST['NOMBRE_CIUDAD'];
                $Datos['Pais_Origen'] = $_POST['NOMBRE_PAIS'];
                $Datos['Aeropuerto_Origen'] = $_POST['AEROPUERTO'];
                echo ($Obj_Tabla->InsertarDatosTabla("origen_viaje", $Datos));
            } else {
                $Datos['Ciudad_Destino'] = $_POST['NOMBRE_CIUDAD'];
                $Datos['Pais_Destino'] = $_POST['NOMBRE_PAIS'];
                $Datos['Aeropuerto_Destino'] = $_POST['AEROPUERTO'];
                echo ($Obj_Tabla->InsertarDatosTabla("destino_viaje", $Datos));
            }
            
            break;
        
        case 'ELIMINAR_CIUDAD':
            // > ELIMINAR_CIUDAD: Dependiendo de su IDENTIFICACIÓN, elimina.
            // > Es llamado por EliminarCiudad.html en [VISTA / ADMINISTRADOR].
            $Identificacion_Ciudad = $_POST['IDENTIFICACION_CIUDAD'];
            $ID_DatoEliminar = $_POST['CIUDAD_ELIMINAR'];

            if($Identificacion_Ciudad == 'CIUDAD_ORIGEN'){
                echo ($Obj_Tabla->EliminarDato("origen_viaje", "ID_OrigenViaje", $ID_DatoEliminar));
            } else {
                echo ($Obj_Tabla->EliminarDato("destino_viaje", "ID_DestinoViaje", $ID_DatoEliminar));
            }

            break;
        
        case 'ELIMINAR_USUARIO':
            // > ELIMINAR_USUARIO: Elimina cualquier usuario registrado.
            // > Es llamado por EliminarUsuario.html en [Vista].
            $ID_DatoEliminar = $_POST['USUARIO_ELIMINAR'];

            echo ($Obj_Tabla->EliminarDato("usuario", "ID_Usuario ", $ID_DatoEliminar));
            break;

        case 'INSERTAR_PAQUETE':
            $Datos['Nombre_Paquete'] = $_POST['NOMBRE_PAQUETE'];
            $Datos['Actividades'] = $_POST['ACTIVIDADES_PAQUETE'];
            echo ($Obj_Tabla->InsertarDatosTabla("paquete_turistico", $Datos));

            break;

        case 'CONSULTAR_PAQUETES':
            // > CONSULTAR_PAQUETES: Recibe los parámetros del formulario y los ingresa en la Base de Datos.
            // > Es llamado por PaquetesRegistrados.html [Vista -> Administrador].
            $Datos = $Obj_Tabla->ObtenerTotalDatos("paquete_turistico");
            $Tabla = "";

            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_PaqueteTuristico']."</td>";
                $Tabla.=   "<td>".$Fila['Nombre_Paquete']."</td>";
                $Tabla.=   "<td>".$Fila['Actividades']."</td>";
            }

            echo $Tabla;
            break;

        case 'ELIMINAR_PAQUETE':
            // > ELIMINAR_USUARIO: Elimina cualquier usuario registrado.
            // > Es llamado por EliminarUsuario.html en [Vista].
            $ID_DatoEliminar = $_POST['PAQUETE_ELIMINAR'];
    
            echo ($Obj_Tabla->EliminarDato("paquete_turistico", "ID_PaqueteTuristico ", $ID_DatoEliminar));
        
            break;
        
        case 'INSERTAR_COMENTARIO':
            // > INSERTAR_COMENTARIO: Ingresa el comentario de algún usuario.
            // > Es llamado por RegistrarComentario.html [Parte de la sección USUARIO].
            $Datos['Comentario'] = $_POST['COMENTARIO'];
            $Datos['Fecha_Comentario'] = date("Y-m-d");
            $Datos['ID_Usuario'] = $_POST['ID_USUARIO'];
            echo ($Obj_Tabla->InsertarDatosTabla("comentarios", $Datos));
            break;

        case 'CONSULTAR_COMENTARIOS':
            // > CONSULTAR_COMENTARIOS: Recibe los parámetros del formulario y los ingresa en la Base de Datos.
            // > Es llamado por ComentariosRegistrados.html [Vista -> Administrador].
            $Datos = $Obj_Tabla->ObtenerJoin("usuario", "comentarios", "ID_Usuario", "ID_Usuario");
            $Tabla = "";
            
            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_Comentario']."</td>";
                $Tabla.=   "<td>".$Fila['Nombre_Usuario']." ".$Fila['Apellido_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Comentario']."</td>";
                $Tabla.=   "<td>".$Fila['Fecha_Comentario']."</td>";
            }
    
            echo $Tabla;
            break;

        case 'CONSULTAR_COMENTARIOS_USUARIO':
            // > CONSULTAR_COMENTARIOS_USUARIO: Recibe los parámetros del formulario y los ingresa en la Base de Datos.
            // > Es llamado por ComentariosRegistrados_Usuario.html [Vista -> Administrador].
            $ID_Usuario_Conectado = $_POST['ID_USUARIO_CONECTADO'];

            $Datos = $Obj_Tabla->ObtenerWhere("comentarios", "ID_Usuario", $ID_Usuario_Conectado);
            $Tabla = "";
            
            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_Comentario']."</td>";
                $Tabla.=   "<td>".$Fila['Comentario']."</td>";
                $Tabla.=   "<td>".$Fila['Fecha_Comentario']."</td>";
            }

            echo $Tabla;
            break;

        case 'INSERTAR_VIAJE':
            // > INSERTAR_VIAJE: Guarda los datos de viaje de un usuario determinado.
            // > Es llamado por RegistroViaje.html en [Vista -> Usuario].

            $Datos['ID_Usuario'] = $_POST['ID_USUARIO'];
            $Datos['FechaInicio_Viaje'] = $_POST['FECHA_INICIO'];
            $Datos['FechaFin_Viaje'] = $_POST['FECHA_FIN'];
            $Datos['ID_OrigenViaje'] = $_POST['CIUDAD_ORIGEN'];
            $Datos['ID_DestinoViaje'] = $_POST['CIUDAD_DESTINO'];
            $Datos['ID_PaqueteTuristico'] = $_POST['ID_PAQUETE'];

            if($Datos['ID_DestinoViaje'] >= 1 && $Datos['ID_DestinoViaje'] <=10){
                $Datos['Precio_Viaje'] = rand(650, 1200);
            } else {
                $Datos['Precio_Viaje'] = rand(200, 450);
            }

            echo ($Obj_Tabla->InsertarDatosTabla("viaje", $Datos));

            break;

        case 'CONSULTAR_VIAJE_USUARIO':
            // > CONSULTAR_VIAJE_USUARIO: Muestra los viajes realizados por el usuario que inició sesión.
            // > Es llamado por ConsultarViajes_Usuario.html en [Vista -> Usuario].

            $ID_Usuario_Conectado = $_POST['ID_USUARIO_CONECTADO'];

            $Datos = $Obj_Tabla->ObtenerViajes_Usuario("viaje", "origen_viaje", "destino_viaje", "usuario", "paquete_turistico", 
            "ID_Viaje", "ID_OrigenViaje", "ID_DestinoViaje", "ID_Usuario", "ID_PaqueteTuristico", $ID_Usuario_Conectado);
            $Tabla = "";
            
            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_Viaje']."</td>";
                $Tabla.=   "<td>".$Fila['Ciudad_Origen']."</td>";
                $Tabla.=   "<td>".$Fila['Ciudad_Destino']."</td>";
                $Tabla.=   "<td>".$Fila['FechaInicio_Viaje']."</td>";
                $Tabla.=   "<td>".$Fila['FechaFin_Viaje']."</td>";
                $Tabla.=   "<td>".$Fila['Nombre_Paquete']."</td>";
            }

            echo $Tabla;

            break;
        
        case 'CONSULTAR_VIAJE_ADMINISTRADOR':
            // > CONSULTAR_VIAJE_USUARIO: Muestra los viajes realizados por el usuario que inició sesión.
            // > Es llamado por ConsultarViajes_Administrador.html en [Vista -> Administrador].
    
            $Datos = $Obj_Tabla->ObtenerViajes_Administrador("viaje", "origen_viaje", "destino_viaje", "usuario", "paquete_turistico", 
            "ID_Viaje", "ID_OrigenViaje", "ID_DestinoViaje", "ID_Usuario", "ID_PaqueteTuristico");
            $Tabla = "";

            foreach($Datos as $Fila){
                $Tabla.= "<tr>
                            <td>".$Fila['ID_Viaje']."</td>";
                $Tabla.=   "<td>".$Fila['Nombre_Usuario']." ".$Fila['Apellido_Usuario']."</td>";
                $Tabla.=   "<td>".$Fila['Ciudad_Origen']."</td>";
                $Tabla.=   "<td>".$Fila['Ciudad_Destino']."</td>";
                $Tabla.=   "<td>".$Fila['FechaInicio_Viaje']."</td>";
                $Tabla.=   "<td>".$Fila['FechaFin_Viaje']."</td>";
                $Tabla.=   "<td>".$Fila['Nombre_Paquete']."</td>";
            }
    
            echo $Tabla;
    
            break;
    }
?>