-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 04-08-2023 a las 22:46:48
-- Versión del servidor: 8.0.31
-- Versión de PHP: 8.0.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `bd_proy_pro3`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comentarios`
--

DROP TABLE IF EXISTS `comentarios`;
CREATE TABLE IF NOT EXISTS `comentarios` (
  `ID_Comentario` int NOT NULL AUTO_INCREMENT,
  `Comentario` varchar(300) NOT NULL,
  `Fecha_Comentario` date NOT NULL,
  `ID_Usuario` int NOT NULL,
  PRIMARY KEY (`ID_Comentario`),
  KEY `ID_Usuario` (`ID_Usuario`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `comentarios`
--

INSERT INTO `comentarios` (`ID_Comentario`, `Comentario`, `Fecha_Comentario`, `ID_Usuario`) VALUES
(1, '¡Muy bonito!', '2023-07-20', 2),
(2, 'En el viaje que realicé a Ciudad de México, tuve cierto percance con el paquete turístico. Era sobre las actividades, eran muy pocas. Podrían añadir más.', '2023-08-04', 2),
(3, 'El viaje que realicé a Roma fue bastante bonito. ¡Recomiendo esta agencia a más no poder!', '2023-08-04', 1),
(4, 'Si tengo que calificar el servicio, le pongo un 11 / 10.', '2023-08-04', 3),
(5, 'Mi viaje a Madrid donde recorrí la ciudad en bicicleta fue de las mejores experiencias que he tenido en mi vida. ¡Gracias!', '2023-08-04', 7),
(6, 'México no me gustó... ¡Me encantó!', '2023-08-04', 8),
(7, 'Rusia es un país muy frío. Deberían considerar nuevos paquetes para este país.', '2023-08-04', 9),
(8, 'Río de Janeiro es un paraíso que todos algún día deberían visitar.', '2023-08-04', 10);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `destino_viaje`
--

DROP TABLE IF EXISTS `destino_viaje`;
CREATE TABLE IF NOT EXISTS `destino_viaje` (
  `ID_DestinoViaje` int NOT NULL AUTO_INCREMENT,
  `Ciudad_Destino` varchar(50) NOT NULL,
  `Pais_Destino` varchar(50) NOT NULL,
  `Aeropuerto_Destino` varchar(50) NOT NULL,
  PRIMARY KEY (`ID_DestinoViaje`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `destino_viaje`
--

INSERT INTO `destino_viaje` (`ID_DestinoViaje`, `Ciudad_Destino`, `Pais_Destino`, `Aeropuerto_Destino`) VALUES
(1, 'New York', 'Estados Unidos', 'Aeropuerto Internacional John F. Kennedy'),
(2, 'París', 'Francia', 'Aeropuerto de Charles de Gaulle'),
(3, 'Londres', 'Reino Unido [UK]', 'Aeropuerto Heathrow'),
(4, 'Roma', 'Italia', 'Aeropuerto Internacional de Fiumicino'),
(5, 'Moscú', 'Rusia', 'Aeropuerto Internacional Sheremétievo'),
(6, 'Beijing', 'China', 'Aeropuerto Internacional de Pekín'),
(7, 'Tokio', 'Japón', 'Aeropuerto Internacional de Haneda'),
(8, 'Seúl', 'Corea del Sur', 'Aeropuerto Internacional de Incheon'),
(9, 'Sidney', 'Australia', 'Aeropuerto Internacional Kingsford Smith'),
(10, 'Madrid', 'España', 'Aeropuerto Barajas Adolfo Suárez'),
(11, 'Ciudad de México', 'México', 'Aeropuerto Internacional Benito Juárez'),
(12, 'Bogotá', 'Colombia', 'Aeropuerto Internacional El Dorado'),
(13, 'Rio de Janeiro', 'Brasil', 'Aeropuerto Internacional de Galeão'),
(14, 'Buenos Aires', 'Argentina', 'Aeropuerto Internacional Ministro Pistarini'),
(15, 'Toronto', 'Canadá', 'Aeropuerto Internacional Toronto Pearson'),
(16, 'Santiago de Chile', 'Chile', 'Aeropuerto Internacional Arturo Merino Benítez'),
(17, 'Ciudad de Panamá', 'Panamá', 'Aeropuerto Internacional de Tocumen'),
(18, 'San Salvador', 'El Salvador', 'El Aeropuerto Internacional San Óscar Arnulfo Rome'),
(19, 'La Habana', 'Cuba', 'Aeropuerto Internacional José Martí'),
(20, 'San Juan', 'Puerto Rico', 'Aeropuerto Internacional Luis Muñoz Marín');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `origen_viaje`
--

DROP TABLE IF EXISTS `origen_viaje`;
CREATE TABLE IF NOT EXISTS `origen_viaje` (
  `ID_OrigenViaje` int NOT NULL AUTO_INCREMENT,
  `Ciudad_Origen` varchar(30) NOT NULL,
  `Pais_Origen` varchar(30) NOT NULL,
  `Aeropuerto_Origen` varchar(50) NOT NULL,
  PRIMARY KEY (`ID_OrigenViaje`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `origen_viaje`
--

INSERT INTO `origen_viaje` (`ID_OrigenViaje`, `Ciudad_Origen`, `Pais_Origen`, `Aeropuerto_Origen`) VALUES
(1, 'Guayaquil', 'Ecuador', 'Aeropuerto Internacional José Joaquín de Olmedo'),
(2, 'Quito', 'Ecuador', 'Aeropuerto Internacional Mariscal Sucre'),
(3, 'Cuenca', 'Ecuador', 'Aeropuerto Mariscal La Mar'),
(4, 'Seymur Sur (Isla Baltra)', 'Ecuador', 'Aeropuerto Seymour [Ecológico Galápagos]');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `paquete_turistico`
--

DROP TABLE IF EXISTS `paquete_turistico`;
CREATE TABLE IF NOT EXISTS `paquete_turistico` (
  `ID_PaqueteTuristico` int NOT NULL AUTO_INCREMENT,
  `Nombre_Paquete` varchar(50) NOT NULL,
  `Actividades` varchar(300) NOT NULL,
  PRIMARY KEY (`ID_PaqueteTuristico`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `paquete_turistico`
--

INSERT INTO `paquete_turistico` (`ID_PaqueteTuristico`, `Nombre_Paquete`, `Actividades`) VALUES
(1, 'Aventura Urbana', 'Explorando la ciudad en bicicleta, visitando museos y galerías de arte, y disfrutando de la gastronomía local.'),
(2, 'Rutas Históricas', 'Recorriendo los monumentos y sitios históricos más importantes de la ciudad, con visitas guiadas y actividades culturales.'),
(3, 'Naturaleza en la Ciudad', 'Descubriendo los parques y reservas naturales de la ciudad, haciendo senderismo, avistamiento de aves y picnic en la naturaleza.'),
(4, 'Descubre la Ciudad', 'Paseos por los barrios más emblemáticos de la ciudad, visitas a mercados y tiendas locales, y degustación de comida típica.'),
(5, 'Cultura y Tradición', 'Conociendo las costumbres y tradiciones locales, visitando mercados de artesanías, festivales y eventos culturales.'),
(6, 'Playa y Ciudad', 'Combinando la experiencia urbana con actividades en la playa, como surf, paddleboard, y paseos en bote.'),
(7, 'Sabores de la Ciudad', 'Degustando los platillos más representativos de la gastronomía local, visitando restaurantes y bares de la ciudad.'),
(8, 'Ciudad en Bicicleta', 'Recorriendo la ciudad en bicicleta, visitando parques, monumentos, y lugares icónicos de la ciudad.');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

DROP TABLE IF EXISTS `usuario`;
CREATE TABLE IF NOT EXISTS `usuario` (
  `ID_Usuario` int NOT NULL AUTO_INCREMENT,
  `Nombre_Usuario` varchar(50) NOT NULL,
  `Apellido_Usuario` varchar(50) NOT NULL,
  `User_Usuario` varchar(50) NOT NULL,
  `Contrasenia_Usuario` varchar(50) NOT NULL,
  `Correo_Usuario` varchar(50) NOT NULL,
  `Rol_Usuario` varchar(15) NOT NULL,
  `FechaCreacion_Usuario` date NOT NULL,
  `Tarjeta_Usuario` int NOT NULL,
  `Telefono_Usuario` int NOT NULL,
  `Direccion_Usuario` varchar(50) NOT NULL,
  PRIMARY KEY (`ID_Usuario`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`ID_Usuario`, `Nombre_Usuario`, `Apellido_Usuario`, `User_Usuario`, `Contrasenia_Usuario`, `Correo_Usuario`, `Rol_Usuario`, `FechaCreacion_Usuario`, `Tarjeta_Usuario`, `Telefono_Usuario`, `Direccion_Usuario`) VALUES
(1, 'Christian', 'Alvarado', 'cris_123', 'cralva_123', 'cris_123@yahoo.com', 'USUARIO', '2023-07-01', 1448521741, 983127412, 'La Joya. Etapa Ónix'),
(2, 'Angie', 'Alvarado', 'angie_345', 'kielair_12', 'alva@gmail.com', 'USUARIO', '2023-07-05', 2013985214, 957841236, 'Villa del Rey. Etapa \"Príncipe\"'),
(3, 'Emanuel', 'Díaz', 'ema_23', '102934', 'ema24@gmail.com', 'USUARIO', '2023-07-05', 1239587412, 963147852, 'Ciudadela \"Los Vergeles\"'),
(4, 'Martín', 'Bastidas', 'mbas', '12345', 'mbas@admin.com', 'ADMINISTRADOR', '2023-07-14', 1, 1, 'ECOTEC'),
(5, 'Cristian', 'Alaña', 'cralana', '12345', 'cralana@admin.com', 'ADMINISTRADOR', '2023-08-04', 2, 2, 'ECOTEC'),
(6, 'Christopher', 'Vanegas', 'crivanegas', '12345', 'crivanegas@admin.com', 'ADMINISTRADOR', '2023-08-04', 3, 3, 'ECOTEC'),
(7, 'Santiago', 'Flores', 'santi_2431', 'san_flor_0192', 'santiflores@gmail.com', 'USUARIO', '2023-08-04', 231645878, 964312878, 'Ciudadela \"La Alborada\"'),
(8, 'Ana', 'Herrera', 'anita_uwu', 'anitalahuerfanita_3', 'annasworld@yahoo.com', 'USUARIO', '2023-08-04', 854613258, 864512374, 'Av. Francisco de Orellana'),
(9, 'Carlos', 'Moreno', 'car_m_m', 'thecharlesking', 'cmoreno@hotmail.com', 'USUARIO', '2023-08-04', 913467852, 231646987, 'Circunvalación 112. Luis Urdaneta'),
(10, 'Sofía', 'Ríos', 'sofi_river', 'darkmoonlagoon', 'sofiariver@outlook.com', 'USUARIO', '2023-08-04', 964613478, 974642135, 'Av. 9 de Octubre');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `viaje`
--

DROP TABLE IF EXISTS `viaje`;
CREATE TABLE IF NOT EXISTS `viaje` (
  `ID_Viaje` int NOT NULL AUTO_INCREMENT,
  `ID_Usuario` int NOT NULL,
  `FechaInicio_Viaje` date NOT NULL,
  `FechaFin_Viaje` date NOT NULL,
  `Precio_Viaje` double NOT NULL,
  `ID_OrigenViaje` int NOT NULL,
  `ID_DestinoViaje` int NOT NULL,
  `ID_PaqueteTuristico` int NOT NULL,
  PRIMARY KEY (`ID_Viaje`),
  KEY `ID_OrigenViaje` (`ID_OrigenViaje`,`ID_DestinoViaje`),
  KEY `ID_DestinoViaje` (`ID_DestinoViaje`),
  KEY `ID_PaqueteTuristico` (`ID_PaqueteTuristico`),
  KEY `ID_Usuario` (`ID_Usuario`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `viaje`
--

INSERT INTO `viaje` (`ID_Viaje`, `ID_Usuario`, `FechaInicio_Viaje`, `FechaFin_Viaje`, `Precio_Viaje`, `ID_OrigenViaje`, `ID_DestinoViaje`, `ID_PaqueteTuristico`) VALUES
(1, 2, '2023-07-20', '2023-07-27', 853, 1, 1, 4),
(2, 2, '2023-08-05', '2023-08-20', 777, 2, 3, 8),
(3, 2, '2023-09-01', '2023-08-10', 256, 3, 11, 2),
(4, 2, '2023-10-13', '2023-10-20', 215, 2, 12, 7),
(5, 1, '2023-08-01', '2023-08-31', 1174, 1, 4, 1),
(6, 1, '2023-10-04', '2023-10-25', 830, 1, 3, 5),
(7, 3, '2023-08-14', '2023-08-20', 330, 2, 12, 1),
(8, 7, '2023-12-01', '2023-12-16', 794, 4, 10, 8),
(9, 7, '2023-08-06', '2023-08-27', 356, 4, 19, 1),
(10, 8, '2023-08-31', '2023-09-30', 1166, 3, 1, 4),
(11, 8, '2023-10-01', '2023-10-31', 264, 3, 11, 4),
(12, 9, '2024-01-11', '2024-02-11', 870, 4, 5, 2),
(13, 10, '2023-08-22', '2023-08-27', 727, 1, 1, 5),
(14, 10, '2023-11-15', '2023-11-30', 412, 2, 13, 1);

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `comentarios`
--
ALTER TABLE `comentarios`
  ADD CONSTRAINT `comentarios_ibfk_1` FOREIGN KEY (`ID_Usuario`) REFERENCES `usuario` (`ID_Usuario`) ON DELETE RESTRICT ON UPDATE CASCADE;

--
-- Filtros para la tabla `viaje`
--
ALTER TABLE `viaje`
  ADD CONSTRAINT `viaje_ibfk_1` FOREIGN KEY (`ID_OrigenViaje`) REFERENCES `origen_viaje` (`ID_OrigenViaje`) ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `viaje_ibfk_2` FOREIGN KEY (`ID_DestinoViaje`) REFERENCES `destino_viaje` (`ID_DestinoViaje`) ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `viaje_ibfk_3` FOREIGN KEY (`ID_PaqueteTuristico`) REFERENCES `paquete_turistico` (`ID_PaqueteTuristico`) ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `viaje_ibfk_4` FOREIGN KEY (`ID_Usuario`) REFERENCES `usuario` (`ID_Usuario`) ON DELETE RESTRICT ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
