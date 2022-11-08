Proceso bidimentionalMatrix
	Definir matriz,filas,columnas,i,j Como Entero;
	filas=2;
	columnas=2;
	
	// fill it out of zeros
	Dimension matriz[filas,columnas];
	Para i=0 Hasta filas-1 Con Paso 1 Hacer
		Para j=0 Hasta columnas-1 Con Paso 1 Hacer
			matriz[i,j]=0;
		FinPara
	FinPara
	
	
	// show the matrix
	Para i=0 Hasta filas-1 Con Paso 1 Hacer
		Para j=0 Hasta columnas-1 Con Paso 1 Hacer
			Escribir matriz[i,j],"   ",Sin Saltar;
		FinPara
		Escribir"";
	FinPara
FinProceso
