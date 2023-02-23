use desarrollo;
create table usuarios(
	nombre varchar(30),
	clave varchar(10));
exec sp_tables @table_owner='dbo';  
