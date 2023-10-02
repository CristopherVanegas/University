-- PRIMER PARCIAL --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;

DROP USER jvera CASCADE;

CREATE USER tu_nombre IDENTIFIED BY "ABCtyu890";
CREATE USER jvera IDENTIFIED BY "mypassword1" PASSWORD EXPIRE;
GRANT CREATE SESSION TO jvera;
--CONNECT tu_nombre/ABCtyu890;


SELECT username, account_status
FROM dba_users
WHERE account_status = 'OPEN';



-- SEGUNDO PARCIAL --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
-- Crear el perfil "taller_profile"
CREATE PROFILE taller_profile LIMIT
    CPU_PER_SESSION 30
    SESSIONS_PER_USER 5
    SESSIONS_PER_USER UNLIMITED
    CONNECT_TIME 60;



-- Crear un rol llamado "rol_taller"
CREATE ROLE rol_taller;

-- Asignar el perfil al rol
ALTER ROLE rol_taller;
GRANT perfil_taller TO rol_taller;



CREATE PROFILE TALLER_PROFILE222 LIMIT
  CPU_PER_SESSION 30
  SESSIONS_PER_USER 5
  CONNECT_TIME 60; -- 60 minutos
    
SELECT profile, resource_name, limit
    FROM dba_profiles
    WHERE profile = 'TALLER_PROFILE222';
    
DROP PROFILE TALLER_PROFILE222;



