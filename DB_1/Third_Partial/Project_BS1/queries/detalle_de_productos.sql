use DB1_Project

if object_id('detalle_productos') is not null
	drop table detalle_productos

create table detalle_productos(
	id int identity,
	cod_categoria int,
	precio int,
	descripcion nvarchar(15),

	primary key(id)
);

alter table detalle_productos
	drop column descripcion;
	
alter table detalle_productos
	add descripcion varchar(15);


--  ADDING FK FROM CATEGORIA.id  --------------------------------------------------------

alter table detalle_productos
	add constraint FK_cod_categoria
	foreign key(cod_categoria)
		references categoria(id);


-----------------------------------------------------------------------------------------