use examen_final_DB1

--  CREACION DE TABLA ---------------------------------------------
-- EMPLEADOS
create table EMPLEADOS(
	nombre varchar(15),
	DNI int identity,
	tipo_trabajo varchar(25),

	primary key(nombre)
);

-- ADD THE FOREIGN KEY FOR TIPO_TRABAJO

-- DIRECTORES
create table TIPO_TRABAJO(
	tipo_trabajo varchar(50),

	primary key(tipo_trabajo)
);

-- CREATE DIRECTORES TABLE
create table DIRECTORES(
	titulacion_academica varchar(50),
	especialidad_jardineria varchar(50),

	primary key(especialidad_jardineria)
);
-- CREATE OPERARIOS TABLE
create table OPERARIOS(
	preparacion varchar(10),
	precio_por_hora int,
	primary key (preparacion)
);


-- CREATE CONTRATO TABLE
create table CONTRATO(
	id_contrato int identity,
	fecha datetime,
	nombre varchar(15),
	descripcion varchar(50),
	cliente varchar(15),
	precio money,

	primary key (id_contrato)
);

-------------------------------------------------------------------

--  FOREIGN KEYS --------------------------------------------------
alter table TIPO_TRABAJO
	ADD CONSTRAINT FK_director
	FOREIGN KEY (tipo_trabajo)
	REFERENCES DIRECTORES(especialidad_jardineria);

alter table TIPO_TRABAJO
	ADD CONSTRAINT FK_operarios
	FOREIGN KEY (preparacion)
	REFERENCES OPERARIOS(preparacion);

alter table EMPLEADOS
	ADD CONSTRAINT FK_tipo_trabajo
	FOREIGN KEY (tipo_trabajo)
	REFERENCES TIPO_TRABAJO(tipo_trabajo);

alter table CONTRATO
	ADD CONSTRAINT FK_nombre
	FOREIGN KEY (nombre)
	REFERENCES EMPLEADOS(nombre);






