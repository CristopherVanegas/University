use DB1_Project

declare @count int

declare @max int
declare @min int
select @max = max(id) from detalle_productos;
select @min = min(id) from detalle_productos;

declare @rand int

--  ADDED COD_PRODUCT FROM detalle_productos.id  ------------------------------------------------
set @count = 1;

while (@count <= 50000)
begin
	select @rand = FLOOR(RAND()*(@max-@min+1))+@min;
	insert into detalle_venta(cod_product) values (@rand)
	set @count = @count + 1;
end

-------------------------------------------------------------------------------------------------



-- select max(cod_product) from detalle_venta; 

select * from detalle_venta;
