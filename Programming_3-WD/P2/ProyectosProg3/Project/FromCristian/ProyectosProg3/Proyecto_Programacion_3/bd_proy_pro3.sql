-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 06-07-2023 a las 00:58:34
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `historial_reservas`
--

DROP TABLE IF EXISTS `historial_reservas`;
CREATE TABLE IF NOT EXISTS `historial_reservas` (
  `ID_HistorialReserva` int NOT NULL AUTO_INCREMENT,
  `Fecha_Reserva` date NOT NULL,
  `ID_Usuario` int NOT NULL,
  `ID_Reserva` int NOT NULL,
  PRIMARY KEY (`ID_HistorialReserva`),
  KEY `ID_Usuario` (`ID_Usuario`,`ID_Reserva`),
  KEY `ID_Reserva` (`ID_Reserva`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `reserva`
--

DROP TABLE IF EXISTS `reserva`;
CREATE TABLE IF NOT EXISTS `reserva` (
  `ID_Reserva` int NOT NULL AUTO_INCREMENT,
  `Cantidad_Pasajeros` int NOT NULL,
  `Estado_Reserva` varchar(20) NOT NULL,
  `PrecioTotal_Reserva` double NOT NULL,
  `ID_Viaje` int NOT NULL,
  PRIMARY KEY (`ID_Reserva`),
  KEY `ID_Viaje` (`ID_Viaje`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

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
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`ID_Usuario`, `Nombre_Usuario`, `Apellido_Usuario`, `User_Usuario`, `Contrasenia_Usuario`, `Correo_Usuario`, `Rol_Usuario`, `FechaCreacion_Usuario`, `Tarjeta_Usuario`, `Telefono_Usuario`, `Direccion_Usuario`) VALUES
(1, 'Cris', 'Alvarado', 'cris_123', 'cralva_123', 'cris_123@yahoo.com', 'USUARIO', '2023-07-01', 1448521741, 983127412, 'La Joya. Etapa Ónix'),
(2, 'Angie', 'Alvarado', 'angieuwu', '123', 'alva@gmail.com', 'USUARIO', '2023-07-05', 123312313, 13212313, 'La Joya'),
(3, 'emanuel', 'diaz', 'ema', '123', 'ema@gmail.com', 'ADMINISTRADOR', '2023-07-05', 123, 123, '123');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `viaje`
--

DROP TABLE IF EXISTS `viaje`;
CREATE TABLE IF NOT EXISTS `viaje` (
  `ID_Viaje` int NOT NULL AUTO_INCREMENT,
  `FechaInicio_Viaje` date NOT NULL,
  `FechaFin_Viaje` date NOT NULL,
  `Precio_Viaje` double NOT NULL,
  `ID_OrigenViaje` int NOT NULL,
  `ID_DestinoViaje` int NOT NULL,
  PRIMARY KEY (`ID_Viaje`),
  KEY `ID_OrigenViaje` (`ID_OrigenViaje`,`ID_DestinoViaje`),
  KEY `ID_DestinoViaje` (`ID_DestinoViaje`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `comentarios`
--
ALTER TABLE `comentarios`
  ADD CONSTRAINT `comentarios_ibfk_1` FOREIGN KEY (`ID_Usuario`) REFERENCES `usuario` (`ID_Usuario`) ON DELETE RESTRICT ON UPDATE CASCADE;

--
-- Filtros para la tabla `historial_reservas`
--
ALTER TABLE `historial_reservas`
  ADD CONSTRAINT `historial_reservas_ibfk_1` FOREIGN KEY (`ID_Reserva`) REFERENCES `reserva` (`ID_Reserva`) ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `historial_reservas_ibfk_2` FOREIGN KEY (`ID_Usuario`) REFERENCES `usuario` (`ID_Usuario`) ON DELETE RESTRICT ON UPDATE CASCADE;

--
-- Filtros para la tabla `reserva`
--
ALTER TABLE `reserva`
  ADD CONSTRAINT `reserva_ibfk_1` FOREIGN KEY (`ID_Viaje`) REFERENCES `viaje` (`ID_Viaje`) ON DELETE RESTRICT ON UPDATE CASCADE;

--
-- Filtros para la tabla `viaje`
--
ALTER TABLE `viaje`
  ADD CONSTRAINT `viaje_ibfk_1` FOREIGN KEY (`ID_OrigenViaje`) REFERENCES `origen_viaje` (`ID_OrigenViaje`) ON DELETE RESTRICT ON UPDATE CASCADE,
  ADD CONSTRAINT `viaje_ibfk_2` FOREIGN KEY (`ID_DestinoViaje`) REFERENCES `destino_viaje` (`ID_DestinoViaje`) ON DELETE RESTRICT ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
