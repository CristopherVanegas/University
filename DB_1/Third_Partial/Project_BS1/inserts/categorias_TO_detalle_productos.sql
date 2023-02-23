use DB1_Project

declare @max int
declare @min int
select @max = max(id) from categoria;
select @min = min(id) from categoria;

declare @rand int;

declare @contador int;

--  ADDED cod_categoria FROM categoria.id  --------------------------------------------
set @contador = 1;
while (@contador <= 100)
begin
	-- select @rand = FLOOR(RAND()*(@max-@min+1))+@min;
	-- insert into detalle_productos(cod_categoria) values (@rand)
	
	-- UPDATE detalle_productos SET detalle_productos.descripcion = (concat('Product ', @contador))

	insert into detalle_productos(descripcion) values (concat('Product ', @contador))

	set @contador = @contador + 1;
end

---------------------------------------------------------------------------------------

alter table detalle_productos
	drop column descripcion;


alter table detalle_productos
	add descripcion varchar(15);


select * from detalle_productos;
