Algoritmo esPar
	Definir z, c, num Como Entero;
	Escribir "Ingrese un n�mero para limitar los ciclos del bucle: ";
	Leer z;
	
	Escribir "";
	Escribir "";
	Para c = 1 Hasta z Con Paso 1 Hacer
		Escribir " >>> Ciclo N�", c;
		Escribir " - Ingresar un n�mero para evaluar si es par o impar: ";
		Leer num;
		
		Si (num % 2) == 0 Entonces
			Escribir " [V] El n�mero es par!";
		SiNo
			Escribir " [X] El n�mero no es par, por lo cual es impar!";
		FinSi
		Escribir "";
	FinPara
FinAlgoritmo

