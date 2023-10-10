// Create a main program that prints in console the value that sumOfNum() returns
Funcion result = sumOfNum(num1, num2)
	Definir suma Como Entero;
	result = num1 + num2;
FinFuncion

Algoritmo main
	Definir num1, num2, result Como Entero;
	Escribir "Please enter 1st number: ";
	Leer num1;
	Escribir "Please enter 2nd number: ";
	Leer num2;
	
	result = sumOfNum(num1, num2);
	Escribir " [+] The result of " num1, " + ", num2, " is ", result;
FinAlgoritmo
