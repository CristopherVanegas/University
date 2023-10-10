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
    }
?>