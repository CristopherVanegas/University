// Est. Cristopher Vanegas - Ejemplo de CREAR y LEER.

Proceso firstArray
	Definir num, i como entero;	// defino contador y array "num".
	Dimension num[5];			// dimensiono/creo "num" a 5 posiciones.
	
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir "Escribe un valor para el indice ", i;
		leer num[i];	// leo y escribo en el índice i para num[]
	FinPara
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir "Posición [",i, "] -> ", num[i];	// imprimo en un formato de texto.
	FinPara
FinProceso

