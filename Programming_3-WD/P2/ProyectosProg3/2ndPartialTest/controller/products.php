<?php
require_once("conn.php");
class Product
{
    public function obtenerTodo()
    {
        $con = new conexion;
        $resultados = $con->consultar("productos");
        $con = null;
        return $resultados;
    }

    public function insertar($datos)
    {
        $con = new conexion;
        $mensaje = $con->insertar("productos", $datos);
        $con = null;
        return $mensaje;
    }
}
