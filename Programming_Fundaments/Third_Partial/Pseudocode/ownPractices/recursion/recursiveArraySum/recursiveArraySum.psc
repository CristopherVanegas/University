SubProceso fillOutArray(arr, d, i)
	Definir n Como Entero;
	Si (i < d) Entonces					// recursive case
		Escribir "send a number: ";
		Leer n;
		
		arr[i] = n;
		fillOutArray(arr, d, i+1);
	FinSi								// base case, end of recursion
FinSubProceso


SubProceso show(arr, d, i)
	Si (i < d) Entonces					// recursive case
		Escribir arr[i];
		show(arr, d, i+1);
	FinSi								// base case, end of recursion
FinSubProceso


SubProceso rSum = sum(arr, d, i)
	Definir rSum Como Entero;
	Si (i < d) Entonces					// recursive case
		rSum = arr[i] + sum(arr, d, i+1);
	SiNo
//		Escribir "total: ", r;
		rSum = 0;							// base case, end of recursion
	FinSi
FinSubProceso


Proceso main
	Definir arr, d Como Entero;
	d = 6;
	Dimension arr[d];
	fillOutArray(arr, d, 0);
	show(arr, d, 0);
	
//	sum(arr, d, 0);
	Escribir "The sum using recursion is: ", sum(arr, d, 0);
FinProceso
