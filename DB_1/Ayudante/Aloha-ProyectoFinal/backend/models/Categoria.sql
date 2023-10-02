-- Crear una tabla categoria si no existe y agregarle los siguientes campos: id_categoria (PK), nombre

CREATE TABLE IF NOT EXISTS categoria (
    id_categoria SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL
);