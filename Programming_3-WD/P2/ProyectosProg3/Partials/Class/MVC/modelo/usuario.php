<?php
require_once("conexion.php");
class Usuario
{
	public function obtenerTodo()
	{
		$con = new Conexion;
		$resultados = $con->consultar("usuario");
		// $conexion=null;
		return $resultados;
	}
}
