use exercise_2

if object_id('hombres') is not null
	drop table hombres;


if object_id('mujeres') is not null
	drop table mujeres;

create table hombres(
	nombre varchar(15),
	domicilio varchar(50),
	edad int
);

create table mujeres(
	nombre varchar(15),
	domicilio varchar(50),
	edad int
);


-- INSERTS -----

insert into hombres(nombre, domicilio, edad) values ('Juan Torres', 'Sarmiento 755', 44)
insert into hombres(nombre, domicilio, edad) values ('Alex', 'Sarmiento 755', 56)
insert into hombres(nombre, domicilio, edad) values ('Pablo', 'Sarmiento 755', 38)
insert into hombres(nombre, domicilio, edad) values ('Pablo', 'Sarmiento 755', 50)


insert into mujeres(nombre, domicilio, edad) values ('Maria', 'Sarmiento 755', 45)
insert into mujeres(nombre, domicilio, edad) values ('LiLiana', 'Sarmiento 755', 35)
insert into mujeres(nombre, domicilio, edad) values ('Susana', 'Sarmiento 755', 41)
insert into mujeres(nombre, domicilio, edad) values ('Paula', 'Sarmiento 755', 65)

select * from mujeres cross join hombres where abs(mujeres.edad - hombres.edad) <= 10;
select * from mujeres cross join hombres where abs(mujeres.edad - hombres.edad) <= 5;

select mujeres.edad - hombres.edad as diferencia;
--select * from hombres;