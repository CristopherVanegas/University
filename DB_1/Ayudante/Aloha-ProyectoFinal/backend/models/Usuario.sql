-- Crear una tabla usuario si no existe y agregarle los siguientes campos: id_usuario (PK), nombre, apellido, email, password, fecha_creacion, telefono, cedula, con relacion a la tabla orden

CREATE TABLE IF NOT EXISTS usuario (
    id_usuario SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    apellido VARCHAR(50) NOT NULL,
    email VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL,
    fecha_creacion TIMESTAMP NOT NULL DEFAULT NOW(),
    telefono VARCHAR(50) NOT NULL
);
