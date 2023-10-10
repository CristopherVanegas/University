<?php
    if(isset($_POST["opcion"])){
        $file = fopen("usuarios.csv", "a");
        fwrite($file, $_POST["cedula"].",".$_POST["nombre"].",".$_POST["correo"].PHP_EOL);
        fclose($file);
        header("Location:index.php");
    }
?>
