<?php
    require("Conexion_Administrador.php");

    $ID_USUARIO_ELEGIDO = $_POST["USUARIO"];

    $SENTENCIA_SQL_USUARIO = "SELECT * FROM usuario ORDER BY ID_Usuario";
    $RESULT_SET_USUARIO = $mysqli->query($SENTENCIA_SQL_USUARIO);

    $HTML = "<option value='0'>Seleccione un usuario</option>";

    while($Dato_Usuario = $RESULT_SET_USUARIO->fetch_assoc()){
        $HTML .= "<option value='".$Dato_Usuario['ID_Usuario']."'>".$Dato_Usuario['Nombre_Usuario']." ".
        $Dato_Usuario['Apellido_Usuario']."</option>";
    }

    echo $HTML;
?>


