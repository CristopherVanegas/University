-- Est. Cristopher Vanegas. --
-- creo la tabla EMPLEADOS con los campos ID_EMPLEADO, NOMBRE y SALARIO --
CREATE TABLE EMPLEADOS (
    id_empleado INT GENERATED ALWAYS AS IDENTITY,
    nombre varchar2(100),
    salario int,
    
    CONSTRAINT pk_empleados PRIMARY KEY (id_empleado)
);

SELECT * FROM EMPLEADOS;
SELECT table_name, owner FROM dba_tables WHERE table_name = 'EMPLEADOS';
DROP TABLE EMPLEADOS;


-- crear usuario local "practica1" --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;

CREATE USER PRACTICA_1 IDENTIFIED BY practica_1;
-- otorgo privilegios de conectividad --
GRANT CREATE SESSION TO PRACTICA_1;

SELECT username FROM dba_users WHERE username = 'PRACTICA_1';


/*
    concedo todos los privilegios con opcion de ADMIN
    en la tabla EMPLEADOS para el usuario PRACTICA_1 
*/
GRANT ALL PRIVILEGES ON EMPLEADOS TO PRACTICA_1;
REVOKE ALTER ON EMPLEADOS FROM PRACTICA_1;


-- Revisar privilegios dados a la tabla creada para el usuario generado --
SELECT privilege, grantable
    FROM DBA_TAB_PRIVS
    WHERE table_name = 'EMPLEADOS'
        AND grantee = 'PRACTICA_1';

