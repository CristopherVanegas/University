<?php
require_once("conexion.php");
Class usuario
{
	public function obtenerTodo()
	{
		$con=new conexion;
		$resultados=$con->consultar("usuario");
		$con=null;
		return $resultados;
	}
	
	public function insertar($datos)
	{
		$con=new conexion;
		$mensaje=$con->insertar("usuario",$datos);
		$con=null;
		return $mensaje;
	}
	
	public function consultarusuario($filtro)
	{
		$con=new conexion;
		$datos=$con->consultarFiltro("usuario",$filtro);
		$con=null;
		return $datos;
	}
}
?>