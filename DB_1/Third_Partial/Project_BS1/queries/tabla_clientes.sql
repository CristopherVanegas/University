use DB1_Project

if object_id('cliente') is not null
	drop table cliente;

declare @contador int;

set @contador = 1;
-- CLIENT TABLES - CREATED  ------------------------
create table cliente(
	id int identity,
	nombre varchar(15),

	primary key (id)
);

select * from cliente;
--------------------------------------------------------


while (@contador <= 500)
begin
	-- print @contador
	-- set @contador = @contador + 1;

	insert into cliente(nombre) values (concat('Cliente ', @contador))
	set @contador = @contador + 1;

 end

select * from cliente;
-----------------------------------------------------------------------