-- EJERCICIO 6 -- PARTE 2 -- CONECTADO COMO ADMINISTRADOR --
ALTER SESSION SET "_ORACLE_SCRIPT"=true;
CREATE USER prueba00
    IDENTIFIED BY prueba123
    DEFAULT TABLESPACE users
    TEMPORARY TABLESPACE temp
    QUOTA 0K ON users;