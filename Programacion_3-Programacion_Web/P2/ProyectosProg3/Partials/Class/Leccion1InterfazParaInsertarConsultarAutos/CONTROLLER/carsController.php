<?php
require_once("../MODEL/cars.php");
$usuobj = new CarsTable;
switch ($_POST['opcion']) {
	case 'consulta':
		$datos = $usuobj->consultarTodo();
		$tabla = "";
		foreach ($datos as $fila) {
			$tabla .= "<tr><td><strong>" . $fila['id'] . "<strong></td>";
			$tabla .= "<td>" . $fila['model'] . "</td>";
			$tabla .= "<td>" . $fila['date_release'] . "</td>";
		}
		echo $tabla;
		break;
	case 'insertar':
		$datos['model'] = $_POST['model'];
		$datos['date_release'] = $_POST['date_release'];
		echo ($usuobj->insertar($datos));
		break;
}
