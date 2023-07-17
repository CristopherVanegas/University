<?php
require_once("../model/products.php");
$usuobj = new Product;
switch ($_POST['opcion']) {
    case 'consulta':
        $datos = $usuobj->obtenerTodo();
        $tabla = "";
        foreach ($datos as $fila) {
            $tabla .= "<tr><td>" . $fila['codigo'] . "</td>";
            $tabla .= "<td>" . $fila['descripcion'] . "</td>";
            $tabla .= "<td>" . $fila['stock'] . "</td>";
            $tabla .= "<td>" . $fila['estado'] . "</td></tr>";
        }
        echo $tabla;
        break;
    case 'insertar':
        $datos['descripcion'] = $_POST['descripcion'];
        $datos['stock'] = $_POST['stock'];
        $datos['estado'] = $_POST['estado'];
        echo ($usuobj->insertar($datos));
        break;
}
