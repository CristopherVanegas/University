<?php
    require_once("Conexion.php");

    Class TablasBD{
        public function ObtenerTotalDatos($Tabla){
            $Obj_Conexion = new Conexion();
            $Resultados = $Obj_Conexion->Consultar($Tabla);
            $Conexion = null;
            return $Resultados;
        }

        // > InsertarDatosTabla() recibe la tabla y los datos a guardarse, y llama a Conexion para guardar. 
        public function InsertarDatosTabla($Tabla, $Datos){
            $Obj_Conexion = new Conexion();
            $Mensaje = $Obj_Conexion->Insertar($Tabla, $Datos);
            $Obj_Conexion = null;
            return $Mensaje;
        }

        // > ConsultarUsuario() busca que exista el USUARIO y CONTRASENIA enviados como parámetros.
        public function ConsultarUsuario($Tabla, $Filtro){
            $Obj_Conexion = new Conexion();
            $Mensaje = $Obj_Conexion->ConsultarFiltro($Tabla, $Filtro);
            $Obj_Conexion = null;
            return $Mensaje;
        }
    }
?>