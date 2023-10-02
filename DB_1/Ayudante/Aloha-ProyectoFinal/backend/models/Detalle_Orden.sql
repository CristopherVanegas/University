-- Crear una tabla detalle_orden si no existe y agregarle los siguientes campos: id_detalle_orden (PK), id_producto (FK), cantidad, valor_total, con relacion a la tabla producto

CREATE TABLE IF NOT EXISTS detalle_orden (
    id_detalle_orden SERIAL PRIMARY KEY,
    id_producto INT NOT NULL,
    cantidad INT NOT NULL,
    subtotal NUMERIC(7, 2) NOT NULL,
    id_orden INT NOT NULL,
    
    CONSTRAINT fk_detalle_orden_producto
      FOREIGN KEY (id_producto)
      REFERENCES producto (id_producto)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION

    CONSTRAINT fk_detalle_orden_id_orden
      FOREIGN KEY (id_orden)
      REFERENCES orden (id_orden)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
);