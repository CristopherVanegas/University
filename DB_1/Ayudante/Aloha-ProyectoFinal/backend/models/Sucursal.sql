-- Crear una tabla sucursal si no existe y agregarle los siguientes campos: id_sucursal (PK), nombre, direccion, telefono

CREATE TABLE IF NOT EXISTS sucursal (
    id_sucursal SERIAL PRIMARY KEY, 
    nombre VARCHAR(50) NOT NULL,
    direccion VARCHAR(50) NOT NULL,
    telefono VARCHAR(10) NOT NULL CHECK (LENGTH(telefono) = 10) -- 10 digitos
);