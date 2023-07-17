<?php
require_once("conexion.php");
class CarsTable
{
    public function consultarTodo()
    {
        $con = new Conexion;
        $resultados = $con->consultar("cars");
        $con = null;
        return $resultados;
    }

    public function insertar($datos)
    {
        $con = new conexion;
        $mensaje = $con->insertar("cars", $datos);
        $con = null;
        return $mensaje;
    }
}
