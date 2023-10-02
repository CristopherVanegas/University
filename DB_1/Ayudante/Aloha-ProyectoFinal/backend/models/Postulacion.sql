-- Crear una tabla postulacion si no existe y agregarle los siguientes campos: id_postulacion (PK), id_usuario (FK), id_sucursal (FK), fecha_creacion

CREATE TABLE IF NOT EXISTS postulacion (
    id_postulacion SERIAL PRIMARY KEY,
    id_usuario INT NOT NULL,
    fecha_creacion TIMESTAMP NOT NULL DEFAULT NOW(),
    experiencia BOOLEAN NOT NULL,

    detalle_experiencia VARCHAR(20) CHECK (detalle_experiencia IN ('cocina', 'mesero', 'cajero', 'todas', 'sin experiencia')), -- Columna opcional con restricción CHECK

    CONSTRAINT fk_postulacion_usuario
      FOREIGN KEY (id_usuario)
      REFERENCES usuario (id_usuario)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
);

