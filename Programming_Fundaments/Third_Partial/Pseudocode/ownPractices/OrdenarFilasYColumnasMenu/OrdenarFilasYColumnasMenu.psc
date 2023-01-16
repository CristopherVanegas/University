// crear un menu para ordenar filas en ascendente o descendente
// crear un menu para ordenar columnas en ascendente o descendente
// ordenar una matrix de 2x2
// usar funciones
// [3, 2]
// [2, 1]

SubProceso ordenarMatriz(array, d)
	Definir i, j, k, auxiliar Como Entero;
	definir f, c Como Entero;
	Escribir "Seleccione si quiere ordenar filas ascendente o descendente: ";
	Escribir "1) ascendente", ", 2) descendente";
	leer f;
	
	
	Si f = 1 Entonces
		Para i=0 Hasta d-1 Con Paso 1 Hacer
			Para j = 0 Hasta d-1 Con Paso 1 Hacer
				Para k = 0 Hasta d-1 Con Paso 1 Hacer
					Si array[i, k] > array[i, j] Entonces
						auxiliar = array[i, j];
						array[i, j] = array[i, k];
						array[i, k] = auxiliar;
					FinSi
				FinPara
			FinPara
		FinPara
	FinSi
	
	Si f = 2 Entonces
		Para i=0 Hasta d-1 Con Paso 1 Hacer
			Para j = 0 Hasta d-1 Con Paso 1 Hacer
				Para k = 0 Hasta d-1 Con Paso 1 Hacer
					Si array[i, k] < array[i, j] Entonces
						auxiliar = array[i, j];
						array[i, j] = array[i, k];
						array[i, k] = auxiliar;
					FinSi
				FinPara
			FinPara
		FinPara
	FinSi
	
FinSubProceso


Proceso main
	definir array, i, j, d Como Entero;
	
	d=2;
	Dimension array[d, d];
	array[0, 0]=3;
	array[0, 1]=2;
	array[1, 0]=2;
	array[1, 1]=1;
	
	ordenarMatriz(array,d);	
	
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Para j=0 Hasta d-1 Con Paso 1 Hacer
			Escribir array[i, j];
		FinPara
	FinPara
	
FinProceso