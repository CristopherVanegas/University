Algoritmo conversionesGrados
	Definir opt Como Entero;
	Escribir "Conversiones de Grados";
	Escribir " [1] Grados Kelvin a Grados Fahrenheit";
	Escribir " [2] Grados Fahrenheit a Grados Kelvin";
	Leer opt;
	
	Segun opt Hacer
		1:
			Definir grado Como Real;
			Escribir "Ingresar un grado en kelvin a transformar: ";
			Leer grado;
			Escribir "La conversion de Kelvin a Fahrenheit es: ", kelvinToFah(grado);
		2:
			Definir grado Como Real;
			Escribir "Ingresar un grado en fahrenheit a transformar: ";
			Leer grado;
			Escribir "La conversion de Fahrenheit a Kelvin es: ", fahToKelvin(grado);
		De Otro Modo:
			Escribir "Opción no válida!";
	FinSegun
FinAlgoritmo

SubProceso conversion = kelvinToFah(kelvin)
	Definir conversion Como Real;
	conversion = 9/5 * (kelvin - 273.15) + 32;
FinSubProceso

SubProceso conversion = fahToKelvin(fahrenheit)
	Definir conversion Como Real;
	conversion = 5/9 * (fahrenheit - 32) + 273.15;
FinSubProceso

