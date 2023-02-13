// ////////////////////////////////////////////// //
// 			  Est. Cristopher Vanegas 		    //
//               Date: Nov 24 2022                //
// ////////////////////////////////////////////// //

SubProceso loopForCapLetters()
	Definir phrase, aux, nPhrase Como Caracter;
	Definir capLetter Como Logico;
	Definir i Como Entero;
	Escribir "Enter a phrase: ";
	Escribir ">>> ", Sin Saltar;
	Leer phrase;							// lee lo que ingresa el user.
	
	phrase = Minusculas(phrase);			// convierte en minuscula la frase que ingresó el user.
	nPhrase = "";						// nueva frase a partir de la que se ingresó el user.
	
	
	capLetter = Falso;					// señal para activar el mayus en los condicionales.
	
	
	Para i=0 Hasta Longitud(phrase)-1 Con Paso 1 Hacer
		// para la letra inicial de la frase
		Si i == 0 Y Subcadena(phrase, i, i) <> " " Entonces		// si es la primera letra de toda la frase entonces se convertirá en mayus.
			nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, i, i)));
			
		SiNo
			// si el mayus está activado lo concatena
			Si (capLetter == Verdadero) Entonces					// si la señal está activa se concatenará la subcadena en mayus.
				nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, i, i)));
				capLetter = Falso;
				
			SiNo
				// para verificar si el caracter que le sigue al espacio es letra
				Si (Subcadena(phrase, i, i) == " ") Y (Subcadena(phrase, i+1, i+1) <> " ") Entonces
					capLetter = Verdadero;	// activa el mayus
					nPhrase = Concatenar(nPhrase, Subcadena(phrase, i, i));
				SiNo
					nPhrase = Concatenar(nPhrase, Subcadena(phrase, i, i));
				FinSi
			FinSi	
		FinSi
	FinPara
	
	Escribir nPhrase;	// escribe la nueva frase con mayúsculas cada letra.
FinSubProceso

SubProceso nP = withoutLoopForCapLetters(nP Por Referencia, p Por Referencia, longitudP, i) 
	Si i < longitudP Entonces
		Si i == 0 Y Subcadena(p, i, i) <> " " Entonces
			nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
		SiNo
			Si Subcadena(p, i-1, i-1) == " " Y Subcadena(p, i, i) <> " " Y Subcadena(p, i+1, i+1) <> " " Entonces
				nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
			SiNo
				Si Subcadena(p, i-1, i-1) == " " Y Subcadena(p, i, i) <> " " Y Subcadena(p, i+1, i+1) == " " Entonces
					nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
				SiNo
					nP = Concatenar(nP, Minusculas(Subcadena(p, i, i)));
				FinSi
			FinSi
		FinSi
		
		i =  i + 1;
		np = withoutLoopForCapLetters(nP, p, longitudP, i);
	FinSi
FinSubProceso

Proceso primeraLetraMayus
	Definir opt Como Entero;
	Escribir "Choose between solving the algorythm using a loop or not (recursion): ";
	Escribir "[1] With Loop";
	Escribir "[2] Without Loop (Recursion)";
	Leer opt;
	
	Segun opt Hacer
		1:
			Escribir "";
			loopForCapLetters();	// método para elevar las primeras letras a mayus.
		2:
			Definir p, nP Como Caracter;
			Escribir "";
			Escribir "Please enter a phrase you wanna add Cap Letters: ", Sin Saltar;
			Leer p;
			//	p = " hello world";
			nP = "";
			nP = withoutLoopForCapLetters(nP, p, Longitud(p), 0);
			
			Escribir "Original Phrase: ", p;
			Escribir "Phrase with cap letters: ", nP;
		De Otro Modo:
			Escribir "";
			Escribir "Opción no encontrada!";
	FinSegun
FinProceso
