// Llenar un vector con N números e indicar cuantos de ellos son pares.

Proceso mainFunc
	nNumberPairOrNot();
FinProceso

SubAlgoritmo nNumberPairOrNot()
	Definir arr, i, pairA, d Como Entero;
	
	Escribir " > Please enter a dimension for the array: ";
	Leer d;
	Dimension arr[d];
	
	// Get values for the array
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Escribir " > Please enter a value [", i+1, "/", d, "]";
		Leer arr[i];
	FinPara
	
	// Prints each value of the array
	Escribir " [] Prints each value of the array";
	pairA = 0;
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Si arr[i]%2 == 0 Entonces
			Escribir " > Number is PAIR because it is ", arr[i];
			pairA = pairA+ 1;
		SiNo
			Escribir " > Number is NOT pair because it is ", arr[i];
		FinSi
		Escribir "";
	FinPara
	
	// Says and prints the pair numbers!
	Escribir " [] Says and prints the pair numbers!";
	Escribir " >>> There are ", pairA, " PAIR numbers!";
	Escribir "These are: ";
	
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Si arr[i]%2 == 0 Entonces
			Escribir arr[i];
		FinSi
	FinPara
FinSubAlgoritmo
