<?php
include_once("../configuraciones/base_datos.php");
include_once("../modelos/usuario.class.php");

switch ($_POST['opcion']) {
	case 'crear':
		# code...
		//var_dump($_FILES)
		move_uploaded_file($_FILES['imagen']['tmp_name'], "../public/images/".$_FILES['imagen']['name']);

		$objUsuario = new Usuario();
		$objUsuario->colocarCedula($_POST['cedula']);
		$objUsuario->colocarNombre($_POST['nombre']);
		$objUsuario->colocarCorreoElectronico($_POST['correo']);
		$objUsuario->colocarImagen("../public/images/".$_FILES['imagen']['name']);
		$objUsuario->crear();
		header("Location:../vistas/index.html");
		break;
	case 'editar':
		# code...
		move_uploaded_file($_FILES['imagen']['tmp_name'], "../public/images/".$_FILES['imagen']['name']);

		$objUsuario = new Usuario();
		$objUsuario->colocarId($_POST['id']);
		$objUsuario->colocarCedula($_POST['cedula']);
		$objUsuario->colocarNombre($_POST['nombre']);
		$objUsuario->colocarCorreoElectronico($_POST['correo']);
		$objUsuario->colocarImagen("../public/images/".$_FILES['imagen']['name']);
		$objUsuario->editar();
		header("Location:../vistas/index.html");
		break;
	case 'eliminar':
		# code...
		$objUsuario = new Usuario();
		$objUsuario->colocarId($_POST['id']);
		$objUsuario->eliminarLogicamente();
		echo "Ok";
		break;
	case 'consultar':
		# code...
		$objUsuario = new Usuario();
		header("Content-Type:application/json");
		echo json_encode($objUsuario->consultarRegistros());
		break;
	case 'consultarPorId':
		# code...
		$objUsuario = new Usuario();
		$objUsuario->colocarId($_POST['id']);
		header("Content-Type:application/json");
		echo json_encode($objUsuario->consultarPorId());
		break;
	default:
		# code...
		break;
}


?>