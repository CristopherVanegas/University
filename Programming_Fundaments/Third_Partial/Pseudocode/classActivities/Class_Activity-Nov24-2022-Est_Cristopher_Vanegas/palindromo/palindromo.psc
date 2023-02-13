// ////////////////////////////////////////////// //
// 			  Est. Cristopher Vanegas			  //
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


SubProceso rString(p Por Valor, rP Por Referencia, i)
	Si (i >= 0) Entonces
		rP = Concatenar(rP, Subcadena(p, i, i));
		rString(p, rP, i-1);
	FinSi
FinSubProceso


SubAlgoritmo palindromoR(p Por Valor, rP Por Valor, i, c)
	Si (i >= 0) Entonces
		Si (Subcadena(p, i, i) == Subcadena(rP, i, i)) Entonces
			c = c + 1;
		FinSi
		
		Si (i == 0) Entonces
			Si (c == Longitud(p)) Entonces
				Escribir "La palabra ES palíndroma!";
			SiNo
				Escribir "La palabra NO es palíndroma!";
			FinSi
		FinSi
		
		palindromoR(p, rP, i-1, c);
	FinSi
FinSubAlgoritmo


Proceso palindromo
	Definir opt Como Entero;
	Escribir "Elegir resolver el algoritmo con bucle o sin bucle: ";
	Escribir "[1] Con Bucle";
	Escribir "[2] Sin Bucle";
	Leer opt;
	
	Segun opt Hacer
		1:
			palindromoWithLoop();							// método para elevar las primeras letras a mayus.
		2:
			Definir p, rP Como Caracter;
			Escribir "Ingrese un string: ";
			Leer p;
			
			rP = "";
			rString(p, rP, Longitud(p)-1);					// método con una frase estática en la cuál se agregan capital letters.
			Escribir "Frase invertida: ", rP;
			palindromoR(p, rP, Longitud(p)-1, 0);			// palindromo(fraseOriginal, fraseInvertida, longitud-1, 0 contadorParaVerificarSiEsPalindromo).
			
		De Otro Modo:
			Escribir "";
			Escribir "Opción no encontrada!";
	FinSegun
FinProceso
