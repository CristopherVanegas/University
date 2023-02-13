// Create a script to order an Array in:
// Increasing
// Decreasing

Proceso orderingAnArray
	menu();
FinProceso

SubProceso menu()
	Definir arr, opt, d Como Entero;
	d = 4;
	Dimension arr[d];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = 7;
	arr[3] = 1;
	
	Escribir "Welcome! First to order the values, press 1 or 2 for the option you want!";
	Escribir " [1] increasing";
	Escribir " [2] decreasing";
	Leer opt;
	
	Segun opt Hacer
		1:
			increasing(arr, d);
		2:
			decreasing(arr, d);
			
		De Otro Modo:
			Escribir "Error 404, option not found!";
	FinSegun
	
FinSubProceso


SubProceso increasing(arr, d)
	Definir i, j, max Como Entero;
	
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Para j = i+1 Hasta d-1 Con Paso 1 Hacer
			Si arr[i] > arr[j] Entonces
				max = arr[i];
				
				arr[i] = arr[j];
				arr[j] = max;
			Finsi
		FinPara
	FinPara
	
	
	Escribir "";
	
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Escribir arr[i];
	FinPara
	
FinSubProceso

SubProceso decreasing(arr, d)
	Definir i, j, min Como Entero;
	
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Para j=i+1 Hasta d-1 Con Paso 1 Hacer
			Si arr[j] > arr[i] Entonces
				min = arr[j];
				
				arr[j] = arr[i];
				arr[i] = min;
			FinSi
		FinPara
	FinPara
	
	Escribir "";
	
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Escribir arr[i];
	FinPara
	
FinSubProceso
