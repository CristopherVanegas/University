USE classicmodels;

-- SP 1 --
DELIMITER //
CREATE PROCEDURE GetOfficeByCountry(IN countryName varchar(255))
BEGIN
	SELECT *
    FROM offices
	WHERE country = countryName;
END //
DELIMITER ;

CALL GetOfficeByCountry('USA');


-- SP 2 --
DELIMITER $$
CREATE PROCEDURE GetOrderCountByStatus(IN orderStatus varchar(25), OUT total INT)
BEGIN
	SELECT COUNT(orderNumber) INTO total FROM orders
	WHERE status = orderStatus;
END $$
DELIMITER ;



CALL GetOrderCountByStatus('Shipped', @mi_variable);
SELECT @mi_variable;



CALL GetOrderCountByStatus('in process', @total);
SELECT @total AS total_in_process;

