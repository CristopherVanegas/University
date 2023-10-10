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

        // > Función Actualizar() que recibe la tabla de parámetro, y el ID del dato que desea actualizarse.
        public function Actualizar($Tabla, $Nombre_Campo, $Nuevo_Dato, $ID_Dato){
            try{
                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }
        
                $QUERY = "UPDATE $Tabla SET $Nombre_Campo = :rol WHERE ID_Usuario = :id";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->bindParam(':rol', $Nuevo_Dato);
                $RESULT_SET->bindParam(':id', $ID_Dato);
        
                $RESULT_SET->execute();
        
                return "Registro actualizado exitosamente.";
        
            } catch (Exception $Ex){
                return $Ex->getMessage();
            }
        }

        // > Función Eliminar() que recibe la tabla de parámetro, y el ID del dato que desea eliminarse.
        public function Eliminar($Tabla, $Nombre_Campo, $ID_Dato){
            try{
                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }
        
                $QUERY = "DELETE FROM $Tabla WHERE $Nombre_Campo = :id";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->bindParam(':id', $ID_Dato);
        
                $RESULT_SET->execute();
        
                return "Registro eliminado exitosamente.";
        
            } catch (Exception $Ex){
                return $Ex->getMessage();
            }
        }

        // > Función Consultar_Join() que recibe tablas, y consulta los elementos de dicha tabla mediante un JOIN.
        public function Consultar_Join($Tabla_Base, $Tabla_Transaccional, $PK, $FK){
            try{

                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }

                $QUERY = "Select * from $Tabla_Transaccional join $Tabla_Base
                on $Tabla_Transaccional.$FK = $Tabla_Base.$PK";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->execute();
                $Resultados = $RESULT_SET->fetchAll();
                return $Resultados;

            } catch (Exception $Ex){
                
                return $Ex->getMessage();
            }
        }

        // > Función Consultar_Where() que recibe tablas, y consulta los elementos de dicha tabla mediante un JOIN.
        public function Consultar_Where($Tabla, $Campo, $Condicion){
            try{

                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }

                $QUERY = "Select * from $Tabla where $Campo = $Condicion";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->execute();
                $Resultados = $RESULT_SET->fetchAll();
                return $Resultados;

            } catch (Exception $Ex){
                
                return $Ex->getMessage();
            }
        }

        // > Función Consultar_Viaje(), un JOIN de la tabla Viaje con CUATRO tablas bases.
        public function Consultar_Viaje($TViaje, $TOrigen, $TDestino, $TUsuario, $TPaquete,
        $PK_Viaje, $FK_Origen, $FK_Destino, $FK_Usuario, $FK_Paquete, $ID_Usuario_Conectado){
            try{

                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }

                $QUERY = "Select * from $TViaje 
                join $TOrigen on $TViaje.$FK_Origen = $TOrigen.$FK_Origen 
                join $TDestino on $TViaje.$FK_Destino = $TDestino.$FK_Destino
                join $TUsuario on $TViaje.$FK_Usuario = $TUsuario.$FK_Usuario
                join $TPaquete on $TViaje.$FK_Paquete = $TPaquete.$FK_Paquete
                where $TUsuario.ID_Usuario = $ID_Usuario_Conectado";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->execute();
                $Resultados = $RESULT_SET->fetchAll();
                return $Resultados;

            } catch (Exception $Ex){
                
                return $Ex->getMessage();
            }
        }

        // > Función Consultar_Viaje_Administrador(), un JOIN de la tabla Viaje con CUATRO tablas bases.
        public function Consultar_Viaje_Administrador($TViaje, $TOrigen, $TDestino, $TUsuario, $TPaquete,
        $PK_Viaje, $FK_Origen, $FK_Destino, $FK_Usuario, $FK_Paquete){
            try{

                if(!$this->Conectar()){
                    return "No se ha podido conectar: ".$this->ERROR;
                    exit;
                }

                $QUERY = "Select * from $TViaje 
                join $TOrigen on $TViaje.$FK_Origen = $TOrigen.$FK_Origen 
                join $TDestino on $TViaje.$FK_Destino = $TDestino.$FK_Destino
                join $TUsuario on $TViaje.$FK_Usuario = $TUsuario.$FK_Usuario
                join $TPaquete on $TViaje.$FK_Paquete = $TPaquete.$FK_Paquete";
                $RESULT_SET = $this->DataBaseConnection->prepare($QUERY);
                $RESULT_SET->execute();
                $Resultados = $RESULT_SET->fetchAll();
                return $Resultados;

            } catch (Exception $Ex){
                
                return $Ex->getMessage();
            }
        }

    }

?>