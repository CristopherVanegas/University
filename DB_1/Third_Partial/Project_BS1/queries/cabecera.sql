use DB1_Project

if object_id('cabecera') is not null
	drop table cabecera;

/*
declare @contador int

set @contador = 1;
-- EXPERIMENT TABLES - CREATED  ------------------------
create table experiments(
	id int identity,
	experiment varchar(30),

	primary key (id)
);

select * from experiments;
--------------------------------------------------------


while (@contador <= 50000)
begin
	-- print @contador
	-- set @contador = @contador + 1;

	insert into experiments(experiment) values (concat('Experimento ', @contador))
	set @contador = @contador + 1;

 end

 */

create table cabecera(
	nFactura int identity,
	cod_cliente int,
	cod_vendedor int,
	fecha datetime
);

alter table cabecera
	add primary key (nFactura);


--  ADDING FKs FROM CLENTE.id AND VENDEDOR.id  --------------------------------------------------------

alter table cabecera
	add constraint FK_cod_clientes
	foreign key(cod_cliente)
	references cliente(id);

alter table cabecera
	add constraint FK_cod_vendedor
	foreign key(cod_vendedor)
	references vendedor(id);

---------------------------------------------------------------------------------


select * from cabecera;