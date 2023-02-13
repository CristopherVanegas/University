Algoritmo esPar
	Definir z, c, num Como Entero;
	Escribir "Ingrese un número para limitar los ciclos del bucle: ";
	Leer z;
	
	Escribir "";
	Escribir "";
	Para c = 1 Hasta z Con Paso 1 Hacer
		Escribir " >>> Ciclo N°", c;
		Escribir " - Ingresar un número para evaluar si es par o impar: ";
		Leer num;
		
		Si (num % 2) == 0 Entonces
			Escribir " [V] El número es par!";
		SiNo
			Escribir " [X] El número no es par, por lo cual es impar!";
		FinSi
		Escribir "";
	FinPara
FinAlgoritmo

