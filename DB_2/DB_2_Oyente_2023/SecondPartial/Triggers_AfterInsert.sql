USE classicmodels;

CREATE TABLE insert_product(
	id_product INT AUTO_INCREMENT PRIMARY KEY,
    product_name VARCHAR(25)
);


-- TRIGGER 1 -------------------------------------------------------------------------------------------------------
CREATE TRIGGER after_insert
	AFTER INSERT
ON insert_product FOR EACH ROW 
    INSERT INTO employees_audit SET accion = 'inserted product', fecha = NOW();

INSERT INTO insert_product SET product_name = 'Pringlesss';

SELECT * FROM insert_product;
SELECT * FROM employees_audit;
