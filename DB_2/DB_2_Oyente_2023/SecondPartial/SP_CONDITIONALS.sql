USE classicmodels;

-- SP CONDITIONAL 1 --------------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS GetCustomerShipping;

DELIMITER $$
CREATE PROCEDURE GetCustomerShipping(
	IN pCustomerNumber INT,
    OUT pShipping VARCHAR(50)
)

BEGIN
	DECLARE customerCountry VARCHAR(100);
    
    SELECT country
	INTO customerCountry FROM customers
    WHERE customerNumber = pCustomerNumber;
    
    CASE customerCountry
		WHEN 'USA' THEN
			SET pShipping = '2-day Shipping';
		WHEN 'Canada' THEN
			SET pShipping = '3-day Shipping';
		ELSE
			SET pShipping = '5-day Shipping';
	END CASE;
    
END$$
DELIMITER ;

SELECT * FROM customers;
CALL GetCustomerShipping(112, @status);
SELECT @status;


-- SP CONDITIONAL 1 --------------------------------------------------------------------------------

DELIMITER $$
CREATE PROCEDURE GetDeliveryStatus(
	IN pOrderNumber INT,
	OUT pDeliveryStatus VARCHAR(100)
)

BEGIN
	DECLARE waitingDay INT DEFAULT 0;
	SELECT DATEDIFF(requireDate, shippedDate)
    INTO waitingDay
    FROM orders
    WHERE orderNumbers = pOrderNumber;
    
    CASE
		WHEN waitingDay = 0 THEN
			SET pDeliveryStatus = 'On Time';
		WHEN waitingDay >= 1 AND waitingDay < 5 THEN
			SET pDeliveryStatus = 'Late';
		WHEN waitingDay >= 5 THEN
            SET pDeliveryStatus = 'Very Late';
		ELSE
			SET pDeliveryStatus = 'No information';
	END CASE;
END $$
DELIMITER ;