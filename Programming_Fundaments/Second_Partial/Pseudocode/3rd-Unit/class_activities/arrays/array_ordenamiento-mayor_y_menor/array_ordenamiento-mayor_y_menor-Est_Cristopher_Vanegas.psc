// Est. Cristopher Vanegas / ----- / Incorporación de algoritmos para encontrar mayor y menor.

SubProceso mostrarArrOrdenado( arreglo )
	Definir i Como Entero;	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		Escribir "Valor ordenado ",i,": ",arreglo[i];
	FinPara
	Escribir "";
FinSubProceso

SubProceso ordenarArregloDesc ( arreglo )
	Definir i,j, aux Como Entero;
	Para i=0 Hasta 9 Con Paso 1 Hacer
		Para j=i+1 Hasta 9 Con Paso 1 Hacer
			Si arreglo[j] < arreglo[i] Entonces
				aux = arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=aux;			
			FinSi
		FinPara
	FinPara
	
FinSubProceso

SubProceso mostrarArreglo( arreglo )
	Definir i Como Entero;	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		Escribir "Valor ",i,": ",arreglo[i];
	FinPara
	Escribir "";
	
FinSubProceso

SubProceso llenarArreglo ( arreglo )
	Definir i Como entero;	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		arreglo[i]=Aleatorio(1,20);
	FinPara
	
FinSubProceso

SubProceso mayor(arr, d)
	Definir m, i Como Entero;
	m = arr[0];
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Si m < arr[i] Entonces
			m = arr[i];
		FinSi
	FinPara
	
	Escribir "El número mayor es: ", m;
FinSubProceso

SubProceso menor(arr, d)
	Definir m, i Como Entero;
	m = arr[0];
	Para i=0 Hasta d-1 Con Paso 1 Hacer
		Si m > arr[i] Entonces
			m = arr[i];
		FinSi
	FinPara
	
	Escribir "El número menor es: ", m;
FinSubProceso

Proceso ordenamiento
	Definir i,j, aux, numer, d Como Entero;
	d = 10;
	Dimension numer[d];	
	llenarArreglo(numer);
	mostrarArreglo(numer);
	ordenarArregloDesc(numer);
	mostrarArrOrdenado(numer);	
	
	// mayor
	mayor(numer, d);
	
	// menor
	menor(numer, d);
	
FinProceso
