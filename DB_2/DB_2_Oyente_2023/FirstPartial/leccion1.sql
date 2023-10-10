create database leccion1;

use leccion1;

CREATE TABLE mesa(
	id INT NOT NULL AUTO_INCREMENT,
    mesa VARCHAR(6),
    
    CONSTRAINT pk_mesa PRIMARY KEY(id)
);

CREATE TABLE rol(
	id INT NOT NULL AUTO_INCREMENT,
    rol VARCHAR(10),
    
    CONSTRAINT pk_rol PRIMARY KEY(id)
);

CREATE TABLE persona(
	id INT NOT NULL AUTO_INCREMENT,
    nombre varchar(15),
    apellido varchar(15),
    id_rol INT NOT NULL,
    
	CONSTRAINT pk_persona PRIMARY KEY(id),
	CONSTRAINT fk_id_rol FOREIGN KEY (id_rol) REFERENCES rol(id)
);

CREATE TABLE producto(
	id INT NOT NULL AUTO_INCREMENT,
    producto VARCHAR(25),
    
	CONSTRAINT pk_productos PRIMARY KEY(id)
);

CREATE TABLE mesaMesero(
	id INT NOT NULL AUTO_INCREMENT,
    id_mesa INT NOT NULL,
	id_persona INT NOT NULL,
	id_orden INT,
    
    CONSTRAINT pk_mesaMesero PRIMARY KEY(id),
	CONSTRAINT fk_id_mesa FOREIGN KEY (id_mesa) REFERENCES mesa(id),
	CONSTRAINT fk_id_persona FOREIGN KEY (id_persona) REFERENCES persona(id)
	-- CONSTRAINT fk_id_orden FOREIGN KEY (id_orden) REFERENCES orden(id)
);

CREATE TABLE encabezado(
	id INT NOT NULL AUTO_INCREMENT,
    id_persona INT NOT NULL,
    id_mesaMesero INT NOT NULL,

	CONSTRAINT pk_detalle_factura PRIMARY KEY(id),
    CONSTRAINT fk_id_persona_encabezado FOREIGN KEY (id_persona) REFERENCES persona(id),
	CONSTRAINT fk_id_mesaMesero FOREIGN KEY (id_mesaMesero) REFERENCES mesaMesero(id)
);

CREATE TABLE detalleFactura(
	id INT NOT NULL AUTO_INCREMENT,
    id_encabezado INT NOT NULL,
    id_producto INT NOT NULL,
    
	CONSTRAINT pk_detalle_factura PRIMARY KEY(id),
	CONSTRAINT fk_id_encabezado FOREIGN KEY (id_encabezado) REFERENCES encabezado(id),
	CONSTRAINT fk_id_producto FOREIGN KEY (id_producto) REFERENCES producto(id)
);

SHOW TABLES;





