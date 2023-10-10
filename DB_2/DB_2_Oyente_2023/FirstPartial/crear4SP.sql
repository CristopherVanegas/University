-- Crear 4 SP --
USE classicmodels;

-- SP1 --
SELECT * FROM orders;

DROP PROCEDURE GetOrderCountByStatusAndCustNum;

DELIMITER $$
CREATE PROCEDURE GetOrderCountByStatusAndCustNum(IN estado varchar(25), IN custNumber INT, OUT total INT)
BEGIN
	SELECT COUNT(orderNumber) INTO total FROM orders
	WHERE status = estado AND customerNumber = custNumber;
END $$
DELIMITER ;

CALL GetOrderCountByStatusAndCustNum("Shipped", 363, @val);
SELECT @val AS Total;


