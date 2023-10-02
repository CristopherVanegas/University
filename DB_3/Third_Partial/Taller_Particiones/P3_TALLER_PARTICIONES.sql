-- Est. Cristopher Vanegas --

-- Eliminar tablas --
DROP TABLE empleados;
DROP TABLE empleados_hash;
DROP TABLE empleados_rango;

-- [ Particionamiento por Lista ] --
CREATE TABLE empleados (
 empleado_id NUMBER,
 nombre VARCHAR2(100),
 salario NUMBER,
 fecha_contrato DATE
) PARTITION BY LIST (nombre)
(
 PARTITION particion_a VALUES ('A%'),
 PARTITION particion_b VALUES (DEFAULT)
);

-- Insertar registros --
-- Insertar en particion_a
INSERT INTO empleados VALUES (6, 'Ana María', 53000, TO_DATE('2022-06-12', 'YYYY-MM-DD'));
INSERT INTO empleados VALUES (7, 'Adrián', 58000, TO_DATE('2022-07-30', 'YYYY-MM-DD'));
INSERT INTO empleados VALUES (8, 'Andrés', 52000, TO_DATE('2021-08-18', 'YYYY-MM-DD'));

-- Insertar en particion_b
INSERT INTO empleados VALUES (9, 'Brenda', 49000, TO_DATE('2023-01-15', 'YYYY-MM-DD'));
INSERT INTO empleados VALUES (10, 'Carlos', 55000, TO_DATE('2022-12-05', 'YYYY-MM-DD'));



-- [ Particionamiento por Hash ] --
CREATE TABLE empleados_hash (
 empleado_id NUMBER,
 nombre VARCHAR2(100),
 salario NUMBER,
 fecha_contrato DATE
) PARTITION BY HASH (empleado_id) PARTITIONS 4;

-- Insertar registros --
-- Insertar registros en empleados_hash
INSERT INTO empleados_hash VALUES (6, 'Diana', 51000, TO_DATE('2021-05-22', 'YYYY-MM-DD'));
INSERT INTO empleados_hash VALUES (7, 'Eduardo', 56000, TO_DATE('2023-03-10', 'YYYY-MM-DD'));
INSERT INTO empleados_hash VALUES (8, 'Fernanda', 49000, TO_DATE('2022-09-18', 'YYYY-MM-DD'));
-- ... (continuar con más inserciones)

-- Verificar la distribución de registros en particiones hash
SELECT partition_name, COUNT(*) FROM user_tab_partitions WHERE table_name = 'EMPLEADOS_HASH' GROUP BY partition_name;


-- [ Particionamiento por Rango ] --
CREATE TABLE empleados_rango (
 empleado_id NUMBER,
 nombre VARCHAR2(100),
 salario NUMBER,
 fecha_contrato DATE
) PARTITION BY RANGE (fecha_contrato)
(
 PARTITION particion_anterior VALUES LESS THAN (TO_DATE('2023-01-01', 'YYYY-MM-DD')),
 PARTITION particion_posterior VALUES LESS THAN (MAXVALUE)
);

-- Insertar registros --
-- Insertar registros en particion_anterior
INSERT INTO empleados_rango VALUES (5, 'Gabriel', 52000, TO_DATE('2022-11-03', 'YYYY-MM-DD'));
INSERT INTO empleados_rango VALUES (6, 'Hugo', 47000, TO_DATE('2021-12-20', 'YYYY-MM-DD'));
-- ... (continuar con más inserciones)

-- Insertar registros en particion_posterior
INSERT INTO empleados_rango VALUES (7, 'Irene', 54000, TO_DATE('2023-06-08', 'YYYY-MM-DD'));
INSERT INTO empleados_rango VALUES (8, 'Javier', 59000, TO_DATE('2023-07-25', 'YYYY-MM-DD'));





-- Mostrar Registros --
-- Mostrar registros en particion_a
SELECT * FROM empleados PARTITION (particion_a);

-- Mostrar registros en particion_b
SELECT * FROM empleados PARTITION (particion_b);

-- Mostrar registros en particiones_hash
SELECT * FROM empleados_hash PARTITION (partition_name);

-- Mostrar registros en particion_anterior
SELECT * FROM empleados_rango PARTITION (particion_anterior);

-- Mostrar registros en particion_posterior
SELECT * FROM empleados_rango PARTITION (particion_posterior);

