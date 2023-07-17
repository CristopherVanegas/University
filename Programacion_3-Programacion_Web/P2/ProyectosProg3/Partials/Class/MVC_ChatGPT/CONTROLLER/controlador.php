<?php
require_once '../MODEL/connection.php';

class Controlador
{
    private $modelo;

    public function __construct()
    {
        $this->modelo = new Conexion();
    }

    public function obtenerDatos()
    {
        $conn = $this->modelo->getConnection();

        $stmt = $conn->prepare("SELECT id, name, surname FROM tu_tabla");
        $stmt->execute();
        $resultados = $stmt->fetchAll(PDO::FETCH_ASSOC);

        return $resultados;
    }
}
