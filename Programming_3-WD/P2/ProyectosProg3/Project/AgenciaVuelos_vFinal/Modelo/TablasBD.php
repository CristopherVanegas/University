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

        // > EliminarDato() recibe la tabla y el ID del registro que se desea eliminar.
        public function EliminarDato($Tabla, $Nombre_Campo, $ID_Dato){
            $Obj_Conexion = new Conexion();
            $Mensaje = $Obj_Conexion->Eliminar($Tabla, $Nombre_Campo, $ID_Dato);
            $Obj_Conexion = null;
            return $Mensaje;
        }

        // > ActualizarDato() recibe la tabla, el ID del registro y qué dato se desea actualizar.
        public function ActualizarDato($Tabla, $Nombre_Campo, $Nuevo_Dato, $ID_Dato){
            $Obj_Conexion = new Conexion();
            $Mensaje = $Obj_Conexion->Actualizar($Tabla, $Nombre_Campo, $Nuevo_Dato, $ID_Dato);
            $Obj_Conexion = null;
            return $Mensaje;
        }

        // > ObtenerJoin() permite una consulta donde se usen datos de dos tablas relacionadas.
        public function ObtenerJoin($Tabla_Base, $Tabla_Transaccional, $PK, $FK){
            $Obj_Conexion = new Conexion();
            $Resultados = $Obj_Conexion->Consultar_Join($Tabla_Base, $Tabla_Transaccional, $PK, $FK);
            $Conexion = null;
            return $Resultados;
        }

        // > ObtenerViajes_Usuario() permite una consulta hacia la tabla transaccional Viajes, junto a tablas bases.
        public function ObtenerViajes_Usuario($TViaje, $TOrigen, $TDestino, $TUsuario, $TPaquete,
        $PK_Viaje, $FK_Origen, $FKDestino, $FKUsuario, $FKPaquete, $ID_Usuario_Conectado){
            $Obj_Conexion = new Conexion();
            $Resultados = $Obj_Conexion->Consultar_Viaje($TViaje, $TOrigen, $TDestino, $TUsuario, $TPaquete,
            $PK_Viaje, $FK_Origen, $FKDestino, $FKUsuario, $FKPaquete, $ID_Usuario_Conectado);
            $Conexion = null;
            return $Resultados;
        }

        // > ObtenerViajes_Administrador() permite una consulta hacia la tabla transaccional Viajes.
        public function ObtenerViajes_Administrador($TViaje, $TOrigen, $TDestino, $TUsuario, $TPaquete,
        $PK_Viaje, $FK_Origen, $FKDestino, $FKUsuario, $FKPaquete){
            $Obj_Conexion = new Conexion();
            $Resultados = $Obj_Conexion->Consultar_Viaje_Administrador($TViaje, $TOrigen, $TDestino, $TUsuario, $TPaquete,
            $PK_Viaje, $FK_Origen, $FKDestino, $FKUsuario, $FKPaquete);
            $Conexion = null;
            return $Resultados;
        }

        // > ObtenerWhere() permite una consulta donde se use la cláusula WHERE.
        public function ObtenerWhere($Tabla, $Campo, $Condicion){
            $Obj_Conexion = new Conexion();
            $Resultados = $Obj_Conexion->Consultar_Where($Tabla, $Campo, $Condicion);
            $Conexion = null;
            return $Resultados;
        }
    }
?>