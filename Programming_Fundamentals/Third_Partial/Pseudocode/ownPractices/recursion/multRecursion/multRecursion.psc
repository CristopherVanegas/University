// Crear una funci�n recursiva para factorial de n n�mero.

SubProceso solution = factorialR(n)
	Definir solution Como Entero;
	
	Si (n > 0) Entonces
		solution = n * factorialR(n-1);
	SiNo
		solution = 1;
	FinSi
FinSubProceso


Proceso main
	Definir n, r Como Entero;
	Escribir "Ingrese un valor de n veces para m�ltiplicar: ";
	Leer n;
	
	r = factorialR(n);
	Escribir "El factorial de ", n, " es ", r;
FinProceso
