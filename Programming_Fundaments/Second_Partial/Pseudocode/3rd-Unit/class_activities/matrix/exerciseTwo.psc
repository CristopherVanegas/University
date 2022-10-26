// Crear una matrix de 3x4 -> Listo
// Llenarlas con 0 -> Listo
// Pedir 6 numeros al user -> Listo
// Valudar si es par / impar o primo

// Llenar las filas de la siguiente manera
// [Pares]
// [Impares]
// [Primos]

Proceso matrix_2x2
	exerciseTwo();
FinProceso

SubProceso exerciseTwo()
	Definir bidimentionalMatrix, container, n, m, i, j, uNum Como Entero;
	m = 3;
	n = 4;
	Dimension bidimentionalMatrix[m, n];
	Dimension container[6];
	
	// Asks for the numbers
	Para i=0 Hasta 5 Con Paso 1 Hacer
		Escribir " > Please enter a number to fill out the container. numbers inserted -> [", i+1, "/ 6]";
		Leer container[i];
	FinPara
	
	// Set each position to 0
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			bidimentionalMatrix[i, j] = 0;
		FinPara
	FinPara
	
	// Validates and enter the numbers into each row
	Para i=0 Hasta 5 Con Paso 1 Hacer
		
		// IF it is pair and cousing number, adds to the first row.
		Si (container[i] <= 1) & (container[i]%1 == 0) & ((container[i]%2)<>0 | (container[i]%3) <> 0) & ((container[i]/2)>0 | (container[i]/3) > 0) & (container[i]%container[i] == 0) Entonces
			Si container[i]%2==0 Entonces
				Escribir "El número NO primo ", container[i], " es par.";
			SiNo
				Escribir "El número NO primo ", container[i], " es impar.";
			FinSi
		SiNo
			Si container[i]%2==0 Entonces
				Escribir "El número primo ", container[i], " es par.";
			SiNo
				Escribir "El número primo ", container[i], " es impar.";
			FinSi
		FinSi
		
		
		//Si (container[i]%2 == 0) && (container[i]%container[i] == 0 && container[i] > 1) Entonces
			
		//	Para j=0 Hasta n-1 Con Paso 1 Hacer
		//		bidimentionalMatrix[0, j] = container[i];
		//		Escribir bidimentionalMatrix[0, j];
		//	FinPara
		//SiNo
			
		//FinSi
	FinPara
	
FinSubProceso
	