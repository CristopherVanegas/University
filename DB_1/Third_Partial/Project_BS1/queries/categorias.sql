use DB1_Project

if object_id('categoria') is not null
	drop table categoria;

declare @contador int;

set @contador = 1;
-- CATEGORY TABLES - CREATED  ------------------------
create table categoria(
	id int identity,
	categoria varchar(15),

	primary key (id)
);

select * from categoria;
--------------------------------------------------------


while (@contador <= 5)
begin
	-- print @contador
	-- set @contador = @contador + 1;

	insert into categoria(categoria) values (concat('Categoria ', @contador))
	set @contador = @contador + 1;

 end

select * from categoria;