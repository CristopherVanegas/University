USE classicmodels;

CREATE TABLE employees_audit (
	idemployees_audit INT AUTO_INCREMENT PRIMARY KEY,
    accion VARCHAR(25),
    fecha DATETIME
);


-- TRIGGER 1 -------------------------------------------------------------------------------------------------------
CREATE TRIGGER before_employee_update
	BEFORE UPDATE 
ON employees FOR EACH ROW
    INSERT INTO employees_audit SET accion = 'update',
    fecha = NOW();

UPDATE employees SET extension = "x4612" WHERE employeeNumber = "1056";

SELECT * FROM employees;
SELECT * FROM employees_audit;






