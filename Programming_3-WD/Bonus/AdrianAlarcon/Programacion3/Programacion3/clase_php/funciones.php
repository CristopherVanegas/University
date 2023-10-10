<?php
    function mostrarTablaDeMultiplicar($numero){
        $cadena = "<ul>";
    for($i=1; $i<13; $i++){
        $cadena = $cadena. "<li>$i*$numero =" .($i*$numero). "</li>";
    }
        $cadena .= "</ul>";
        return $cadena;
    }

?>