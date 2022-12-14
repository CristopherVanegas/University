// Crear una matrix de 3x4 -> Listo
// Llenarlas con 0 -> Listo
// Pedir 6 numeros al user -> Listo
// Validar si es par / impar o primo

// Llenar las filas de la siguiente manera
// [Pares]
// [Impares]
// [Primos]

// Trabajo Grupal.
// Est. Cristopher Vanegas && Est. Gabriel Montes De Oca.
// NOTA: MODIFICADO EL NUMERO DE COLUMNNAS POR CASO ESPECIAL DE REPETICIÓN DE DATOS.

Proceso main
	Definir bidimentionalMatrix, container, n, m, i, j, k, uNum Como Entero;
	m = 3;
	n = 6; //4
	Dimension bidimentionalMatrix[m, n];
	Dimension container[6];
	
	// Asks for the numbers
	Para i=0 Hasta 5 Con Paso 1 Hacer
		Escribir " > Please enter a number to fill out the container. numbers inserted -> [", i+1, "/ 6]";
		Leer container[i];
	FinPara
	
	// Set each position to 0
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			bidimentionalMatrix[i, j] = 0;
		FinPara
	FinPara
	
	// order
	// [Pares]
	// [Impares]
	// [Primos]
	j = 0;
	Para k=0 Hasta 5 Con Paso 1 Hacer
		// pair
		Si container[k] mod 2 == 0 Entonces
			bidimentionalMatrix[0, j] = container[k];
		FinSi
		
		// impairs
		Si container[k] mod 2 <> 0 Entonces
			bidimentionalMatrix[1, j] = container[k];
		FinSi
		
		// cousins
		Si cousinValidation(container[k]) Entonces
			bidimentionalMatrix[2, j] = container[k];
		FinSi
		
		j = j + 1;
	FinPara
	
	// show the matrix
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			Escribir bidimentionalMatrix[i,j],"   ",Sin Saltar;
		FinPara
		Segun i Hacer
			0:
				Escribir "Pair   ", Sin Saltar;
			1:
				Escribir "Impairs   ", Sin Saltar;
			2:
				Escribir "Cousins   ", Sin Saltar;
		FinSegun
		Escribir"";
	FinPara
FinProceso

SubProceso isCousin = cousinValidation(num)
	Definir i, count Como Entero;
	Definir isCousin Como Logico;
	
	count = 0;
	Para i=1 Hasta num Con Paso 1 Hacer
		Si num%i=0 Entonces
			count = count + 1;
		FinSi
	FinPara
	
	Si count == 2 Entonces
		//Escribir "Is a cousin number ", n;
		isCousin = Verdadero;
	SiNo
		//Escribir "Not a cousin number ", n;
		isCousin = Falso;
	FinSi
FinSubProceso
