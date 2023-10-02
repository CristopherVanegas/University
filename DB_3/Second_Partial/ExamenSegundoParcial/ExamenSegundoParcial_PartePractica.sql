/*  Est. Cristopher Vanegas  */
-- Ejercicio 1 --
    -- Crea un tablaspace llamado "taller_tablespace" con un tama;o inicial de 100M y un crecimiento aumatico de 10M. 
    -- Crea un user llamado "taller_user" con la contrase;a "taller123" y asigna el tablespace "taller_tablespace" como su tablespace predeterminado. 
CREATE TABLESPACE taller_tablespace
DATAFILE 'C:\oracleXE\taller_tablespace.txt'
SIZE 100M
AUTOEXTEND ON
NEXT 10M;

ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE USER TALLER_USER
    IDENTIFIED BY taller123
    DEFAULT TABLESPACE taller_tablespace;

SELECT * FROM ALL_USERS 
    WHERE USERNAME = 'TALLER_USER';


-- Ejecicio 2 --
    -- Crea un rol llamado "taller_role" con el privilegio de crear vistas.
CREATE ROLE TALLER_ROLE;
GRANT CREATE VIEW TO TALLER_ROLE;

SELECT * FROM dba_roles WHERE ROLE = 'TALLER_ROLE';


-- Ejercicio 3 --
    -- Crea un perfil llamado "taller_profile" con las siguientes restricciones:
        -- Limite de session de cpu: 30seg
        -- Limite de session de tiempo 1 hora
        -- Limite de sessiones concurrentes 5.
    
CREATE PROFILE TALLER_PROFILE LIMIT
    CPU_PER_SESSION 30000
    SESSIONS_PER_USER 5;
    
SELECT profile, resource_name, limit
    FROM dba_profiles
    WHERE profile = 'TALLER_PROFILE';


-- Ejercicio 4 --
    -- Asigna el rol "taller_role" al usuario "taller_user". 
    -- Asigna el perfil "taller_profile" al usuario "taller_user" --
GRANT taller_role TO taller_user;
ALTER USER taller_user PROFILE taller_profile;


-- Ejercicio 5 --
    -- Verifica los roles existentes en la base de datos.
    -- Verifica los perfiles existentes en la base de datos. --
SELECT * FROM dba_roles;
SELECT profile, resource_name, limit FROM dba_profiles;


-- Ejercicio 6 --
    -- Revoca el rol "taller_role" al usuario "taller_user".
    -- Revoca el perfil "taller_profile" al usuario "taller_user". --
REVOKE taller_role TO taller_user;
REVOKE taller_profile TO taller_user;

SELECT GRANTEE, GRANTED_ROLE FROM dba_role_privs
    WHERE GRANTEE = 'TALLER_USER';

SELECT profile, resource_name, limit
    FROM dba_profiles
    WHERE profile = 'TALLER_USER';


-- Ejercicio 7 --
    -- Crea un nuevo usuario llamado "taller_user2" con la contrase;a "taller456".
    -- Y asigna el tablespace "taller_tablespace" como su tablespace predeterminado.
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE USER TALLER_USER2
    IDENTIFIED BY taller456
    DEFAULT TABLESPACE taller_tablespace;


-- Ejercicio 8 -
    -- Antes deberas crear la tabla con al menos 5 campos e insertarles al menos 5 registros.
-- Ejercicio 1 - Crear tabla --
DROP TABLE EMPLEADOS;

CREATE TABLE EMPLEADOS (
  id_empleados INT PRIMARY KEY,
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

SELECT * FROM EMPLEADOS;

-- Inserción 1
INSERT INTO EMPLEADOS (id_empleados, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (1, 'Juan', 'Pérez', TO_DATE('1995-05-15', 'YYYY-MM-DD'), 'Calle 123', 'Ciudad1', 'Estado1', 'M', '1234567890', 'juan@example.com');

-- Inserción 2
INSERT INTO EMPLEADOS (id_empleados, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (2, 'María', 'Gómez', TO_DATE('1998-10-25', 'YYYY-MM-DD'), 'Avenida 456', 'Ciudad2', 'Estado2', 'F', '9876543210', 'maria@example.com');

-- Inserción 3
INSERT INTO EMPLEADOS (id_empleados, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (3, 'Pedro', 'López', TO_DATE('1997-03-12', 'YYYY-MM-DD'), 'Calle Principal', 'Ciudad3', 'Estado3', 'M', '5555555555', 'pedro@example.com');

-- Inserción 4
INSERT INTO EMPLEADOS (id_empleados, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (6, 'Laura', 'Sánchez', TO_DATE('1994-07-22', 'YYYY-MM-DD'), 'Avenida Norte', 'Ciudad3', 'Estado3', 'F', '7777777777', 'laura@example.com');

-- Inserción 5
INSERT INTO EMPLEADOS (id_empleados, nombre, apellido, fecha_nacimiento, direccion, ciudad, estado, genero, celular, email)
VALUES (7, 'Eduardo', 'González', TO_DATE('1993-11-09', 'YYYY-MM-DD'), 'Calle Sur', 'Ciudad2', 'Estado2', 'M', '2222222222', 'eduardo@example.com');

    -- Crea un rol llamado "taller_role2" con el privilegio de seleccion (SELECT) en la tabla "empleados".
CREATE ROLE TALLER_ROLE2;
GRANT SELECT ON EMPLEADOS TO TALLER_ROLE2;

SELECT * FROM dba_roles WHERE ROLE = 'TALLER_ROLE2';


-- Ejercicio 9 --
    -- Crea un perfil llamado "taller_profile2" con las siguientes restricciones: --
        -- Limite de session de CPU: 20seg.
        -- Limite de sesion de tiempo: 2horas.
        -- Limite de sesiones concurrentes: 3.
CREATE PROFILE TALLER_PROFILE2 LIMIT
    CPU_PER_SESSION 20000
    SESSIONS_PER_USER 2;
    
SELECT profile, resource_name, limit
    FROM dba_profiles
    WHERE profile = 'TALLER_PROFILE2';
    

-- Ejercicio 10 --
    -- Asigna el rol "taller_role2" al usuario "taller_user2".
    -- Asigna el perfil "taller_profile2" al usuario "taller_user2".
    -- Ingresar un usuario taller_user2 y realizar un select a la tabla empleados.
    
GRANT TALLER_ROLE2 TO TALLER_USER2;
ALTER USER TALLER_USER2 PROFILE TALLER_PROFILE2;
-- iniciar en sqlplus con TALLER_USER2;


-- Ejercicio 11 --
    -- Crea un nuevo usuario llamado "taller_user3" con la contrase;a "taller789" y asigna el tablespace "taller_tablespace" como su tablespace predeterminado.
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE USER TALLER_USER3
    IDENTIFIED BY taller789
    DEFAULT TABLESPACE taller_tablespace;
GRANT CREATE SESSION TO TALLER_USER3;

SELECT * FROM ALL_USERS 
    WHERE USERNAME = 'TALLER_USER3';
    
-- Ejercicio 12 --
    -- Antes deberas crear la tabla con al menos 5 campos e insertarles al menos 5 registros.
    
DROP TABLE ORDERS;

CREATE TABLE ORDERS (
  id_orders INT PRIMARY KEY,
  producto VARCHAR(20),
  fecha_creacion DATE,
  fecha_vencimiento DATE,
  empresa VARCHAR(20),
  precio INT
);

-- Inserción 1
INSERT INTO ORDERS (id_orders, producto, fecha_creacion, fecha_vencimiento, empresa, precio)
VALUES (1, 'Leche', TO_DATE('1995-05-15', 'YYYY-MM-DD'), TO_DATE('1995-05-15', 'YYYY-MM-DD'), 'La Lechera', 1);

-- Inserción 2
INSERT INTO ORDERS (id_orders, producto, fecha_creacion, fecha_vencimiento, empresa, precio)
VALUES (2, 'Cereal', TO_DATE('1995-05-15', 'YYYY-MM-DD'), TO_DATE('1995-07-15', 'YYYY-MM-DD'), 'Trix', 3);

-- Inserción 3
INSERT INTO ORDERS (id_orders, producto, fecha_creacion, fecha_vencimiento, empresa, precio)
VALUES (3, 'Laptop', TO_DATE('1995-05-15', 'YYYY-MM-DD'), TO_DATE('2005-05-15', 'YYYY-MM-DD'), 'Dell', 1000);

-- Inserción 4
INSERT INTO ORDERS (id_orders, producto, fecha_creacion, fecha_vencimiento, empresa, precio)
VALUES (4, 'Coffee', TO_DATE('1995-05-15', 'YYYY-MM-DD'), TO_DATE('1995-8-15', 'YYYY-MM-DD'), 'Cafe Oro', 5);

-- Inserción 5
INSERT INTO ORDERS (id_orders, producto, fecha_creacion, fecha_vencimiento, empresa, precio)
VALUES (5, 'Pan', TO_DATE('1995-05-15', 'YYYY-MM-DD'), TO_DATE('1995-05-25', 'YYYY-MM-DD'), 'Panaderia el Pato', 2);

SELECT * FROM ORDERS;

    -- Crea un rol llamado "taller_role3" con el privilegio de insercion (INSERT) en la tabla "Orders".
CREATE ROLE TALLER_ROLE3;
GRANT INSERT ON ORDERS TO TALLER_ROLE3;


-- Ejercicio 13 --
    -- Crea un perfil llamado "taller_profile3" con las siguientes restricciones:
        -- Limite de sesion de CPU: 40seg.
        -- Limite de session de tiempo: 3horas.
        -- Limite de sesiones concurrentes: 2.
CREATE PROFILE TALLER_PROFILE3 LIMIT
    CPU_PER_SESSION 40000;
    SESSIONS_PER_USER 2
    
SELECT profile, resource_name, limit
    FROM dba_profiles
    WHERE profile = 'TALLER_PROFILE3';

-- Ejercicio 14 --
    -- Asigna el rol "taller_role3" al usuario "taller_user3".
    -- Asigna el perfil "taller_profile3" al usuario "taller_user3".
    -- Ingresa con el usuario TALLER_USER3 y realizar un INSERT a la tabla orders.
    
GRANT TALLER_ROLE3 TO TALLER_USER3;
ALTER USER TALLER_USER3 PROFILE TALLER_PROFILE3;
-- Tercera operacion en sqlplus --
-- Inserción 6
/*
    INSERT INTO ORDERS (id_orders, producto, fecha_creacion, fecha_vencimiento, empresa, precio)
    VALUES (6, 'Pizza Familiar Pepperonni', TO_DATE('1995-05-15', 'YYYY-MM-DD'), TO_DATE('1995-05-16', 'YYYY-MM-DD'), 'Domino's', 15);
*/










