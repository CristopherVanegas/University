use DB1_Project

declare @contador as int
	set @contador = 1;
declare @rand_price as int

while (@contador <= 100)
begin
	-- set @rand_price = floor(rand() * (500-1+1)+1);
	update detalle_productos set precio = ABS(CAST(NEWID() as binary(6)) % 2500) + 1;

	set @contador = @contador + 1;
end

select * from detalle_productos;