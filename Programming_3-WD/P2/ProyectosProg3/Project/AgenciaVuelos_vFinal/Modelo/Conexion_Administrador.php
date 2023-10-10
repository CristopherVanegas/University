<?php
    $mysqli = new mysqli("localhost", "root", "", "bd_proy_pro3");

    if(mysqli_connect_errno()){
        echo 'Conexión fallida: ', mysqli_connect_errno();
        exit();
    }
?>