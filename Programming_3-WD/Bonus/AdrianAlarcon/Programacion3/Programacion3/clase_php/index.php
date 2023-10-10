<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP</title>
</head>
<body>
    <hr>
    <h1>Hola Mundo</h1>
    <?php

    include("funciones.php");

    echo "Esto se genero desde PHP";
    $numero1 = 12;
    $numero2 = 23;
    echo "<br>La suma de ". $numero1. "con el ".$numero2. "es ".($numero1 + $numero2);
    echo "<br>La resta de $numero1 con el $numero2 es ".($numero1 - $numero2);
    echo "<br>La multiplicacion de ". $numero1. "con el ".$numero2. "es ".($numero1 * $numero2);
    echo "<br>La division de $numero1 con el $numero2 es ".($numero1 / $numero2);
    if($numero1>$numero2){
        echo"<br>El $numero1 es mayor al $numero2";
    }else if ($numero1==$numero2){
        echo "<br>El $numero1 es igual al $numero2";
    }else{
        echo"<br>El $numero1 es menor al $numero2";
    }

    echo mostrarTablaDeMultiplicar(40);
    
    ?>
</body>
</html>