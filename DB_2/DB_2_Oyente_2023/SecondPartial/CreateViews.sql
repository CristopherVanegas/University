USE classicmodels;

-- Se desea crear una vista que represente el total de ventas por orden.
CREATE VIEW salePerOrder AS
	SELECT orderNumber, SUM(quantityOrdered * priceEach) total FROM orderDetails
		GROUP BY orderNumber
		ORDER BY total DESC;
    
SELECT * FROM salePerOrder;

SHOW TABLES;

SHOW FULL TABLES;