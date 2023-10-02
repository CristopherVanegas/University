CREATE TABLE facturas (
    factura_id NUMBER,
    fecha DATE,
    cliente_id NUMBER,
    monto NUMBER,
    PRIMARY KEY (factura_id, cliente_id)
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

SELECT partition_name, subpartition_name, high_value
FROM user_tab_subpartitions
WHERE table_name = 'FACTURAS';
''''

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

-- Insertar Datos en la tabla de pagos
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (1, 'A', TO_DATE('2020-04-02', 'YYYY-MM-DD'), 10000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (2, 'B', TO_DATE('2022-07-02', 'YYYY-MM-DD'), 60000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (3, 'C', TO_DATE('2023-02-02', 'YYYY-MM-DD'), 50000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (4, 'D', TO_DATE('2021-06-02', 'YYYY-MM-DD'), 70000);
INSERT INTO pagos(pago_id, tipo_pago, fecha, monto) VALUES (5, 'E', TO_DATE('2023-05-02', 'YYYY-MM-DD'), 35000);

-- Verificar las particiones y subparticiones creadas en la tabla de pagos
SELECT partition_name, subpartition_name, high_value
FROM user_tab_subpartitions
WHERE table_name = 'PAGOS';

-- Realizar la operación EXCHANGE PARTITION para intercambiar la partición más reciente con la tabla "pagos_nuevos"
-- No se puede automatizar este paso debido a restricciones en Oracle SQL
-- Debes ejecutar manualmente la operación EXCHANGE PARTITION aquí

-- Verificar las particiones y subparticiones de la tabla "pagos_nuevos" después de la operación EXCHANGE PARTITION
-- No se puede automatizar este paso debido a restricciones en Oracle SQL

-- Crear la tabla detalle_facturas
CREATE TABLE
