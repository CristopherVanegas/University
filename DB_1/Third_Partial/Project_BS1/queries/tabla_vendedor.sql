use DB1_Project

if object_id('vendedor') is not null
	drop table vendedor;

declare @contador int;

set @contador = 1;
-- SELLER TABLES - CREATED  ------------------------
create table vendedor(
	id int identity,
	nombre varchar(15),

	primary key (id)
);

select * from vendedor;
--------------------------------------------------------


while (@contador <= 10)
begin
	-- print @contador
	-- set @contador = @contador + 1;

	insert into vendedor(nombre) values (concat('Vendedor ', @contador))
	set @contador = @contador + 1;

 end

select * from vendedor;