-- Est. Cristopher Vanegas --
-- Ejercicio 1 --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE ROLE ADMIN2;
SELECT role FROM dba_roles
    WHERE role = 'ADMIN2';

-- Ejercicio 2 --
CREATE PROFILE HIGH_PERMISSIONS LIMIT
    SESSIONS_PER_USER 10
    CPU_PER_SESSION 10000;
SELECT profile, resource_name, limit
    FROM dba_profiles
    WHERE profile = 'HIGH_PERMISSIONS';
    
-- Ejercicio 3 --
CREATE USER JOHNDOE1
    IDENTIFIED BY mypassword
    PROFILE HIGH_PERMISSIONS;
SELECT username, account_status
    FROM dba_users
    WHERE username = 'JOHNDOE1';
    
-- Ejercicio 4 --
GRANT ADMIN2 TO JOHNDOE1;
SELECT * FROM dba_role_privs
    WHERE grantee = 'JOHNDOE1';
    
-- Ejercicio 5 --
ALTER ROLE ADMIN_2 SET profile high_permissions;    /* Error sintactico */
SELECT * FROM dba_role_privs
    WHERE granted_role = 'ADMIN2';
ALTER USER JOHNDOE1 PROFILE high_permissions;
SELECT u.username, u.profile, r.granted_role FROM 
    dba_users u JOIN dba_role_privs r
    ON u.username = r.grantee
WHERE r.granted_role = 'ADMIN2';

-- Ejercicio 6 --
SELECT *
    FROM dba_profiles
    WHERE profile = 'HIGH_PERMISSIONS';
    
-- Ejercicio 7 --
SELECT role
    FROM dba_roles
    WHERE role = 'ADMIN1';

-- Ejercicio 8 --
CREATE ROLE EDITOR1;
SELECT role FROM dba_roles
    WHERE role = 'EDITOR1';

-- Ejercicio 9 --
CREATE PROFILE LOW_PERMISSIONS LIMIT
    SESSIONS_PER_USER 5
    CPU_PER_SESSION 5000;
SELECT * FROM dba_profiles
    WHERE profile = 'LOW_PERMISSIONS';
    
-- Ejercicio 10 --
CREATE USER JANEDOE2
    IDENTIFIED BY mypassword
    PROFILE LOW_PERMISSIONS;
SELECT username, profile FROM dba_users
    WHERE username = 'JANEDOE2';
    
-- Ejercicio 11 --
GRANT EDITOR TO JANEDOE2;  /* Rol editor no existe */

-- Ejercicio 12 --
SELECT * FROM dba_role_privs
    WHERE granted_role = 'EDITOR2';
ALTER ROLE EDITOR2 SET PROFILE LOW_PERMISSIONS; /* Error sintactico */
-- ALTER USER user_1 PROFILE LOW_PERMISSIONS;


-- Ejercicio 13 --
SELECT username, profile FROM dba_users
    WHERE username = 'JANEDOE2';
    
-- Ejercicio 14 --
SELECT GRANTEE, GRANTED_ROLE FROM dba_role_privs
    WHERE GRANTEE = 'JANADOE2';

-- Ejercicio 15 --
SELECT PROFILE FROM dba_profiles;   /* PERFILES */
SELECT ROLE FROM dba_roles; /* ROLES */

