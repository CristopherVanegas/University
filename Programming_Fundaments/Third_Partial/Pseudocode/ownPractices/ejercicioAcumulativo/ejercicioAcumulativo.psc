// ///////////////////////////////////////// //
//											/
// ----- ESTUDIANTE CRISTOPHER VANEGAS ----- //
//											/
// ///////////////////////////////////////// //


SubProceso randomVals(matrix Por Referencia, m, n)
	Definir i, j Como Entero;
	Para i = 0 Hasta m-1 Con Paso 1 Hacer
		Para j = 0 Hasta n-1 Con Paso 1 Hacer
			matrix[i, j] = Aleatorio(1, 15);
		FinPara
	FinPara
FinSubProceso


SubProceso showMatrix(matrix Por Referencia, m, n)
	Definir i, j Como Entero;
	
	Para i = 0 Hasta m-1 Con Paso 1 Hacer
		Escribir "   |", Sin Saltar;
		Para j = 0 Hasta n-1 Con Paso 1 Hacer
			Si (Longitud(ConvertirATexto(matrix[i, j])) == 1) Entonces
				Escribir "    ", matrix[i, j], "   |", Sin Saltar;

			SiNo
				Escribir "  ", matrix[i, j], "   |", Sin Saltar;
			FinSi
		FinPara
		Escribir "";
	FinPara
FinSubProceso

SubProceso sortMenu(matrix Por Referencia, m, n)
	Definir opt Como Entero;
	
	Escribir "";
	Escribir "Do you want to sort rows or columns?";
	Escribir "[1] Rows";
	Escribir "[2] Columns";
	Leer opt;
	
	Segun opt Hacer
		1:
			// rows
			Escribir "";
			Escribir "";
			Escribir "Rows";
			typeOfSorting(matrix, m, n, "r");
			
		2:
			// columns
			Escribir "";
			Escribir "";
			Escribir "Columns";
			typeOfSorting(matrix, m, n, "c");
			
		De Otro Modo:
			Escribir "Option not found!";
	FinSegun
FinSubProceso

SubProceso typeOfSorting(matrix Por Referencia, m, n, mode)
	Definir opt Como Entero;
	
	Escribir "";
	Escribir "Please select the type of algorythm to sort: ";
	Escribir "[1] Increment Sorting";
	Escribir "[2] Decrement Sorting";
	Leer opt;
	
	Segun opt Hacer
		1:
			Escribir "";
			Escribir "Increment Sorting";
			Escribir "";
			
			incrementSorting(matrix, m, n, mode);
		2:
			Escribir "";
			Escribir "Decrement Sorting";
			Escribir "";
			decrementSorting(matrix, m, n, mode);
			
		De Otro Modo:
			Escribir "Option not found!";
	FinSegun
FinSubProceso


SubProceso incrementSorting(matrix Por Referencia, m, n, mode)
	Definir i, j, k, aux Como Entero;
	
	Si (mode == "r") Entonces
//		Sort Rows
		Para i = 0 Hasta m-1 Con Paso 1 Hacer
			Para j = 0 Hasta n-1 Con Paso 1 Hacer
				Para k = j + 1 Hasta n-1 Con Paso 1 Hacer
					Si (matrix[i, j] > matrix[i, k]) Entonces
						aux = matrix[i, k];	// kepts the value of j + 1
						
						matrix[i, k] = matrix[i, j];
						matrix[i, j] = aux;	// set the value of j + 1 in j
					FinSi
				FinPara
			FinPara
		FinPara
	SiNo
		Si (mode == "c") Entonces
//			Sort Columns
			Para j = 0 Hasta n-1 Con Paso 1 Hacer
				Para i = 0 Hasta m-1 Con Paso 1 Hacer
					Para k = i + 1 Hasta m-1 Con Paso 1 Hacer
						Si (matrix[i, j] > matrix[k, j]) Entonces
							aux = matrix[i, k];	// kepts the value of j + 1
							
							matrix[k, j] = matrix[i, j];
							matrix[i, j] = aux;	// set the value of j + 1 in j
						FinSi
					FinPara
				FinPara
			FinPara
		FinSi
	FinSi
FinSubProceso


SubProceso decrementSorting(matrix Por Referencia, m, n, mode)
	Definir i, j, k, aux Como Entero;
	
	Si (mode == "r") Entonces
//		Sort Rows
		Para i = 0 Hasta m-1 Con Paso 1 Hacer
			Para j = 0 Hasta n-1 Con Paso 1 Hacer
				Para k = j + 1 Hasta n-1 Con Paso 1 Hacer
					Si (matrix[i, j] < matrix[i, k]) Entonces
						aux = matrix[i, k];	// kepts the value of j + 1
						
						matrix[i, k] = matrix[i, j];
						matrix[i, j] = aux;	// set the value of j + 1 in j
					FinSi
				FinPara
			FinPara
		FinPara
	SiNo
		Si (mode == "c") Entonces
//			Sort Columns
			Para j = 0 Hasta n-1 Con Paso 1 Hacer
				Para i = 0 Hasta m-1 Con Paso 1 Hacer
					Para k = i + 1 Hasta m-1 Con Paso 1 Hacer
						Si (matrix[i, j] < matrix[k, j]) Entonces
							aux = matrix[i, k];	// kepts the value of j + 1
							
							matrix[k, j] = matrix[i, j];
							matrix[i, j] = aux;	// set the value of j + 1 in j
						FinSi
					FinPara
				FinPara
			FinPara
		FinSi
	FinSi
FinSubProceso


SubProceso verifySpecialChar(name Por Referencia)
	//	This function verifies if special characters where sent and if so, it's gona ask for a new name!
	Definir i, j Como Entero;
	Definir specialChars Como Caracter;
	Definir isFreeFromSpecialChars Como Logico;
	specialChars = "!#$%&()*+,?./:<=>?@";
	//	isFreeFromSpecialChars = Falso;
	
	Repetir		
		Para i = 0 Hasta Longitud(name)-1 Con Paso 1 Hacer
			Para j = 0 Hasta Longitud(specialChars)-1 Con Paso 1 Hacer
				Si (Subcadena(name, i, i) == Subcadena(specialChars, j, j)) Entonces
					isFreeFromSpecialChars = Falso;
					Limpiar Pantalla;
					// resets the loops to ask again for a new name
					j = Longitud(specialChars)-1;
					i = Longitud(name)-1;
					
					// asks for another name!
					Escribir "Sorry this name has special chars!";
					Escribir "";
					name = setName();
				SiNo
					isFreeFromSpecialChars = Verdadero;
				FinSi
			FinPara
		FinPara
	Hasta Que (isFreeFromSpecialChars == Verdadero)
	Escribir "";
FinSubProceso


Funcion name = setName()
	Definir name, specialChars Como Caracter;
	
	Escribir "HEY! Welcome to these program in which is covered everything from Programming Fundaments - 2nd Semester!";
	Escribir "Please enter your name: ", Sin Saltar;
	Leer name;
	name = Minusculas(name);
	
	verifySpecialChar(name);
FinFuncion


Funcion verif = isRecursivePalindrome(name, invertedName, i, count)
	Definir verif Como Logico;
	Si (Subcadena(name, i, i) == Subcadena(invertedName, i, i)) Y (i < Longitud(name)) Entonces
		verif = isRecursivePalindrome(name, invertedName, i + 1, count + 1);
	SiNo
		Si (Subcadena(name, i, i) <> Subcadena(invertedName, i, i)) Y (i < Longitud(name)) Entonces
			verif = isRecursivePalindrome(name, invertedName, Longitud(name)-1, count);
		FinSi
	FinSi
	
	Si (count == Longitud(name)) Entonces
		verif = Verdadero;
	FinSi
FinFuncion


Funcion v = isPalindrome(name, mode)
	Definir v Como Logico;
	Definir i Como Entero;
	Definir invertedName Como Caracter;
	
	// inverts name
	Para i = Longitud(name)-1 Hasta 0 Con Paso -1 Hacer
		invertedName = Subcadena(name, i, i);
	FinPara
	
	Si (mode == "l") Entonces														// LOOP VERIFICATION
		Para i = 0 Hasta Longitud(name)-1 Con Paso 1 Hacer
			Si (Subcadena(name, i, i) == Subcadena(invertedName, i, i)) Entonces
				v = Verdadero;
			SiNo
				v = Falso;
				i = Longitud(name)-1;
			FinSi
		FinPara
		
	SiNo
		Si (mode == "r") Entonces													// RECURSIVE VERIFICATION
			v = isRecursivePalindrome(name, invertedName, 0, 0);
		FinSi
	FinSi
FinFuncion


SubProceso palindromeMenu(name)
	Definir opt Como Entero;
	Escribir "";
	Escribir "If you want to know if your name is palindrome, you should choose to solve the algorythm with: ";
	Escribir "[1] Loop";
	Escribir "[2] Recursion";
	Leer opt;
	
	Segun opt Hacer
		1:
			Si (isPalindrome(name, "l") == Verdadero) Entonces
				Escribir "Your name is palindrome!";
			SiNo
				Escribir "Your name is not palindrome!";
			FinSi
		2:
			Si (isPalindrome(name, "r") == Verdadero) Entonces
				Escribir "Your name is palindrome!";
			SiNo
				Escribir "Your name is not palindrome!";
			FinSi			
		De Otro Modo:
			Escribir "Option not found!";
	FinSegun
FinSubProceso


Proceso main
	Definir matrix, m, n Como Entero;
	Definir name Como Caracter;
	m = 3;
	n = 4;
	Dimension matrix[m, n];
	
	name = setName();
	palindromeMenu(name);
	randomVals(matrix, m, n);
	Escribir "unsorted matrix";
	showMatrix(matrix, m, n);
	Escribir "";
	Escribir "";
	
	Escribir "sorted matrix";
	sortMenu(matrix, m, n);
	showMatrix(matrix, m, n);
	Escribir "";
	
	Escribir "";
	Escribir "Great! That is all for now ", name, "!";
	Escribir "See u in Object Oriented Programming!";
FinProceso
