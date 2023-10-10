// ////////////////////////////////////////////// //
// 			  Est. Cristopher Vanegas 		    //
//               Date: Nov 24 2022                //
// ////////////////////////////////////////////// //

Proceso withLoopFirstLetterToMayus
	Definir phrase, aux, nPhrase Como Caracter;
	Definir capLetter Como Logico;
	Definir i Como Entero;
	Escribir "Ingrese una frase: ";
	Escribir ">>> ", Sin Saltar;
	Leer phrase;
	
	nPhrase = "";
	
	
	capLetter = Falso;
	
	
	Para i=0 Hasta Longitud(phrase)-1 Con Paso 1 Hacer
		
		// para la letra inicial de la frase
		Si i == 0 Y Subcadena(phrase, i, i) <> " " Entonces
			nPhrase = Concatenar(nPhrase, Mayusculas(Subcadena(phrase, i, i)));
			
		SiNo
			// si el mayus está activado lo concatena
			Si capLetter == Verdadero Entonces
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
	
	Escribir nPhrase;
FinProceso
