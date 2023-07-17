<?php
require_once("../modelo/usuario.php");
$usuobj = new Usuario;

switch ($_POST['opcion']) {
	case 'consulta':
		$datos = $usuobj->obtenerTodo();
		$tabla = "";
		foreach ($datos as $fila) {
			$tabla .= "<tr><td>" . $fila['codigo'] . "</td>";
			$tabla .= "<td>" . $fila['usuario'] . "</td>";
			$tabla .= "<td>" . $fila['password'] . "</td>";
			$tabla .= "<td>" . $fila['estado'] . "</td>";
			$tabla .= "<td>" . $fila['fechacreacion'] . "</td></tr>";
		}
		echo $tabla;
		break;

	default:
		// code...
		break;
}
