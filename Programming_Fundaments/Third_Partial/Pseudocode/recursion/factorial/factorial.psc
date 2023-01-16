SubProceso r = factorial ( n )
	Definir r Como Entero;
	r = 1;
	Si (n > 1) Entonces					// Caso factorial
		r = n * factorial( n - 1 );
	SiNo								// Caso base
		r = 1;
	FinSi
FinSubProceso

Proceso main
	Definir n Como Entero;
	Escribir "Please enter a number: ";
	Leer n;
	
	Escribir "The factorial of ", n, " is: ", factorial( n );
FinProceso
