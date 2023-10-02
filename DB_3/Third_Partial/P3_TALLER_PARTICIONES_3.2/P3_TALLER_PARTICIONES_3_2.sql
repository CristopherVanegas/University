CREATE TABLE empleados ( empleado_id NUMBER, nombre VARCHAR2(100), salario NUMBER, fecha_contrato DATE )

PARTITION BY LIST (nombre) (
PARTITION particion_a VALUES ('A'), PARTITION particion_b VALUES (DEFAULT)
);
INSERT INTO empleados (empleado_id, nombre, salario, fecha_contrato) VALUES (1, 'Ana', 50000, TO_DATE('2020-01-15', 'YYYY-MM-DD'));
INSERT INTO empleados (empleado_id, nombre, salario, fecha_contrato)VALUES (2, 'Alberto', 55000, TO_DATE('2019-08-20', 'YYYY-MM-DD'));
INSERT INTO empleados (empleado_id, nombre, salario, fecha_contrato)VALUES (3, 'Alicia', 48000, TO_DATE('2021-03-10', 'YYYY-MM-DD'));
INSERT INTO empleados (empleado_id, nombre, salario, fecha_contrato)VALUES (4, 'Brenda', 52000, TO_DATE('2022-05-05', 'YYYY-MM-DD'));
INSERT INTO empleados (empleado_id, nombre, salario, fecha_contrato)VALUES (5, 'Carlos', 60000, TO_DATE('2018-11-30', 'YYYY-MM-DD'));

CREATE TABLE empleados1 ( empleado_id NUMBER, nombre VARCHAR2(100), salario NUMBER, fecha_contrato DATE
)
PARTITION BY HASH (empleado_id) PARTITIONS 4;

INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (1, 'Ana', 50000, TO_DATE('2020-01-15', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (2, 'Brenda', 52000, TO_DATE('2022-05-05', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (3, 'Carlos', 60000, TO_DATE('2018-11-30', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (4, 'David', 45000, TO_DATE('2023-02-18', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (5, 'Elena', 55000, TO_DATE('2019-06-20', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (6, 'Fernando', 48000, TO_DATE('2021-07-10', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (7, 'Gabriela', 51000, TO_DATE('2020-03-25', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (8, 'Hugo', 58000, TO_DATE('2017-09-12', 'YYYY-MM-DD'));
INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (9, 'Iván', 49000, TO_DATE('2022-08-05', 'YYYY-MM-DD'));

INSERT INTO empleados1 (empleado_id, nombre, salario, fecha_contrato)VALUES (10, 'Julia', 53000, TO_DATE('2019-04-03', 'YYYY-MM-DD'));

SELECT empleado_id, DBMS_ROWID.ROWID_OBJECT(rowid) AS rowid_object FROM empleados1;

CREATE TABLE empleados2 ( empleado_id NUMBER, nombre VARCHAR2(100), salario NUMBER, fecha_contrato DATE
)
PARTITION BY RANGE (fecha_contrato) (
PARTITION particion_anterior VALUES LESS THAN (TO_DATE('2023-01-01', 'YYYY-MM-DD')),
PARTITION particion_posterior VALUES LESS THAN (MAXVALUE)
);

INSERT INTO empleados2 (empleado_id, nombre, salario, fecha_contrato) VALUES (1, 'Ana', 50000, TO_DATE('2022-05-15', 'YYYY-MM-DD'));
INSERT INTO empleados2 (empleado_id, nombre, salario, fecha_contrato) VALUES (2, 'Brenda', 52000, TO_DATE('2021-11-20', 'YYYY-MM-DD'));
INSERT INTO empleados2 (empleado_id, nombre, salario, fecha_contrato) VALUES (3, 'Carlos', 60000, TO_DATE('2022-08-10', 'YYYY-MM-DD'));
INSERT INTO empleados2 (empleado_id, nombre, salario, fecha_contrato) VALUES (4, 'David', 45000, TO_DATE('2023-03-18', 'YYYY-MM-DD'));
INSERT INTO empleados2 (empleado_id, nombre, salario, fecha_contrato) VALUES (5, 'Elena', 55000, TO_DATE('2023-07-22', 'YYYY-MM-DD'));
INSERT INTO empleados2 (empleado_id, nombre, salario, fecha_contrato) VALUES (6, 'Fernando', 48000, TO_DATE('2024-01-05', 'YYYY-MM-DD'));

SELECT * FROM empleados2 PARTITION (particion_anterior); SELECT * FROM empleados2 PARTITION (particion_posterior);

