alter session set "_ORACLE_SCRIPT"= true;
create user administrador1
    identified  by admin123  default tablespace users temporary tablespace temp quota 500K on users;
select privilege from dba_sys_privs where grantee = 'administrador1';
select granted_role from dba_role_privs where grantee = 'administrador1';
select table_name, privilege from dba_sys_privs where grantee ='administrador1'
grant create session to administrador1;
create user prueba1 
identified by prueba1
default tablespace users
temporary tablespace temp
quota 0k on users;

    