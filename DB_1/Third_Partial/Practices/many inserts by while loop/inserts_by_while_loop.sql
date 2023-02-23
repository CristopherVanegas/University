use DB1_Project

if object_id('experiments') is not null
	drop table experiment;

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

select * from experiments;