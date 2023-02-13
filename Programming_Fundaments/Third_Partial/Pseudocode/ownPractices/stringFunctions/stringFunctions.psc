SubProceso funcionesConString()
	Definir opt Como Entero;
	Escribir "Bienvenido al programa de funciones para String!";
	EScribir "Por favor ingrese una opción para elegir una función de Caracteres y obtener su información: ";
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
			Escribir "Función Longitud!";
			Leer text;
			Escribir "La longitud de ", text, " es ", Longitud(text);
			
		2:
			// Mayúsculas
			Escribir "Función Mayúsculas!";
			Leer text;
			Escribir "La versión de mayúsculas de ", text, " es ", Mayusculas(text);
		3:
			// Minúsculas
			Escribir "Función Minúsculas!";
			Leer text;
			Escribir "La versión de minúsculas de ", text, " es ", Minusculas(text);
		
		4:
			// SubCadena
			Escribir "Función SubCadena!";
			Leer text;
			Escribir "La versión de acortada de ", text, " es ", Subcadena(text, 0, trunc((Longitud(text)/2)-1));
			
		5:
			// Concatenar
			Escribir "Función Concatenar!";
			Escribir "Leer cadena uno: ", Sin Saltar;
			Leer string1;
			Escribir "Leer cadena dos: ", Sin Saltar;
			Leer string2;
			Escribir "La versión concatenada de lo que se envió es de ", Concatenar(string1, string2);
			
		6:
			Definir string Como Caracter;
			Definir int Como Entero;
			string = "55";
			
			// Convertir Cadena o String a Número
			Escribir "Función Convertir Cadena o String a Número!";
			
			int = ConvertirANumero(string);
			Escribir "La conversión de String a Entero es ", int;
		7:
			Definir string Como Caracter;
			Definir int Como Entero;
			
			// Convertir un Número a String o Cadena
			Escribir "Función Convertir Número a String o Cadena!";
			int = 50;
			string = ConvertirATexto(int);
			Escribir "La conversión de Entero a Texto es ", string;
		
		De Otro Modo:
			Escribir "Opción no encontrada!";
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
