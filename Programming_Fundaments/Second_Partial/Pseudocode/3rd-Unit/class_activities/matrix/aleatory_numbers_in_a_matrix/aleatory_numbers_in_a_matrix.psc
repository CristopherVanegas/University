Proceso matrix
	matrix2x2();
FinProceso

SubProceso matrix2x2()
	Definir bidimentionalMatrix, n, m, i, j Como Entero;
	Escribir " > Please enter the n dimention for matrix: ";
	Leer n;
	Escribir " > Please enter the m dimention for matrix: ";
	Leer m;
	Dimension bidimentionalMatrix[n, m];
	
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Para j=0 Hasta m-1 Con Paso 1 Hacer
			bidimentionalMatrix[i, j] = Aleatorio(0, 10);
		FinPara
	FinPara
	
	Escribir "";
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Para j=0 Hasta m-1 Con Paso 1 Hacer
			Escribir " [] The value for the matrix in position [", i,", ", j, "] is ", bidimentionalMatrix[i, j];
		FinPara
	FinPara
FinSubProceso
	