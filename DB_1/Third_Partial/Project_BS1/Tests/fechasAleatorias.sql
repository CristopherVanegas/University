if object_id('fechas_aleatorias') is not null
	drop table fechas_aleatorias;

-- Crear una tabla para almacenar las fechas aleatorias
CREATE TABLE fechas_aleatorias (
    fecha DATE
);

-- Insertar 100 fechas aleatorias entre el 1 de enero de 2004 y el 31 de diciembre de 2023
DECLARE @start_date DATE = '2004-01-01';
DECLARE @end_date DATE = '2024-12-31';
DECLARE @counter INT = 1;

WHILE @counter <= 100
BEGIN
    INSERT INTO fechas_aleatorias (fecha)
    VALUES (DATEFROMPARTS(FLOOR(RAND() * (YEAR(@end_date) - YEAR(@start_date)) + YEAR(@start_date)),
                          FLOOR(RAND() * 12) + 1,
                          FLOOR(RAND() * 27) + 1));
    SET @counter = @counter + 1;
END

select * from fechas_aleatorias;
select min(fecha) from fechas_aleatorias;
select max(fecha) from fechas_aleatorias;