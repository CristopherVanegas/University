use DB1_Project

if object_id('detalle_venta') is not null
	drop table detalle_venta;

create table detalle_venta(
	cod_product int,
	precio float,
	cantidad int,
	nFactura int identity,
	primary key (nFactura)
);


--  ADDED FKs FROM DETALLE_PRODUCTOS.id AND CABECERA.nFactura  ----------------------------------
alter table detalle_venta
	add constraint FK_cod_product
	foreign key (cod_product)
		references detalle_productos(id);

-------------------------------------------------------------------------------------------------

select * from detalle_venta;