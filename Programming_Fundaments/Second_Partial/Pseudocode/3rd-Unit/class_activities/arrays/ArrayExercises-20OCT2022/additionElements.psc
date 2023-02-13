// Definir 2 arreglos (A/B) de N tamaño y solicitar el ingreso de los
// números luego sume los elementos de cada vector y almacene el rsultado
// de un vector 3 de tamaño 2

Proceso mainFunc
	additionElements();
FinProceso

SubAlgoritmo additionElements
	Definir A, B, C, i, dA, dB, vTA, vTB Como Enteros;
	
	// DIMENSION OF ARRAYS ///////////////////////////////////////
	Dimension C[2];
	
	Escribir " > Please enter the dimension for array A: ";
	Leer dA;
	Dimension A[dA];
	
	Escribir " > Please enter the dimension for array B: ";
	Leer dB;
	Dimension B[dB];
	
	//----------------------------------------------------------//
	
	// ASK FOR VALS B AND SUMS EACH ELEMENT //////////////////////////////////////////////
	Escribir "";
	Para i=0 Hasta dA-1 Con Paso 1 Hacer
		Escribir " > Please enter a value [", i+1, "/", dA, "]";
		Leer A[i];
	FinPara
	
	vTA = 0;
	Para i=0 Hasta dA-1 Con Paso 1 Hacer
		vTA = vTA + A[i];
	FinPara
	Escribir " >>> Total val for A: ", vTA;
	
	// ASK FOR VALS B AND SUMS EACH ELEMENT //////////////////////////////////////////////
	Escribir "";
	Para i=0 Hasta dB-1 Con Paso 1 Hacer
		Escribir " > Please enter a value [", i+1, "/", dB, "]";
		Leer B[i];
	FinPara
	
	vTB = 0;
	Para i=0 Hasta dB-1 Con Paso 1 Hacer
		vTB = vTB + B[i];
	FinPara
	Escribir " >>> Total val for B: ", vTB;
	
	
	// ADDS VALUE FOR C //////////////////////////////////////////////
	C[0] = vTA;
	C[1] = vTB;
	Para i=0 Hasta 1 Con Paso 1 Hacer
		Escribir " > C values are [", C[i], "]";
	FinPara
FinSubAlgoritmo
	