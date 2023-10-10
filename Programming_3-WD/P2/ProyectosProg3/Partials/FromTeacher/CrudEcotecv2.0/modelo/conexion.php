<?php

Class Conexion
{
	private $usuario="root";
	private $pass="";
	private $dbcon=null;
	private $dns="mysql:host=localhost:3306;dbname=dbprog3";
	private $error=null;

	private function conectar()
	{
		try{
			$this->dbcon=new PDO($this->dns,$this->usuario,$this->pass);
			$this->dbcon->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
			return true;
		}catch(PDOException $e)
		{
			$this->error=$e->getMessage();
			return false;
		}
	}

	public function consultar($tabla)
	{
		try{
			if(!$this->conectar())
			{
				return "No conecta: ".$this->error;
				exit;
			}
			$query="Select * from $tabla";
			$result_set=$this->dbcon->prepare($query);
			$result_set->execute();
			$resultados=$result_set->fetchAll();
			return $resultados;

		}catch(Exception $e)
		{
			return $e->getMessage();
		}
	}
	
	public function consultarFiltro($tabla,$filtro)
	{
		try{
			if(!$this->conectar())
			{
				return "No conecta: ".$this->error;
				exit;
			}
			$query="Select * from $tabla where ";
			foreach($filtro as $clave=>$valor)
			{
				$query.= $clave."= :".$clave." and ";
			}
			$query=substr($query,0,strlen($query)-4);
			$result_set=$this->dbcon->prepare($query);
			foreach($filtro as $clave=>$valor)
			{
				$clave=":".$clave;
				$result_set->bindValue($clave,$valor);
			}
			$result_set->execute();
			$resultados=$result_set->fetchAll();
			return $resultados;

		}catch(Exception $e)
		{
			return $e->getMessage();
		}
	}
	
	public function insertar($tabla,$datos)
	{
		try{
			if(!$this->conectar())
			{
				return "No conecta: ".$this->error;
				exit;
			}
			$sentencia="Insert into $tabla (";
			foreach($datos as $clave=>$valor)
			{
				$sentencia.=$clave.",";
			}
			$sentencia=substr($sentencia,0,strlen($sentencia)-1).") values (";
			foreach($datos as $clave=>$valor)
			{
				$sentencia.=":".$clave.",";
			}
			$sentencia=substr($sentencia,0,strlen($sentencia)-1).")";
			$st=$this->dbcon->prepare($sentencia);
			foreach($datos as $clave=>$valor)
			{
				$clave=":".$clave;
				$st->bindValue($clave,$valor);
			}
			$st->execute();
			return "Registro guardado...";

		}catch(Exception $e)
		{
			return $e->getMessage();
		}
	}
}


?>