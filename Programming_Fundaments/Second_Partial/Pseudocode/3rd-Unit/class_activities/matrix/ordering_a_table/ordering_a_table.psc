// Crear una matrix de 3x4 -> Listo
// Llenarlas con 0 -> Listo
// Pedir 6 numeros al user -> Listo
// Validar si es par / impar o primo

// Llenar las filas de la siguiente manera
// [Pares]
// [Impares]
// [Primos]

// Trabajo Individual.
// Est. Cristopher Vanegas.
// NOTA: MODIFICADO EL NUMERO DE COLUMNNAS POR CASO ESPECIAL DE REPETICIÓN DE DATOS.

Proceso main
	Definir bidimentionalMatrix, m, n Como Entero;
	
	m = 3;	// initializing rows
	n = 6;	// initializing columns
	Dimension bidimentionalMatrix[m, n];					// Creates the matrix
	
	matrixOfZeros(bidimentionalMatrix, m, n);				// Sets each position to 0
	askForAndSetToTheTable(bidimentionalMatrix, m, n);		// Asks for the numbers and evaluate at the same time
	sortingMenu(bidimentionalMatrix, n);											// Order the Matrix
	showTheMatrix(bidimentionalMatrix, m, n);				// Shows the matrix
FinProceso

SubProceso showTheMatrix(matrix, m, n)
	Definir i, j Como Entero;
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			Escribir matrix[i,j],"   ",Sin Saltar;
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
FinSubProceso


SubProceso sortingMenu(matrix, n)
	Definir opt Como Entero;
	
	Escribir " > Please choose the way you want to sort the data in the table: ";
	Escribir " [1] Increasing Sorting";
	Escribir " [2] Decreasing Sorting";
	Escribir "";
	Leer opt;
	
	Segun opt Hacer
		1:
			increasingMatrixOrder(matrix, n);
		2:
			decreasingMatrixOrder(matrix, n);
			
		De Otro Modo:
			Escribir "404 Option Not Found!";
			Escribir "End of Program...";
			Escribir "";
	FinSegun
	
FinSubProceso

SubProceso matrixOfZeros(matrix, m, n)
	Definir i, j Como Entero;
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			matrix[i, j] = 0;
		FinPara
	FinPara
FinSubProceso

SubProceso askForAndSetToTheTable(matrix, m, n)
	Definir i, j, uNum, pair_c, impair_c, cousin_c Como Entero;
	pair_c = 0;
	impair_c = 0;
	cousin_c = 0;
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Escribir " > Please enter a number, numbers inserted -> [", i+1, "/", n, "]";
		Leer uNum;
		Escribir "";
		
		// pairs
		Si uNum mod 2 == 0 Entonces
			pairs(matrix, uNum, pair_c);
			pair_c = pair_c + 1;
		FinSi
	
		
		// impairs
		Si uNum mod 2 <> 0 Entonces
			impairs(matrix, uNum, impair_c);
			impair_c = impair_c + 1;
		FinSi
		
		// cousins
		Si cousinValidation(uNum) Entonces
			cousins(matrix, uNum, cousin_c);
			cousin_c = cousin_c + 1;	
		FinSi
		
	FinPara
FinSubProceso

SubProceso pairs(matrix, num, column)
	matrix[0, column] = num;
FinSubProceso

SubProceso impairs(matrix, num, column)
	matrix[1, column] = num;
FinSubProceso

SubProceso cousins(matrix, num, column)
	matrix[2, column] = num;
FinSubProceso

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

SubProceso increasingMatrixOrder(matrix, n)
	Definir m, i, j Como Entero;
	Para i = 0 Hasta n-1 Con Paso 1 Hacer
		Para j = i+1 Hasta n-1 Con Paso 1 Hacer
			Si matrix[0, i] > matrix[0, j] Y matrix[0, j] <> 0 Entonces
				m = matrix[0, i];
				
				matrix[0, i] = matrix[0, j];
				matrix[0, j] = m;
			Finsi
			Si matrix[1, i] > matrix[1, j] Y matrix[1, j] <> 0 Entonces
				m = matrix[1, i];
				
				matrix[1, i] = matrix[1, j];
				matrix[1, j] = m;
			Finsi
			Si matrix[2, i] > matrix[2, j] Y matrix[2, j] <> 0 Entonces
				
				m = matrix[2, i];
				matrix[2, i] = matrix[2, j];
				matrix[2, j] = m;
			Finsi
		FinPara
	FinPara
FinSubProceso

SubProceso decreasingMatrixOrder(matrix, n)
	Definir m, i, j Como Entero;
	Para i = 0 Hasta n-1 Con Paso 1 Hacer
		Para j = i+1 Hasta n-1 Con Paso 1 Hacer
			Si matrix[0, i] < matrix[0, j] Y matrix[0, j] <> 0 Entonces
				m = matrix[0, i];
				 
				matrix[0, i] = matrix[0, j];
				matrix[0, j] = m;
			Finsi
			Si matrix[1, i] < matrix[1, j] Y matrix[1, j] <> 0 Entonces
				m = matrix[1, i];
				
				matrix[1, i] = matrix[1, j];
				matrix[1, j] = m;
			Finsi
			Si matrix[2, i] < matrix[2, j] Y matrix[2, j] <> 0 Entonces
				m = matrix[2, i];
				
				matrix[2, i] = matrix[2, j];
				matrix[2, j] = m;
			Finsi
		FinPara
	FinPara
FinSubProceso
