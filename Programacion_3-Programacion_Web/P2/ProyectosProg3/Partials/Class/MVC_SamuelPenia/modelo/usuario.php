<?php
require_once("conexion.php");
Class usuario
{
	public function obtenerTodo()
	{
		$con=new conexion;
		$resultados=$con->consultar("usuario");
		// $conexion=null;
		return $resultados;
	}
	public function insertar($datos)
	{
		$con=new conexion;
		$mensaje = $con->insertar("usuario", $datos);
		$conexion=null;
		return $mensaje;
	}
}
