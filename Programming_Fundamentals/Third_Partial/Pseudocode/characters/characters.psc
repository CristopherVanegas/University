Proceso main
	charFunctions();
FinProceso

SubAlgoritmo charFunctions
	Definir word Como Cadena;
	Definir size, opt Como Entero;
	
	word = "Hello";
	
	Escribir "Welcome to the STRING script!";
	Escribir "Please enter 1, 2 or 3 for";
	Escribir " [1] String length";
	Escribir " [2] Looping a String";
	Escribir " [3] Using Sub String to get first character";
	Leer opt;
	
	Segun opt Hacer
		1:
			// length
			lengthStr(word);
			
		2:
			// looping the string
			loopingStr(word);
			
		3:
			// sub string for first position
			subString(word);
			
			
		De Otro Modo:
			Escribir "Error 404 option not found!";
	FinSegun
FinSubAlgoritmo

SubAlgoritmo lengthStr(str)
	Definir size Como Entero;
	size = Longitud(str);
	Escribir "The length of ", str, " is ", size, " characters.";
FinSubAlgoritmo

SubAlgoritmo subString(str)
	Definir subStr Como Caracter;
	subStr = Subcadena(str, 0, 0);	// To extract the first position.
	Escribir "The Sub-String from 0 to 0 of ", str, " is ", subStr;
FinSubAlgoritmo

SubAlgoritmo loopingStr(str)
	Definir i Como Entero;
	Definir subStr Como Caracter;
	
	Escribir "Looping String...";
	Para i=0 Hasta Longitud(str)-1 Con Paso 1 Hacer
		subStr = Subcadena(str, i, i);
		Escribir subStr;
	FinPara
FinSubAlgoritmo
	