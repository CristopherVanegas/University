<?php
    Class Conexion{
        private $Usuario = "root";
        private $Password = "";
        private $DataBaseConnection = null;
        private $DNS = "mysql:host=localhost:3306;dbname=bd_proy_pro3";
        private $ERROR = null;

        // > Función Conectar(), que conecta a la Base de Datos bd_proy:pro3.
        private function Conectar(){
            try{

                $this->DataBaseConnection = new PDO($this->DNS, $this->Usuario, $this->Password);
                $this->DataBaseConnection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                return true;

            } catch (PDOException $Ex){

                $this->ERROR = $Ex->getMessage();
                return false;
            }
        }

        // > Función Consultar() que recibe la tabla de parámetro, y consulta los elementos de dicha tabla.
        public function Consultar($Tabla){
            try{

                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }

                $QUERY = "Select * from $Tabla";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->execute();
                $Resultados = $RESULT_SET->fetchAll();
                return $Resultados;

            } catch (Exception $Ex){
                
                return $Ex->getMessage();
            }
        }

        // > Función Insertar() que guarda datos en la tabla enviada como parámetro.
        public function Insertar($Tabla, $Datos){
            try{

                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }
                
                #Inicio de la sentencia con INSERT [Guarda el nombre de los campos]
                $Sentencia = "Insert into $Tabla (";
                foreach($Datos as $Clave=>$Valor){
                    $Sentencia.= $Clave.= ",";
                }

                #Continuación de sentencia con INSERT [Guarda el nombre de los valores recibidos por parámetro]
                $Sentencia = substr($Sentencia, 0, strlen($Sentencia) -1).") values (";
                foreach($Datos as $Clave=>$Valor){
                    $Sentencia.= ":".$Clave.",";
                }

                $Sentencia = substr($Sentencia, 0, strlen($Sentencia) -1).")";

                #Se arma el objeto y se adjuntan los parámetros. ST ya guarda mi sentencia.
                $ST = $this->DataBaseConnection->prepare($Sentencia);
                foreach($Datos as $Clave=>$Valor){
                    $Clave = ":".$Clave;
                    $ST->bindValue($Clave, $Valor);
                }

                $ST->execute();
                return "Registro guardado.";
                
            } catch (Exception $Ex){
                
                return $Ex->getMessage();
            }
        }

        // > Función ConsultarFiltro() que busca las credenciales en la tabla enviada.
        public function ConsultarFiltro($Tabla, $Filtro){
            try{
                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }
                
                // > De los datos enviados, guarda también su Rol [Usuario o Administrador].

                $QUERY = "SELECT * FROM $Tabla WHERE User_Usuario = :User_Usuario AND Contrasenia_Usuario = :Contrasenia_Usuario";

                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->bindValue(':User_Usuario', $Filtro['User_Usuario']);
                $RESULT_SET->bindValue(':Contrasenia_Usuario', $Filtro['Contrasenia_Usuario']);

                $RESULT_SET->execute();
                $Resultados = $RESULT_SET->fetchAll();
                return $Resultados;

            } catch (Exception $Ex){

                return $Ex->getMessage();
            }
        }
    }

?>