// Funcion para saber si un numero es primo o no, devuelve True o False
Funcion boolean = esPar ( n )
	Definir boolean Como Logico;
	Si n mod 2 == 0 Entonces
		boolean = Verdadero;
	SiNo
		boolean = Falso;
	FinSi
FinFuncion

// Funcion para saber si un numero es primo o no, devuelve True o False
Funcion boolean = esPrimo ( n )
	Definir boolean Como Logico;
	Definir i, c Como Entero;
	c = 0;
	
	Para i = 1 Hasta n Con Paso 1 Hacer
		Si n mod i == 0 Entonces
			c = c + 1;
		FinSi
	FinPara
	
	Si c == 2 Entonces
		boolean = Verdadero;
	SiNo
		boolean = Falso;
	FinSi
FinFuncion

// Funcion para saber si un numero es primo o no
Funcion primos(arreglo,n)
	Definir i, j, cont como entero;
	
	// Itero cada posicion del array
	Para j = 0 Hasta n-1 Con Paso 1 Hacer
		cont=0;
		// Verifico si el valor del numero en la posicion j es primo o no
		Para i<-1 Hasta arreglo[j] con paso 1 hacer
			si arreglo[j] mod i==0 Entonces
				cont=cont+1;
			FinSi
		FinPara
		
		// Verifico el contador para decidir si es primo o no
		Si cont=2 Entonces
			Escribir "El numero es primo:", arreglo[j];
		SiNo
			Escribir "El numero no es primo:", arreglo[j];
		FinSi
	FinPara
FinFuncion

// Funcion Mostrar Arreglo
Funcion mostrararreglo(arreglo,n)
	Definir i como entero;
	Para i<-0 Hasta n-1 con paso 1 hacer
		Escribir sin saltar "", arreglo[i];
	FinPara
	Escribir "";
FinFuncion

// Funcion llenar arreglo
Funcion llenararreglo(arreglo,n)
	Definir i como entero;
	Para i<-0 Hasta n-1 con paso 1 hacer
		arreglo[i]= Aleatorio(1,10);
	FinPara
FinFuncion

Proceso Main
	// Arreglo dinamico
	Definir arreglo, n como entero;
	Escribir "Ingrese el tamaño del arreglo:";
	Leer n;
	
	Mientras n<=4 Hacer
		Escribir "El arreglo debe ser mayor a 4.", "Ingrese nuevamente el tamaño:";
		Leer n;
	FinMientras
	Escribir "El tamaño del arreglo es valido";
	
	Dimension arreglo[n];
	
	// llenararreglo
	llenararreglo(arreglo, n);
	
	// mostrararreglo
	mostrararreglo(arreglo, n);
	
	// Ejecucion de la funcion primos
	primos(arreglo, n);
FinProceso

