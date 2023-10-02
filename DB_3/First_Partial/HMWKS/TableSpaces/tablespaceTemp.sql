
-- CREO EL TABLESPACE ---------------------------------------------
CREATE TABLESPACE tablespace1
DATAFILE 'C:\OracleEX\prueba1.txt'
SIZE 100M
AUTOEXTEND ON
NEXT 10M;


-- ELIMINO EL TABLESPACE ------------------------------------------
DROP TABLESPACE tablespace1 INCLUDING CONTENTS AND DATAFILES;

-- SELECT DE LOS TABLESPACES PARA VER SUS ESTADOS -----------------
SELECT tablespace_name, status FROM
dba_tablespaces;

-- ALTERO LA TABLA ------------------------------------------------
ALTER TABLESPACE tablespace1 OFFLINE;

ALTER TABLESPACE tablespace1
ADD DATAFILE 'C:\OracleEX\prueba2.txt'
SIZE 200M;
