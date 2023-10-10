<?php
    require_once("../Modelo/TablasBD.php");
    
    $Obj_Tabla = new TablasBD();

    switch($_POST['Opcion']){

        case 'LOGIN':

            // > LOGIN: Recibe como parámetros el Usuario y Contrasenia ingresados para validarse.
            // > Es llamado por Login.html en [Vista].
            
            $Filtro['User_Usuario'] = $_POST['User_Usuario'];
            $Filtro['Contrasenia_Usuario'] = $_POST['Contrasenia_Usuario'];
            $DATO_USUARIO = $Obj_Tabla->ConsultarUsuario("usuario", $Filtro);
            
            if(empty($DATO_USUARIO)){
                echo "No se ha podido validar las credenciales.";
            } else {
                session_start();
                $_SESSION['User_Usuario'] = $DATO_USUARIO[0]['User_Usuario'];
                $_SESSION['Rol_Usuario'] = $DATO_USUARIO[0]['Rol_Usuario'];

                // > Dependiendo del Rol, direcciona a diferentes páginas.

                if($_SESSION['Rol_Usuario'] == 'USUARIO'){
                    echo "USER";
                } else {
                    echo "ADMIN";
                }
            }
            break;
    }
?>