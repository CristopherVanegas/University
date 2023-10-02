/*   P1_TAREAS_DML_ORACLE   */
-- Est. Cristopher Vanegas --

-- Ejercicio 1 - Crear tabla --
CREATE TABLE ALUMNOS (
  id_alumnos INT PRIMARY KEY,
  nombre VARCHAR(20),
  apellido VARCHAR(20),
  fecha_nacimiento DATE,
  direccion VARCHAR(100),
  ciudad VARCHAR(50),
  estado VARCHAR(50),
  genero VARCHAR(10),
  celular VARCHAR(15),
  email VARCHAR(100)
);

-- DROP TABLE ALUMNOS;


-- Ejercicio 2 - Ingresar datso --
-- Inserción 1
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (1, 'Juan', 'Pérez', TO_DATE('1995-05-15', 'YYYY-MM-DD'), 'Calle 123', 'Ciudad1', 'Estado1', 'M', '1234567890', 'juan@example.com');

-- Inserción 2
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (2, 'María', 'Gómez', TO_DATE('1998-10-25', 'YYYY-MM-DD'), 'Avenida 456', 'Ciudad2', 'Estado2', 'F', '9876543210', 'maria@example.com');

-- Inserción 3
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (3, 'Pedro', 'López', TO_DATE('1997-03-12', 'YYYY-MM-DD'), 'Calle Principal', 'Ciudad3', 'Estado3', 'M', '5555555555', 'pedro@example.com');

-- Inserción 4
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (4, 'Ana', 'Martínez', TO_DATE('1996-08-18', 'YYYY-MM-DD'), 'Avenida Central', 'Ciudad2', 'Estado2', 'F', '6666666666', 'ana@example.com');

-- Inserción 5
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (5, 'Carlos', 'Rodríguez', TO_DATE('1999-12-01', 'YYYY-MM-DD'), 'Calle Secundaria', 'Ciudad1', 'Estado1', 'M', '4444444444', 'carlos@example.com');

-- Inserción 6
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (6, 'Laura', 'Sánchez', TO_DATE('1994-07-22', 'YYYY-MM-DD'), 'Avenida Norte', 'Ciudad3', 'Estado3', 'F', '7777777777', 'laura@example.com');

-- Inserción 7
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (7, 'Eduardo', 'González', TO_DATE('1993-11-09', 'YYYY-MM-DD'), 'Calle Sur', 'Ciudad2', 'Estado2', 'M', '2222222222', 'eduardo@example.com');

-- Inserción 8
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (8, 'Sofía', 'Torres', TO_DATE('1996-02-28', 'YYYY-MM-DD'), 'Avenida Oeste', 'Ciudad1', 'Estado1', 'F', '8888888888', 'sofia@example.com');

-- Inserción 9
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (9, 'Luisa', 'Ramírez', TO_DATE('1993-06-14', 'YYYY-MM-DD'), 'Avenida Este', 'Ciudad3', 'Estado3', 'F', '9999999999', 'luisa@example.com');

-- Inserción 10
INSERT INTO ALUMNOS (id_alumnos, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (10, 'Andrés', 'García', TO_DATE('1998-09-05', 'YYYY-MM-DD'), 'Calle 456', 'Ciudad1', 'Estado1', 'M', '7777777777', 'andres@example.com');

SELECT * FROM ALUMNOS;


-- Ejercicio 3 - Eliminar Registros con una Condicion --
DELETE FROM ALUMNOS
    WHERE fecha_nacimiento < TO_DATE('1994-01-01', 'YYYY-MM-DD');
SELECT * FROM ALUMNOS;

-- Ejercicio 4 - Eliminar un Registro Especifico --
DELETE FROM ALUMNOS
    WHERE id_alumnos = 3;
SELECT * FROM ALUMNOS;


-- Ejercico 5 - Actualizar en lote varios registros de acuerdo a una Condicion --
UPDATE ALUMNOS
    SET DIRECCION = NULL
    WHERE fecha_nacimiento > TO_DATE('1995-01-01', 'YYYY-MM-DD');
SELECT * FROM ALUMNOS;

-- Ejercicio 6 - Actualizar un solo registro de la entidad creada --
UPDATE ALUMNOS
    SET CIUDAD = 'OHIO'
    WHERE id_alumnos = 8;
SELECT * FROM ALUMNOS;

-- Ejericio 7 - Borrar la tabla --
DROP TABLE ALUMNOS;

