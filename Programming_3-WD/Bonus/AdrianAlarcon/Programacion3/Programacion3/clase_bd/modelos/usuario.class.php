<?php


class Usuario{
	private $id;
	private $nombre = "Antonio";
	private $cedula;
	private $correoElectronico;
	private $estado;
	private $imagen;
	private $conexion;

	public function __construct(){
		//echo "Esto se escribió desde el constructor";
		
		global $servidor, $usuario, $clave, $puerto, $nombre;
		$this->conexion = new mysqli($servidor, $usuario, $clave, $nombre, $puerto);
		if($this->conexion->connect_errno){
			echo $this->conexion->connect_error;
		}/*else{
			echo "Se conectó a la base";
		}*/
	}

	public function colocarId($id){
		$this->id = $id;
	}
	public function colocarNombre($nombre){
		$this->nombre = $nombre;
	}
	public function colocarCedula($cedula){
		$this->cedula = $cedula;
	}
	public function colocarCorreoElectronico($correoElectronico){
		$this->correoElectronico = $correoElectronico;
	}
	public function colocarImagen($imagen){
		$this->imagen = $imagen;
	}

	public function presentarInformacion(){
		echo "El nombre es {$this->nombre}, la cedula es {$this->cedula} y el correo es
		{$this->correoElectronico}";
	}


	public function crear(){
		$consulta = "INSERT INTO usuarios (cedula, nombre, correo, imagen) 
		VALUES ('{$this->cedula}','{$this->nombre}','{$this->correoElectronico}','{$this->imagen}')";
		$resultado = $this->conexion->query($consulta);
	}

	public function consultarRegistros(){
		$consulta = "SELECT * FROM usuarios WHERE estado = 'A'";
		$resultado = $this->conexion->query($consulta);
		$arrego = array();
		while($fila = $resultado->fetch_assoc()){
			$arrego[] = $fila;
		}
		return $arrego;
	}

	public function consultarPorId(){
		$consulta = "SELECT * FROM usuarios WHERE id = '{$this->id}'";
		$resultado = $this->conexion->query($consulta);
		return $resultado->fetch_assoc();	
	}

	public function editar(){
		$consulta = "UPDATE usuarios 
					SET cedula ='{$this->cedula}', nombre ='{$this->nombre}', 
					correo='{$this->correoElectronico}', imagen = '{$this->imagen}'
					WHERE id = '{$this->id}'";
		$resultado = $this->conexion->query($consulta);
	}

	public function eliminar(){
		$consulta = "DELETE FROM usuarios WHERE id = '{$this->id}'";
		$resultado = $this->conexion->query($consulta);
	}

	public function eliminarLogicamente(){
		$consulta = "UPDATE usuarios 
					SET estado = 'I'
					WHERE id = '{$this->id}'";
		$resultado = $this->conexion->query($consulta);
	}


}



?>