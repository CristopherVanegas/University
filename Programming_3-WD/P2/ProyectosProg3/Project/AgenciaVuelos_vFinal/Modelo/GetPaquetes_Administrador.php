<?php
    require("Conexion_Administrador.php");

    $ID_PAQUETE_ELEGIDO = $_POST["PAQUETE"];

    $SENTENCIA_SQL_PAQUETE = "SELECT * FROM paquete_turistico ORDER BY ID_PaqueteTuristico ";
    $RESULT_SET_PAQUETE = $mysqli->query($SENTENCIA_SQL_PAQUETE);

    $HTML = "<option value='0'>Seleccione un paquete</option>";

    while($Dato_Paquete = $RESULT_SET_PAQUETE->fetch_assoc()){
        $HTML .= "<option value='".$Dato_Paquete['ID_PaqueteTuristico']."'>".$Dato_Paquete['Nombre_Paquete']."</option>";
    }

    echo $HTML;
?>


