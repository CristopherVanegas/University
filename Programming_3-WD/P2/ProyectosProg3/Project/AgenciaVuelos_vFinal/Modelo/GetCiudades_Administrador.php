<?php
    require("Conexion_Administrador.php");

    $ID_IDENTIFICADOR_ELEGIDO = $_POST["IDENTIFICADOR"];

    if($ID_IDENTIFICADOR_ELEGIDO == "CIUDAD_ORIGEN"){
        $SENTENCIA_SQL_ORIGEN = "SELECT * FROM origen_viaje ORDER BY ID_OrigenViaje";
        $RESULT_SET_ORIGEN = $mysqli->query($SENTENCIA_SQL_ORIGEN);

        $HTML = "<option value='0'>Seleccione una ciudad de origen</option>";

        while($Dato_Origen = $RESULT_SET_ORIGEN->fetch_assoc()){
            $HTML .= "<option value='".$Dato_Origen['ID_OrigenViaje']."'>".$Dato_Origen['Ciudad_Origen']."</option>";
        }

        echo $HTML;

    } else {
        $SENTENCIA_SQL_DESTINO = "SELECT * FROM destino_viaje ORDER BY ID_DestinoViaje";
        $RESULT_SET_DESTINO = $mysqli->query($SENTENCIA_SQL_DESTINO);

        $HTML = "<option value='0'>Seleccione una ciudad de destino</option>";

        while($Dato_Destino = $RESULT_SET_DESTINO->fetch_assoc()){
            $HTML .= "<option value='".$Dato_Destino['ID_DestinoViaje']."'>".$Dato_Destino['Ciudad_Destino']."</option>";
        }

        echo $HTML;
    }
?>