-- Est. Cristopher Vanegas --

-- 1) Crear una tabla llamada "facturas" con particionamiento por rango en la columna "fecha" y
-- subparticionamiento por hash en la columna "cliente_id". Campos para la tabla de factura: factura_id
-- NUMBER, fecha DATE, cliente_id NUMBER, monto NUMBER. Valoración (3 puntos)
DROP TABLE facturas;
CREATE TABLE facturas (
    factura_id NUMBER,
    fecha DATE,
    cliente_id NUMBER,
    monto NUMBER
)
PARTITION BY RANGE (fecha)
SUBPARTITION BY HASH (cliente_id)
SUBPARTITIONS 4
(
    PARTITION p2020 VALUES LESS THAN (TO_DATE('2021-01-01', 'YYYY-MM-DD')),
    PARTITION p2021 VALUES LESS THAN (TO_DATE('2022-01-01', 'YYYY-MM-DD')),
    PARTITION p2022 VALUES LESS THAN (TO_DATE('2023-01-01', 'YYYY-MM-DD')),
    PARTITION p2023 VALUES LESS THAN (TO_DATE('2024-01-01', 'YYYY-MM-DD'))
);


-- Insertar Datos --
INSERT INTO facturas(factura_id, fecha, cliente_id, monto) VALUES (1, TO_DATE('2020-01-02', 'YYYY-MM-DD'), 1, 50000);
INSERT INTO facturas(factura_id, fecha, cliente_id, monto) VALUES (2, TO_DATE('2023-08-17', 'YYYY-MM-DD'), 2, 60000);
INSERT INTO facturas(factura_id, fecha, cliente_id, monto) VALUES (3, TO_DATE('2022-01-15', 'YYYY-MM-DD'), 3, 70000);
INSERT INTO facturas(factura_id, fecha, cliente_id, monto) VALUES (4, TO_DATE('2022-04-25', 'YYYY-MM-DD'), 4, 90000);
INSERT INTO facturas(factura_id, fecha, cliente_id, monto) VALUES (5, TO_DATE('2021-07-11', 'YYYY-MM-DD'), 5, 54000);



-- 2) Verificar las particiones y subparticiones creadas en la tabla "facturas". Valoración (1 puntos)
SELECT partition_name, subpartition_name, high_value
FROM user_tab_subpartitions
WHERE table_name = 'FACTURAS';


-- 3) Realizar la operación EXCHANGE PARTITION para intercambiar la partición más antigua con una
-- tabla llamada "facturas_archivadas". Valoración (2 puntos)
-- Crear la tabla "facturas_archivadas" con la misma estructura que "facturas"
CREATE TABLE facturas_archivadas AS SELECT * FROM facturas WHERE 1=0;

-- Intercambiar la partición más antigua
ALTER TABLE facturas EXCHANGE PARTITION p2020 WITH TABLE facturas_archivadas;


-- 4) Verificar las particiones y subparticiones de la tabla "facturas_archivadas" después de la operación
-- EXCHANGE PARTITION. Valoración (1 puntos)
SELECT partition_name, subpartition_name, high_value
FROM user_tab_subpartitions
WHERE table_name = 'FACTURAS_ARCHIVADAS';



-- 5) Crear una tabla llamada "pagos" con particionamiento por lista en la columna "tipo_pago" y
-- subparticionamiento por rango en la columna "fecha". Campos para la tabla de pagos: pago_id
-- NUMBER, tipo_pago VARCHAR2(50), fecha DATE, monto NUMBER Valoración (3 puntos)
DROP TABLE pagos;
-- Crear la tabla de pagos
CREATE TABLE pagos (
  pago_id NUMBER PRIMARY KEY,
  tipo_pago VARCHAR2(50),
  fecha DATE,
  monto NUMBER
) 
PARTITION BY LIST (tipo_pago)
SUBPARTITION BY RANGE (fecha)
(
    PARTITION particion_a VALUES ('A')(
            SUBPARTITION particion_2021 VALUES LESS THAN (TO_DATE('2021-01-01', 'YYYY-MM-DD')),
            SUBPARTITION particion_2023 VALUES LESS THAN (TO_DATE('2023-01-01', 'YYYY-MM-DD'))
    ),
    PARTITION particion_b VALUES (DEFAULT)(
            SUBPARTITION particion_2021 VALUES LESS THAN (TO_DATE('2021-01-01', 'YYYY-MM-DD')),
            SUBPARTITION particion_2023 VALUES LESS THAN (TO_DATE('2023-01-01', 'YYYY-MM-DD'))
    )
);

-- Insertar Datos --
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (1, 1, TO_DATE('2020-04-02', 'YYYY-MM-DD'), 10000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (2, 2, TO_DATE('2022-07-02', 'YYYY-MM-DD'), 60000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (3, 3, TO_DATE('2023-02-02', 'YYYY-MM-DD'), 50000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (4, 4, TO_DATE('2021-06-02', 'YYYY-MM-DD'), 70000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (5, 5, TO_DATE('2023-05-02', 'YYYY-MM-DD'), 35000);



-- 6) Verificar las particiones y subparticiones creadas en la tabla "pagos". Valoración (1 puntos)
SELECT partition_name, subpartition_name, high_value
FROM user_tab_subpartitions
WHERE table_name = 'PAGOS';




-- 7) Realizar la operación EXCHANGE PARTITION para intercambiar la partición más reciente con una
-- tabla llamada "pagos_nuevos". Valoración (2 puntos)










-- 8) Verificar las particiones y subparticiones de la tabla "pagos_nuevos" después de la operación
-- EXCHANGE PARTITION. Valoración (1 puntos)








-- 9) Crear una tabla llamada "detalle_facturas" con particionamiento por hash en la columna "factura_id" y
-- subparticionamiento por lista en la columna "producto". Considerar los siguientes campos: detalle_id
-- NUMBER, factura_id NUMBER, producto VARCHAR2(50), cantidad NUMBER Valoración
-- (3 puntos)

DROP TABLE detalle_facturas;
-- Crear la tabla detalle_facturas
CREATE TABLE detalle_facturas (
    detalle_id NUMBER,
    factura_id NUMBER,
    producto VARCHAR2(50),
    cantidad NUMBER
)
PARTITION BY HASH(factura_id) PARTITIONS 4 (
    SUBPARTITION BY LIST(producto)
    (
        PARTITION p2020 VALUES ('Lapiz', 'Borrador'),
        PARTITION p2021 VALUES ('Laptop', 'Chompa'),
        PARTITION p2022 VALUES ('Teclado', 'Mouse'),
        PARTITION p2023 VALUES ('Monitor', 'Audifonos')
    )
);



-- Insertar Datos --
INSERT INTO detalle_facturas(detalle_id, factura_id, producto, cantidad) VALUES (1, 1, 'Lapiz', 10);
INSERT INTO detalle_facturas(detalle_id, factura_id, producto, cantidad) VALUES (2, 2, 'Laptop', 2);
INSERT INTO detalle_facturas(detalle_id, factura_id, producto, cantidad) VALUES (3, 3, 'Borrador', 3);
INSERT INTO detalle_facturas(detalle_id, factura_id, producto, cantidad) VALUES (4, 4, 'Chompa', 1);
INSERT INTO detalle_facturas(detalle_id, factura_id, producto, cantidad) VALUES (5, 5, 'Audifonos'), 1);






-- 10) Verificar las particiones y subparticiones creadas en la tabla "detalle_facturas". Valoración (0.75 puntos)
SELECT partition_name, subpartition_name
FROM user_tab_subpartitions
WHERE table_name = 'DETALLE_FACTURAS';


/*Nota: Para cada una de las tablas debe realizar la inserción de 5 registros (Valoración 1.50 - 0.5 por el
lote de inserciones en cada tabla) y presentar los datos de las particiones (Valoración 0.75 – 0.25 por cada
lote de visualizaciones de las particiones de una tabla).*/