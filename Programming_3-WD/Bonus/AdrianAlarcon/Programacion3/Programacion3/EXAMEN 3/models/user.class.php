<?php

class User{

    private $id;
    private $marca;
    private $modelo;
    private $color;
    private $precio;
    private $connection;
    private $error ="";

    public function __construct()
    {
        global $server, $user, $password, $name_data_base;
        try{
            $this -> connection = new mysqli($server, $user, $password, $name_data_base);
            if( $this-> connection -> connect_errno){
                
                $this->error = $this->connection->connect_error;
             }
        }
        catch(Exception $e){
            $this->error = $e->getMessage();
            exit;
        }   
    }

    public function setId($id){
        $this->id = $id;
    }
    public function setMarca($marca){ 
        $this->marca = $marca;
    }
    public function setModelo($modelo){
        $this->modelo = $modelo;
    }
    public function setColor($color){ 
        $this->color = $color;
    }
    public function setPrecio($precio){
        $this->precio = $precio;
    }
    public function getError(){
        return $this->error;
    }


    public function createVehiculo()
    {
        $results = $this->connection->query("INSERT INTO vehiculos (marca, modelo, color, precio) 
        VALUES ('{$this->marca}','{$this->modelo}','{$this->color}','{$this->precio}')");
        if ($results){
            return true;
        } else{
            echo $this->connection->connect_error; 
            exit;
            return false;
        }
    }
    
    public function editUser()
    {
        $results = $this->connection->query
        (   
            "UPDATE vehiculos 
            SET marca = '{$this->marca}', modelo='{$this->modelo}', color=('{$this->color}'), precio='{$this->precio}'
            WHERE id = '{$this->id}' "
        );
        if ($results){
            return true;
        } else{
            return false;
        } 
    }
    
    public function removeUser()
    {
        $results = $this->connection->query("DELETE FROM vehiculos WHERE id = '{$this->id}' ");
        if ($results){
            return true;
        } else{
            return false;
        }
    }
    
    public function getVehiculo()
    {
        $results = $this ->connection-> query("SELECT * FROM vehiculos");
        if(!$results){
            $this->error = "Error en la consulta de obtener usuarios";
            return false;
        }else{
            $array = array();
            while($data = $results->fetch_assoc()){
                $array[] = $data;
            }
            return $array;
        }


    }
}

