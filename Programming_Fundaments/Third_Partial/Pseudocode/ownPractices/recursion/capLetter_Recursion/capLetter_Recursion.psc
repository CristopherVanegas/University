// 1. Elevar cada letra de una palabra de una frase enviada por el user
// a mayúsculas
// 2. UTILIZAR SUBPROCESOS o FUNCIONES
// 3. ITERAR con RECURSION
// 4. Imprimir la frase

//" hola mundo";
//" Hola Mundo";
//"verdadero y verdaro = verdaro"

SubProceso capLettersRecursive(phrase, i, d, nPhrase Por Referencia)
	Si (i < d) Entonces																				// recursive case & base case
		Si (i == 0 Y Subcadena(phrase, 0, 0) <> " ") Entonces											// if at the beginnning there is not a space
			nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, 0, 0)));
		SiNo
			Si (Subcadena(phrase, i-1, i-1) == " ") Y (Subcadena(phrase, i, i) <> " ") Entonces		// if a word starts after a space " " after 0, 0 index position
				nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, i, i)));
			SiNo
				nPhrase = Concatenar(nPhrase, Subcadena(phrase, i, i));								// if the letter it's not in the beggining of the word it's not gonna be a cap letter
			FinSi
		FinSi
		
		capLettersRecursive(phrase, i+1, d, nPhrase);
	FinSi
	// end of recursion
FinSubProceso


Proceso main
	Definir phrase, nPhrase Como Caracter;
	Definir length Como Entero;
	nPhrase = "";
	Escribir "Please enter a phrase: ", Sin Saltar; Leer phrase; length = Longitud(phrase);
	Escribir "";
	Escribir " >>> Phrase without cap letters: ", phrase;
	
	capLettersRecursive(phrase, 0, length, nPhrase);
	Escribir " >>> Phrase with cap letters: ", nPhrase;
FinProceso
