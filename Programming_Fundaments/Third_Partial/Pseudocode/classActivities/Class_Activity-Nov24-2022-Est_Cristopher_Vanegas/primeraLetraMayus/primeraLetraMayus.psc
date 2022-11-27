// ////////////////////////////////////////////// //
// 			  Est. Cristopher Vanegas 		    //
//               Date: Nov 24 2022                //
// ////////////////////////////////////////////// //

SubProceso loopForCapLetters()
	Definir phrase, aux, nPhrase Como Caracter;
	Definir capLetter Como Logico;
	Definir i Como Entero;
	Escribir "Ingrese una frase: ";
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

SubProceso withoutLoopForCapLetters()
	Definir phrase, nPhrase Como Caracter;
	phrase = "hello world";
	Escribir "Frase original: ", phrase;
	nPhrase = "";
	
	// cada parte concatenada de la frase original y elevando las inciales a mayus.
	nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, 0, 0)));
	nPhrase = Concatenar(nPhrase, Minusculas(Subcadena(phrase, 1, 4)));
	nPhrase = Concatenar(nPhrase, Minusculas(Subcadena(phrase, 5, 5)));
	nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, 6, 6)));
	nPhrase = Concatenar(nPhrase, Minusculas(Subcadena(phrase, 7, 10)));	
	Escribir "Cap Letter activados: ", nPhrase;
FinSubProceso


Proceso primeraLetraMayus
	Definir opt Como Entero;
	Escribir "Elegir resolver el algoritmo con bucle o sin bucle: ";
	Escribir "[1] Con Bucle";
	Escribir "[2] Sin Bucle";
	Leer opt;
	
	Segun opt Hacer
		1:
			loopForCapLetters();	// método para elevar las primeras letras a mayus.
		2:
			// frase definida
			withoutLoopForCapLetters();	// método con una frase estática en la cuál se agregan capital letters.
			
		De Otro Modo:
			Escribir "";
			Escribir "Opción no encontrada!";
	FinSegun
FinProceso
