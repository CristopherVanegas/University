USE classicmodels;

DROP TABLE IF EXISTS insertOfficesRegister;
CREATE TABLE insertOfficesRegister(
	id INT AUTO_INCREMENT PRIMARY KEY,
    alert VARCHAR(250),
	fecha_insercion TIMESTAMP
);

-- Crear el trigger que se activará después de un INSERT en la tabla "catalogo"
DELIMITER //
CREATE TRIGGER after_offices_insert
	AFTER INSERT ON offices
	FOR EACH ROW
BEGIN
    INSERT INTO insertOfficesRegister(alert, fecha_insercion)
    VALUES (CONCAT('Nueva inserción en la tabla offices. ID: ', OLD.officeCode, ', city: ', O.city, ', addressLine1: ', NEW.addressLine1, ', addressLine2: ', NEW.addressLine2, ', state: ', NEW.state, ', country: ', NEW.country, ', postalCode: ', NEW.postalCode, ', terrotory: ', NEW.territory, ', at: ', NOW()), NOW());
END;
//
DELIMITER ;

-- Insertar una nueva fila en la tabla "offices" con un valor para 'officeCode'
INSERT INTO offices (officeCode, city, phone, addressLine1, addressLine2, state, country, postalCode, territory)
VALUES ('8', 'GYE', '+000 000 0000', 'Dirección 1', 'Dirección 2', 'GYE', 'EC', '0000', 'NA');


-- Verificar inserciones en Offices
SELECT * FROM offices;

-- Verificar el registro en la tabla "registro_inserciones"
SELECT * FROM insertOfficesRegister;