<?php
require_once("../modelo/conexion.php");
// require_once("../")

$conexion = mysqli_connect("localhost", "root", "", "dbprog3");
// $usobj = new usuario;

// Verificar la conexión

if (mysqli_connect_errno()) {
    echo "Error al conectar con la base de datos: " . mysqli_connect_error();
    exit();
}

$username = $_POST['username'];
$password = $_POST['password'];
$mood = $_POST['mood'];
if (isset($_POST['mood'])) {
    $mood = $_POST['mood'];
    // Resto del código para procesar y guardar los datos en la base de datos
} else {
    echo "La clave 'mood' no está definida en el array POST";
}

$sql = "INSERT INTO usuario (usuario, password, estado, fechacreacion) VALUES ('$username', '$password', '$mood', NOW())";

if (mysqli_query($conexion, $sql)) {
    // echo "Datos guardados correctamente";
} else {
    echo "Error al guardar los datos" . mysqli_error($conexion);
}

mysqli_close(($conexion));
