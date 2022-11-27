SubProceso r = recursiveAddition(n)
	Definir r, num Como Entero;
	
	Si (n >= 1) Entonces
		Escribir "Please enter a value: ";
		Leer num;
		Escribir "Value entered: ", num;
		r = num + recursiveAddition(n-1);
	SiNo
		r = 0;
	FinSi
	
FinSubProceso

Proceso main
	Definir r, n Como Entero;
	Escribir "Please enter the number of values you want to add: ";
	Leer n;
	r = recursiveAddition(n);
	Escribir "The addition of all values is: ", r;
FinProceso
