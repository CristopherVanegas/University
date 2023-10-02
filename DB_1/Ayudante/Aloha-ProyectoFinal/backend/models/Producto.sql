-- Crear una tabla producto si no existe y agregarle los siguientes campos: id_producto (PK), nombre, descripcion, precio, id_categoria (FK), con relacion a la tabla categoria

CREATE TABLE IF NOT EXISTS producto (
    id_producto SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL UNIQUE,
    descripcion VARCHAR(50) NOT NULL,
    precio NUMERIC(4, 2) NOT NULL, -- Precio con 10 dígitos en total, 2 de ellos para los decimales
    imagen VARCHAR(200) NOT NULL,
    id_categoria INT NOT NULL,

    CONSTRAINT fk_producto_categoria
      FOREIGN KEY (id_categoria)
      REFERENCES categoria (id_categoria)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
);
