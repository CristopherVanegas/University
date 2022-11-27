// ////////////////////////////////////////////// //
// 			  Est. Cristopher Vanegas 		    //
//               Date: Nov 24 2022                //
// ////////////////////////////////////////////// //

SubProceso palindromoWithLoop()
	Definir i, cont Como Entero;
	Definir text, textInverted Como Caracter;
	Leer text;										// lee una palabra ingresada por el user.
	
	text = Minusculas(text);							// convierte a minúsculas.
	
	textInverted = "";								// string nuevo para comprobar es inicializado.
	
	Para i = Longitud(text)-1 Hasta 0 Con Paso -1 Hacer							// bucle para guardar la forma invertida del texto del usuario en textInverted.
		textInverted = Concatenar(textInverted, Subcadena(text, i, i));
	FinPara
	
	Escribir textInverted;							// se imprime el texto invertido.
	
	
	// BLOQUE PARA COMPROBAR QUE SEAN LO MISMO (SEA PALÍNDROMO) //
	cont = 0;
	Para i = 0 Hasta Longitud(text)-1 Con Paso 1 Hacer							// se itera la palabra ingresada por el user.
		Si (Subcadena(text, i, i) == Subcadena(textInverted, i, i)) Entonces		// se verifica si la subcadena text en (i, i) es igual a la subcadena invertida en (i, i).
			cont = cont + 1;														// solo si es así entonces se suma 1 al contador.
		FinSi
	FinPara
	
	
	Si (cont == Longitud(text)) Entonces											// si el contador y la longitud ya sea de text o textInverted son la misma significa que cada
		Escribir "la palabra es palíndroma";										// subcadena era la misma por lo cual es la misma palabra en un sentido u otro.
	SiNo
		Escribir "la palabra no es palíndroma";									// si no entonces no es palíndroma.
	FinSi
FinSubProceso


SubProceso withoutLoop()
	Definir word, wordDivd, wordDivd2, wordDivInverted Como Caracter;
	Definir opt, cont Como Entero;
	
	Repetir
		Escribir "";
		Escribir "Elegir parabra 1 o 2: ";
		Escribir "[1] Palabra 1";
		Escribir "[2] Palabra 2";
		
		Leer opt;
		cont = 0;
		
		Segun opt Hacer
			1:
				word = Minusculas("palindromo");
				Escribir "La palabra que está por default es: ", word;

				Si Subcadena(word, 0, 0) == Subcadena(word, Longitud(word)-1, Longitud(word)-1) Entonces
					cont = cont + 1;
				FinSi
				Si Subcadena(word, 1, 1) == Subcadena(word, Longitud(word)-2, Longitud(word)-2) Entonces
					cont = cont + 1;
				FinSi
				Si Subcadena(word, 2, 2) == Subcadena(word, Longitud(word)-3, Longitud(word)-3) Entonces
					cont = cont + 1;
				FinSi
				Si Subcadena(word, 3, 3) == Subcadena(word, Longitud(word)-4, Longitud(word)-4) Entonces
					cont = cont + 1;
				FinSi
				Si Subcadena(word, 4, 4) == Subcadena(word, Longitud(word)-5, Longitud(word)-5) Entonces
					cont = cont + 1;
				FinSi
				
				Si cont == Longitud(word)/2 Entonces
					Escribir "La palabra ", word, " es palíndroma!";
				SiNo
					Escribir "La palabra ", word, " no es palíndroma!";
				FinSi
				
//				Escribir "contador: ", cont;
				
			2:
				word = Minusculas("anilina");
				Escribir "La palabra que está por default es: ", word;
				
				wordDivd = Subcadena(word, 0, Trunc((Longitud(word))/2)-1);
				wordDivd2 = Concatenar("", Subcadena(word, 2*(Trunc((Longitud(word))/2)-1), Longitud(word)-1));
				
				wordDivInverted = Concatenar(Subcadena(wordDivd2, Longitud(wordDivd2)-1, Longitud(wordDivd2)-1), Subcadena(wordDivd2, Longitud(wordDivd2)-2, Longitud(wordDivd2)-2));
				wordDivInverted = Concatenar(wordDivInverted, Subcadena(wordDivd2, Longitud(wordDivd2)-3, Longitud(wordDivd2)-3));
				Escribir wordDivd, " ", wordDivInverted;
				
				Si wordDivd == wordDivInverted Entonces
					Escribir "La palabra ", word, " es palíndroma!";
				SiNo
					Escribir "La palabra ", word, " no es palíndroma!";
				FinSi
				
			De Otro Modo:
				Escribir "Opción no encontrada!";
		FinSegun
	Hasta Que ((opt == 1) O (opt == 2));
FinSubProceso


Proceso palindromo
	Definir opt Como Entero;
	Escribir "Elegir resolver el algoritmo con bucle o sin bucle: ";
	Escribir "[1] Con Bucle";
	Escribir "[2] Sin Bucle";
	Leer opt;
	
	Segun opt Hacer
		1:
			palindromoWithLoop();	// método para elevar las primeras letras a mayus.
		2:
			// frase definida
			withoutLoop();	// método con una frase estática en la cuál se agregan capital letters.
			
		De Otro Modo:
			Escribir "";
			Escribir "Opción no encontrada!";
	FinSegun
FinProceso
