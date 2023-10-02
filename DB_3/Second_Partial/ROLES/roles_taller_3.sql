-- EJERCICIO 1 Y 2 --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE USER ADMINISTRADOR
    IDENTIFIED BY admin123
        DEFAULT   TABLESPACE users
        TEMPORARY TABLESPACE temp
        QUOTA 500K ON USERS;
SELECT username FROM dba_users WHERE username = 'ADMINISTRADOR';


-- EJERCICIO 3 --
SELECT privilege FROM dba_sys_privs
    WHERE grantee = 'ADMINISTRADOR';  --  PRIVILEGIOS CONCEDIDOS  --
SELECT granted_role FROM dba_role_privs
    WHERE grantee = 'ADMINISTRADOR';  --  ROLES CONCEDIDOS  --
SELECT table_name, privilege FROM dba_tab_privs
    WHERE grantee = 'ADMMINISTRADOR'; --  PERMISOS CONCEDIDOS SOBRE OBJETOS  --


-- EJERCICIO 4 --
GRANT CREATE SESSION TO ADMINISTRADOR;

-- EJERCICIO 6 -- PARTE 1 --
GRANT CREATE USER TO ADMINISTRADOR;

-- EJERCICIO 7 --
SELECT grantee FROM dba_sys_privs
    WHERE privilege = 'CREATE USER';

-- EJERCICIO 8 --
SELECT grantee FROM dba_sys_privs
    WHERE privilege = 'CREATE SESSION';
    
DROP USER PRUEBA00;