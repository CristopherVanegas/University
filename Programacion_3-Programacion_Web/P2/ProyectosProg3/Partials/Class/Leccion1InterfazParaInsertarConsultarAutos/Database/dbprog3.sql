-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 08-07-2023 a las 15:55:28
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
-- Base de datos: `dbprog3`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cars`
--

DROP TABLE IF EXISTS `cars`;
CREATE TABLE IF NOT EXISTS `cars` (
  `id` int NOT NULL AUTO_INCREMENT,
  `model` varchar(50) NOT NULL,
  `date_release` varchar(50) NOT NULL,
  `datetime` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `cars`
--

INSERT INTO `cars` (`id`, `model`, `date_release`, `datetime`) VALUES
(1, 'Ford Maverick', '1965', '2023-07-08'),
(2, 'aaaaa', '2023', '0000-00-00'),
(3, 'Chevrolet Camaro ZL1', '2023', '0000-00-00');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

DROP TABLE IF EXISTS `usuario`;
CREATE TABLE IF NOT EXISTS `usuario` (
  `codigo` int NOT NULL AUTO_INCREMENT,
  `usuario` varchar(30) NOT NULL,
  `password` varchar(50) NOT NULL,
  `estado` varchar(20) NOT NULL,
  `fechacreacion` date NOT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=MyISAM AUTO_INCREMENT=1234589 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`codigo`, `usuario`, `password`, `estado`, `fechacreacion`) VALUES
(1234581, 'User 3', 'user3', 'TRISTE', '2023-07-01'),
(1234580, 'Jkali_21', '1234567', 'NEUTRO', '2023-07-01'),
(1234579, 'enzo', '1234', 'FELIZ', '2023-06-24'),
(1234578, 'Christian', 'elgyemisthebestpokemon', 'FELIZ', '2023-06-24'),
(1234577, 'User 2', '54321', 'NEUTRO', '2023-06-24'),
(1234576, 'User 1', '12345', '', '2023-06-24'),
(1234583, 'Cristopher', 'Vanegas', 'Activo', '2023-07-02'),
(1234584, 'Cristopher', 'Vanegas', 'Activo', '2023-07-06'),
(1234585, 'Cristopher', 'mypassword', 'Activo', '2023-07-06'),
(1234586, 'alex123', 'alex12', 'Seleccione el estado', '2023-07-06'),
(1234587, 'andybajaa', 'Hola2468', 'Seleccione el estado', '2023-07-07'),
(1234588, 'andybajaa', 'Hola2468', 'Activo', '2023-07-07');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
