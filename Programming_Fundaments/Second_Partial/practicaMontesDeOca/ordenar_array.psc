// Crear un programa que ordene un array.
// ARRAY: [3, 2, 5, 7, 1]
// Ordenar de menor a mayor.

SubProceso ordenValor(array, d)
	Definir i, j, auxiliar Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Para j = i+1 Hasta d-1 Con Paso 1 Hacer
			Si array[j] < array[i] Entonces
				auxiliar = array[i];
				array[i] = array[j];
				array[j] = auxiliar;
			
			FinSi
		FinPara
	FinPara
	
FinSubProceso

Proceso main
	definir array, d, i Como Entero;
	d= 5;
	Dimension array[d];
	array[0]=3;
	array[1]=2;
	array[2]=5;
	array[3]=7;
	array[4]=1;
	
	ordenValor(array, d);
	
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Escribir array[i];
		
	FinPara
FinProceso

