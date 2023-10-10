<?php

include("../config/data_base.php");
include("../models/user.class.php");


switch($_POST['option']){ 
    
    case "list":
        $user = new User();
        header("content-type:application/json");
        if($user->getError() != ""){
            echo json_encode(array("estado"=>"Error","datos" => $user->getError()));
        }else{
            $list = $user->getUser();
            if($user->getError() != ""){
                echo json_encode(array("estado"=> "Error", "datos" => $user->getUser()));
            }else{
                echo json_encode(array("estado"=> "Exito", "datos" => $list));        
            }   
        }
        break;
    
    case "enter":
          
        $user = new User();
        $user->setMarca($_POST['marca']);
        $user->setModelo($_POST['modelo']);
        $user->setColor($_POST['color']);
        $user->setPrecio($_POST['precio']);
 
        $user->createVehiculo();
        break;
    
    case "edit":
        $arrName = explode(".", $_FILES["avatar2"]["name"]);
        $indice = count($arrName) - 1;
        $imageName = date("YmdHis") . "." . $arrName[$indice];
        move_uploaded_file($_FILES["avatar2"]["tmp_name"], "../public/images/" . $imageName);//no hay imagen jaja

        $user = new User();
        $user-> setId($_POST['id']);
        $user->setName($_POST['nombre']);
        $user->setmodelo($_POST['correo']);
        $user->setColor($_POST['clave']);
        $user->setPrecio($imageName);

        $user->editUser();

        header("Location:../views/index.html");

        break;
        
        case "delete":
            $user = new User();
            $user-> setId($_POST['id']);
    
            $user-> removeUser();
            echo "Ok";
            
            break;

        
        case "get_by_id":
            $user = new User();
            $user-> setId($_POST['id']);
            header("Content-type:application/json");
    
            if($user->getError() != ""){
                echo json_encode(array("estado"=>"Error","datos" => $user->getError()));
            }else{
                $list = $user->createVehiculo();
                if($user->getError() != ""){
                    echo json_encode(array("estado"=> "Error", "datos" => $user->createVehiculo()));
                }else{
                    echo json_encode(array("estado"=> "Exito", "datos" => $list));        
                }
            }

            break;
        
        case "manage":
            
            $user = new User();
            $user->setMarca($_POST['marca']);
            $user->setModelo($_POST['modelo']);
            $user->setColor($_POST['color']);
            $user->setPrecio($_POST['precio']);
     
            $user->createVehiculo();
    
            //

            if ($_POST["id"] == "") {
                $user->createVehiculo();
                
            } else {
                $user-> setId($_POST['id']);
                $user->editUser();
            }

             header("Location:../views/index.html");
            
            break;

}


$file = fopen("vehiculos.csv", "a");
fwrite($file, $_POST['marca'] . "," . $_POST['modelo'] . "," . $_POST['color'] . "," . $_POST['precio'] . PHP_EOL);
fclose($file);

header("Location:../views/index.html");
exit;

$arrName = explode(".", $_FILES["avatar2"]["name"]);
$indice = count($arrName) - 1;
$imageName = date("YmdHis") . "." . $arrName[$indice];

move_uploaded_file($_FILES["avatar2"]["tmp_name"], "images/" . $imageName); //solo era para no confundirme con el codigo de clase

$file = fopen("datos.csv", "a");
fwrite($file, $_POST['nombre'] . "," . $_POST['correo'] . "," . $_POST['clave'] . "," . $imageName . PHP_EOL);
fclose($file);

header("Location:index.php");
