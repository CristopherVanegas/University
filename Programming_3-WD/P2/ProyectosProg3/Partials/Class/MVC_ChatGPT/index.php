<!DOCTYPE html>
<html>

<head>
  <title>Registrar usuario</title>
  <meta charset="utf-8" />
  <link rel="stylesheet" type="text/css" href="estilo.css" />
</head>

<body>
  <?php
  require_once './MODEL/connection.php';
  require_once './CONTROLLER/controlador.php';
  $modelo = new Controlador();
  $datos = $modelo->obtenerDatos();
  $vista = new Vista();
  $vista->mostrarDatos($datos); ?>
</body>

</html>