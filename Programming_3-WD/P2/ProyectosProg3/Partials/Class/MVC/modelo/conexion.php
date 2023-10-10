<?php

class Conexion
{
	private $usuario = "root";
	private $pass = "";
	private $dbcon = null;
	private $dns = "mysql:host=localhost:3306;dbname=dbprog3";
	private $error = null;

	private function conectar()
	{
		try {
			$this->dbcon = new PDO($this->dns, $this->usuario, $this->pass);
			$this->dbcon->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			return true;
		} catch (PDOException $e) {
			$this->error = $e->getMessage();
			return false;
		}
	}

	public function consultar($tabla)
	{
		try {
			if (!$this->conectar()) {
				return "No conecta: " . $this->error;
				exit;
			}
			$query = "SELECT * FROM $tabla";
			$result_set = $this->dbcon->prepare($query);
			$result_set->execute();
			$resultados = $result_set->fetchAll();
			return $resultados;
		} catch (Exception $e) {
			return $e->getMessage();
		}
	}
}
