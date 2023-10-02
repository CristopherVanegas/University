-- Crear una tabla orden si no existe y agregarle los siguientes campos: id_orden (PK), id_sucursal (FK), fecha_creacion, estado, id_detalle_orden (FK), id_usuario (FK) con relacion a la tabla usuario

CREATE TABLE IF NOT EXISTS orden (
    id_orden SERIAL PRIMARY KEY,
    id_sucursal INT NOT NULL,
    fecha_creacion TIMESTAMP NOT NULL DEFAULT NOW(),
    estado VARCHAR(50) NOT NULL,
    -- id_detalle_orden INT NOT NULL,
    id_usuario INT NOT NULL,
    valor_total NUMERIC(7, 2) NOT NULL,

    CONSTRAINT fk_orden_sucursal
      FOREIGN KEY (id_sucursal) -- Columna de la tabla actual
      REFERENCES sucursal (id_sucursal) -- Columna de la tabla referenciada
      ON DELETE NO ACTION -- Acción al eliminar
      ON UPDATE NO ACTION, -- Acción al actualizar

    -- CONSTRAINT fk_orden_detalle_orden
    --   FOREIGN KEY (id_detalle_orden) -- Columna de la tabla actual
    --   REFERENCES detalle_orden (id_detalle_orden) -- Columna de la tabla referenciada
    --   ON DELETE NO ACTION -- Acción al eliminar
    --   ON UPDATE NO ACTION, -- Acción al actualizar

    CONSTRAINT fk_orden_usuario
      FOREIGN KEY (id_usuario) -- Columna de la tabla actual
      REFERENCES usuario (id_usuario) -- Columna de la tabla referenciada
      ON DELETE NO ACTION -- Acción al eliminar
      ON UPDATE NO ACTION -- Acción al actualizar
);