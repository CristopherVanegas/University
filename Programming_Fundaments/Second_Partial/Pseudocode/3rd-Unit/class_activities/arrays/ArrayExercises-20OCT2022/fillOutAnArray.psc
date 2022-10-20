
// Llenar un arreglo o vector de 20 números aleatorios, elementos entre 1 y 50

Proceso mainFunc
	fillOutAnArray();
FinProceso

SubAlgoritmo fillOutAnArray()
	Definir arr, i Como Entero;
	Dimension arr[20];
	
	// Get values for the array
	Para i=0 Hasta 19 Con Paso 1 Hacer
		arr[i] = Aleatorio(1, 50);
	FinPara
	
	// Prints each value of the array
	Para i=0 Hasta 19 Con Paso 1 Hacer
		Escribir " > The value for position [", i, "] is ", arr[i];
	FinPara
FinSubAlgoritmo
	