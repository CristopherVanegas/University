SubProceso ordenar(arr, d)
	Definir i, j, aux Como Entero;

	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Para j = i + 1 Hasta d-1 Con Paso 1 Hacer
			Si (arr[i] < arr[j]) Entonces
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			FinSi
		FinPara
	FinPara
FinSubProceso


SubProceso agregar(arr, d)
	Definir i Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Leer arr[i];
	FinPara
FinSubProceso


SubProceso mostrar(arr, d)
	Definir i Como Entero;
	Escribir " | ", Sin Saltar;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Escribir arr[i], " ", Sin Saltar;
	FinPara
	Escribir " | ";
FinSubProceso


Proceso main
	Definir arr, d Como Entero;
	Escribir "dimension para el array = ", Sin Saltar; Leer d;
	Dimension arr[d];
	
	agregar(arr, d);
	mostrar(arr, d);
	ordenar(arr, d);
	mostrar(arr, d);
	
	// obtiene el último valor porque fue ordenado de forma ascendente
	Escribir "El número mayor es ", arr[d-1];
	// obtiene el primer valor porque fue ordenado de forma ascendente
	Escribir "El número menor es ", arr[0];

FinProceso
