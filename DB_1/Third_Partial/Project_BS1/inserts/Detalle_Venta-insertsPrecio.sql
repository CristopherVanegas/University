use DB1_Project

declare @contador as int
	set @contador = 1;

while (@contador <= 50000)
begin
	update detalle_venta set precio = (cantidad * (select precio from detalle_productos where cod_product = detalle_productos.id))

	set @contador = @contador + 1;
end

select * from detalle_venta where cod_product = 9;
select * from detalle_productos where id = 9;