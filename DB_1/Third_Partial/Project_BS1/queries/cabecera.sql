use DB1_Project

if object_id('cabecera') is not null
	drop table cabecera;

create table cabecera(
	nFactura int identity,
	cod_cliente int,
	cod_vendedor int,
	fecha datetime
);

alter table cabecera
	add primary key (nFactura);


--  ADDING FKs FROM CLENTE.id AND VENDEDOR.id  ----------------------------------

alter table cabecera
	add constraint FK_cod_clientes
	foreign key(cod_cliente)
	references cliente(id);

alter table cabecera
	add constraint FK_cod_vendedor
	foreign key(cod_vendedor)
	references vendedor(id);

---------------------------------------------------------------------------------
--  INSERTING FKs FROM CLENTE.id AND VENDEDOR.id  -------------------------------

---------------------------------------------------------------------------------

select * from cabecera;