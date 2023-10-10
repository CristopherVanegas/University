USE classicmodels;

SHOW TABLES;

SELECT
	customerName,
    city,
    state,
    postalCode,
    country
FROM
	customers
ORDER BY customerName;

-- Stored Procedure --
DELIMITER $$
CREATE PROCEDURE GetCustomers()
BEGIN
	SELECT
		customerName,
        city,
        state,
        postalCode,
        country
	FROM
		customers
	ORDER BY customerName;
END
$$ DELIMITER ;


-- Stored Procedure 1 --
DROP PROCEDURE IF EXISTS GetEmployees;
DELIMITER $$
CREATE PROCEDURE GetEmployees()
BEGIN
	SELECT
		employeeNumber,
        firstName,
		lastName,
        email,
        officeCode,
        extension,
        jobTitle
	FROM
		employees
	WHERE
		employeeNumber < 1400;
END
$$ DELIMITER ;

CALL GetEmployees();
SHOW CREATE PROCEDURE GetEmployees;


-- Stored Procedure 2 --
DROP PROCEDURE IF EXISTS GetOffices;
DELIMITER $$
CREATE PROCEDURE GetOffices()
BEGIN
	SELECT offices.officeCode, firstName, lastName, email, jobTitle
	FROM offices
	INNER JOIN employees ON offices.officeCode = employees.officeCode;
END
$$ DELIMITER ;

CALL GetOffices();
SHOW CREATE PROCEDURE GetOffices;


-- Stores Procedure 3 --
DROP PROCEDURE IF EXISTS GetOrders;
DELIMITER $$
CREATE PROCEDURE GetOrders()
BEGIN
	SELECT orderNumber, orderDate, customerNumber FROM orders WHERE status="Shipped";
END
$$ DELIMITER ;
CALL GetOrders();

