use DB1_Project

declare @contador as int
	set @contador = 1;

while (@contador <= 100)
begin
	update detalle_productos set precio = floor(rand() * (500-1+1)+1)

	set @contador = @contador + 1;
end