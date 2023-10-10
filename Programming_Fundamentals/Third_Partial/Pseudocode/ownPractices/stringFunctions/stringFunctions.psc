SubProceso funcionesConString()
	Definir opt Como Entero;
	Escribir "Bienvenido al programa de funciones para String!";
	EScribir "Por favor ingrese una opci�n para elegir una funci�n de Caracteres y obtener su informaci�n: ";
	Escribir "[1] Longitud(x);";
	Escribir "[2] Mayuculas(x);";
	Escribir "[3] Minusculas(x);";
	Escribir "[4] Subcadena(x, inicio, fin);";
	Escribir "[5] Concatenar(x, y);";
	Escribir "[6] ConvertirANumero(cadena);";
	Escribir "[7] ConvertirATexto(entero);";
	Leer opt;
	
	
	Definir text, string1, string2 Como Caracter;
	Segun opt Hacer
		1:
			// Longitud
			Escribir "Funci�n Longitud!";
			Leer text;
			Escribir "La longitud de ", text, " es ", Longitud(text);
			
		2:
			// May�sculas
			Escribir "Funci�n May�sculas!";
			Leer text;
			Escribir "La versi�n de may�sculas de ", text, " es ", Mayusculas(text);
		3:
			// Min�sculas
			Escribir "Funci�n Min�sculas!";
			Leer text;
			Escribir "La versi�n de min�sculas de ", text, " es ", Minusculas(text);
		
		4:
			// SubCadena
			Escribir "Funci�n SubCadena!";
			Leer text;
			Escribir "La versi�n de acortada de ", text, " es ", Subcadena(text, 0, trunc((Longitud(text)/2)-1));
			
		5:
			// Concatenar
			Escribir "Funci�n Concatenar!";
			Escribir "Leer cadena uno: ", Sin Saltar;
			Leer string1;
			Escribir "Leer cadena dos: ", Sin Saltar;
			Leer string2;
			Escribir "La versi�n concatenada de lo que se envi� es de ", Concatenar(string1, string2);
			
		6:
			Definir string Como Caracter;
			Definir int Como Entero;
			string = "55";
			
			// Convertir Cadena o String a N�mero
			Escribir "Funci�n Convertir Cadena o String a N�mero!";
			
			int = ConvertirANumero(string);
			Escribir "La conversi�n de String a Entero es ", int;
		7:
			Definir string Como Caracter;
			Definir int Como Entero;
			
			// Convertir un N�mero a String o Cadena
			Escribir "Funci�n Convertir N�mero a String o Cadena!";
			int = 50;
			string = ConvertirATexto(int);
			Escribir "La conversi�n de Entero a Texto es ", string;
		
		De Otro Modo:
			Escribir "Opci�n no encontrada!";
	FinSegun
	Escribir "";
FinSubProceso

Proceso main
	Definir answer Como Entero;
	Repetir
		funcionesConString();
		
		Repetir
			Escribir "";
			Escribir "Desea continuar probando otras funciones?";
			Escribir "[1] Si";
			Escribir "[2] No";
			Leer answer;
			
			Limpiar Pantalla;
		Hasta Que (answer == 1 O answer == 2);
		
		Si (answer == 2) Entonces
			Escribir "";
			Escribir "Listo! Programa terminado...";
		FinSi
	Hasta Que (answer == 2);
	
FinProceso
