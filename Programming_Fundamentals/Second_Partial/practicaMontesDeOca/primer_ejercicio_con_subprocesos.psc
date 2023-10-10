// DIFERENCIA ENTRE FUNCIÓN Y MÉTODO
// Una función SIEMPRE retorna un valor.
// Un método NO retorna un valor.

// ALGO EN COMUN -> las funciónes y métodos PUEDEN o NO llevar parámetros o argumentos.


SubAlgoritmo resultado_de_la_suma  = sumar(sumando1, sumando2)
	Definir resultado_de_la_suma Como Entero;
	
	resultado_de_la_suma = sumando1  + sumando2;
FinSubAlgoritmo

SubProceso resultado_division = div(dividendo, divisor)
	Definir resultado_division Como Real;
	resultado_division = dividendo / divisor;

FinSubProceso


// crea un subproceso que posea un bucle y sea utilizado para imprimir
// un string que se recibe como parametro.

SubProceso string(word)
	
	Definir i Como Entero;
	Para i = 0 Hasta Longitud(word)-1 Con Paso 1 Hacer
		Escribir subcadena(word,i ,i);
	FinPara
	
FinSubProceso


Proceso main
	Definir resultado Como Entero;
	resultado = sumar(5, 2);
	Escribir resultado;
	
	Definir resultadoDiv Como Real;
	resultadoDiv = div(53, 16);
	Escribir resultadoDiv;
	
	Definir word Como Caracter;
	Escribir "Ingrese su palabra: " ;
	Leer word;
	Escribir word;
	string(word);


FinProceso

