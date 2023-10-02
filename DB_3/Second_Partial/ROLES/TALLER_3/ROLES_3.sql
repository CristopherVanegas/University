-- Est. Cristopher Vanegas --
-- Ejercicio 1 --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE ROLE admin_role;
SELECT * FROM dba_roles where ROLE = 'ADMIN_ROLE' or ROWNUM < 2;

-- Ejercicio 2 --
CREATE PROFILE perfil_admin
    LIMIT SESSIONS_PER_USER 7
    CPU_PER_SESSION 70000;
SELECT * FROM dba_profiles
    WHERE PROFILE = 'PERFIL_ADMIN';

-- Ejercicio 3 --
CREATE USER admin_user
    IDENTIFIED BY mypassword
    PROFILE perfil_admin;
SELECT * FROM dba_users
    WHERE USERNAME = 'ADMIN_USER';
    
-- Ejercicio 4 --
GRANT admin_role TO admin_user;

-- Ejercicio 5 --
CREATE ROLE editor_role;
SELECT * FROM dba_roles where ROLE = 'EDITOR_ROLE' or ROWNUM < 2;

-- Ejercicio 6 --
CREATE PROFILE PERFIL_EDITOR LIMIT
    SESSIONS_PER_USER 3
    CPU_PER_SESSION 3000;
SELECT * FROM dba_profiles
    WHERE PROFILE = 'PERFIL_EDITOR';

-- Ejercicio 7 --
CREATE USER editor_user
    IDENTIFIED BY mypassword 
    PROFILE perfil_editor;
SELECT USERNAME, PROFILE FROM dba_users
    WHERE USERNAME = 'EDITOR_USER';
    
-- Ejercicio 8 --
GRANT editor_role TO editor_user;
SELECT grantee, granted_role FROM dba_role_privs
    WHERE grantee = 'EDITOR_USER';
    
-- Ejercicio 9 --
GRANT UPDATE ANY TABLE, INSERT ANY TABLE, DELETE ANY TABLE TO admin_role;
SELECT grantee, privilege FROM dba_sys_privs
    WHERE grantee = 'ADMIN_ROLE';
    
-- Ejercicio 10 --
GRANT UPDATE ANY TABLE, INSERT ANY TABLE, DELETE ANY TABLE TO editor_role;
SELECT grantee, privilege FROM dba_sys_privs
    WHERE grantee = 'EDITOR_ROLE';
    