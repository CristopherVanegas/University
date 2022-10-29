// Crear una matrix de 3x4 -> Listo
// Llenarlas con 0 -> Listo
// Pedir 6 numeros al user -> Listo
// Validar si es par / impar o primo

// Llenar las filas de la siguiente manera
// [Pares]
// [Impares]
// [Primos]

// Trabajo Grupal.
// Est. Cristopher Vanegas && Est. Joaquin Mantilla && Est. Valeria Albán.
// NOTA: MODIFICADO EL NUMERO DE COLUMNNAS POR CASO ESPECIAL DE REPETICIÓN DE DATOS.

Proceso ordering_values
	Definir bidimentionalMatrix, m, n, i, j, pair_c, impair_c, cousin_c, uNum Como Entero;
	// initializing dimentions
	m = 3;
	n = 6;
	
	// Creates the matrix and set each position to 0
	Dimension bidimentionalMatrix[m, n];
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			bidimentionalMatrix[i, j] = 0;
		FinPara
	FinPara
	
	// Asks for the numbers and evaluate at the same time
	pair_c = 0;
	impair_c = 0;
	cousin_c = 0;
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Escribir " > Please enter a number, numbers inserted -> [", i+1, "/", n, "]";
		Leer uNum;
		
		// pairs
		Si uNum mod 2 == 0 Entonces
			bidimentionalMatrix[0, pair_c] = uNum;
			pair_c = pair_c + 1;
		FinSi
		
		// impairs
		Si uNum mod 2 <> 0 Entonces
			bidimentionalMatrix[1, impair_c] = uNum;
			impair_c = impair_c + 1;
		FinSi
		
		// cousins
		Si cousinValidation(uNum) Entonces
			bidimentionalMatrix[2, cousin_c] = uNum;
			cousin_c = cousin_c + 1;
		FinSi
	FinPara
	
	// show the matrix
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			Escribir bidimentionalMatrix[i,j],"   ",Sin Saltar;
		FinPara
		Segun i Hacer
			0:
				Escribir "[Pair] ", Sin Saltar;
			1:
				Escribir "[Impairs] ", Sin Saltar;
			2:
				Escribir "[Cousins] ", Sin Saltar;
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
