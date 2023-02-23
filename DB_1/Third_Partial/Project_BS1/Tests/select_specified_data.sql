use DB1_Project

select id from categoria
	where id = 5;

/*
declare @contador int
	set @contador = select id from categoria where id = 5;

print @contador;

declare @contador int
select @contador = id from categoria where id = 2;
print @contador;
*/


--  GET RANDOM ID FROM CATEGORIAS  -----------------------------

declare @rand int,
		@min int,
		@max int;

select @max = max(id) from categoria;
select @min = min(id) from categoria;

print @max;
print @min;

select @rand = FLOOR(RAND()*(@max-@min+1))+@min;
print @rand;


----------------------------------------------------------------
