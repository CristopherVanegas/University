
if object_id('libros') is not NULL
	drop table libros;

if object_id('editoriales') is not null
	drop table editoriales;

create table libros(
	codigo int identity,
	titulo varchar(40),
	autor varchar(30) default 'Desconocido',
	codigoeditorial tinyint not null,
	precio decimal(5,2)
);

create table editoriales(
	codigo tinyint identity,
	nombre varchar(20),
	primary key (codigo)
);

go

-- INSERTED DATA -----------------------------------------------------
insert into editoriales values('Planeta');
insert into editoriales values('Emece');
insert into editoriales values('Siglo XXI');

insert into libros values('El aleph','Borges',2,20);
insert into libros values('Martin Fierro','Jose Hernandez',1,30);
insert into libros values('Aprenda PHP','Mario Molina',3,50);
insert into libros values('Java en 10 minutos',default,3,45);
----------------------------------------------------------------------

-- GET DATA --
select * from libros;

select titulo, nombre, autor
	from editoriales as e
	full join libros as l
	on codigoeditorial = e.codigo;

