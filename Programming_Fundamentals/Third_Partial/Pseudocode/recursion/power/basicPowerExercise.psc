SubProceso result = fnPower(base, exponent)
	Definir result Como Entero;
	
	Si (exponent == 0) Entonces								// base case (basically ends the recursion)
		result = 1;
	SiNo													// Recursion case (Calls the recursion function)
		Si (exponent > 0) Entonces
			result = base * fnPower(base, exponent - 1);
		FinSi
	FinSi
FinSubProceso

Proceso main
	Definir base, exponent Como Entero;
	Escribir "Please enter the base: ";
	Leer base;
	Escribir "Please enter the exponent: ";
	Leer exponent;
	
	Escribir "The result of ", base, " to the ", exponent, " power is: ", fnPower(base, exponent);
FinProceso
