// Funcion Mostrar Arreglo
Funcion mostrararreglo(arreglo,n)
	Definir i como entero;
	Para i<-0 Hasta n-1 con paso 1 hacer
		Escribir sin saltar "  ", arreglo[i];
	FinPara
	Escribir "";
FinFuncion

// Funcion llenar arreglo
Funcion llenararreglo(arreglo,n)
	Definir i Como Entero;
	Para i<-0 Hasta n-1 con paso 1 hacer
		arreglo[i]= Aleatorio(1,10);
	FinPara
FinFuncion

// Funcion para llenar invertido

// Elevar al cuadrado
Funcion r = elevar(b, e)
	Definir i, r Como Entero;
	r = b;
	
	// Si el exponente es 0 devuelve 1
	Si e == 0 Entonces
		r = 1;
	// Si no, eleva y devuelve
	Sino
		Para i = 1 Hasta e-1 Con Paso 1 Hacer
			r = r * b;
		FinPara
	FinSi
FinFuncion

// Guarda en el otro array
SubProceso guardarEnOtroArray ( array1, array2,n )
	Definir i Como Entero;
	Para i = 0 Hasta n-1 Con Paso 1 Hacer
		array2[i] = elevar(array1[i], 2);
	FinPara
FinSubProceso

// Guarda en el otro array pero invertido
SubProceso guardarEnOtroArrayInvertido ( array1, array2,n )
	Definir i Como Entero;
	Para i = n-1 Hasta 0 Con Paso -1 Hacer
		array2[i] = array1[n-i-1];
	FinPara
FinSubProceso


Proceso dosArreglosElevados
	// Arreglo dinamico
	Definir arreglo1, arreglo2, n como entero;
	Escribir "Ingrese el tamaño del arreglo:";
	Leer n;
	
	Mientras n<=4 Hacer
		Escribir "El arreglo debe ser mayor a 4.", "Ingrese nuevamente el tamaño:";
		Leer n;
	FinMientras
	Escribir "El tamaño del arreglo es valido";
	
	Dimension arreglo1[n];
	Dimension arreglo2[n];
	
	// llenararreglo
	llenararreglo(arreglo1, n);
	
	// mostrararreglo
	Escribir "Arreglo 1";
	mostrararreglo(arreglo1, n);
	Escribir "";
	
	guardarEnOtroArray(arreglo1, arreglo2, n);
	Escribir "Arreglo 2";
	mostrararreglo(arreglo2, n);
	Escribir "";
	
	guardarEnOtroArrayInvertido(arreglo1, arreglo2, n);
	Escribir "Arreglo 1";
	mostrararreglo(arreglo1, n);
	Escribir "Arreglo 2 Invertido";
	mostrararreglo(arreglo2, n);
	Escribir "";
FinProceso
