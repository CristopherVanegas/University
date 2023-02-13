SubProceso r = factorialRecursivo(n)
	Definir r Como Entero;
	Si (n >= 1) Entonces
		Escribir "n = ", n, " is higher equal to 1, so enters the function again! -> n * !n-1";
		
		r = n * factorialRecursivo(n-1);						// Returns n * !n-1
	SiNo
		Escribir "Recursion end...";
		r = 1;										// Returns 1
	FinSi
FinSubProceso


SubProceso fact = conBucle(n)
	Definir fact Como Entero;
	fact = 1;
	
	Mientras n > 1 Hacer
		Escribir "fact: ", fact, " multiplied by n: ", n;
		fact = fact * n;
		n = n-1;
	FinMientras
FinSubProceso


Proceso main
	Definir opt, num, r Como Entero;
	Escribir "Welcome to the Factorial program!";
	Escribir "First you need to choose the way yo wanna solve the problem!";
	Repetir
		Escribir "";
		Escribir "[1] With Recursion";
		Escribir "[2] With Loop";
		Leer opt;
		
		Si ((opt <> 1) O (opt <> 2)) Entonces
			Escribir "";
			Escribir "Sorry but you are able to just enter 1 or 2!";
		FinSi
	Hasta Que ((opt == 1) O (opt == 2));
	
	Limpiar Pantalla;
	Escribir "Done! You chose option ", opt;
	Escribir "Now enter a number to get its factorial: ";
	Leer num;
	
	Escribir "";
	Segun opt Hacer
		1:
			// Recursion
			r = factorialRecursivo(num);
			
			Escribir "";
			Escribir "The result is: ", r;
		2:
			// Loop
			r = conBucle(num);
			
			Escribir "";
			Escribir "The result is: ", r;
			
		De Otro Modo:
			Escribir "Option not found!";
	FinSegun
	FinProceso
