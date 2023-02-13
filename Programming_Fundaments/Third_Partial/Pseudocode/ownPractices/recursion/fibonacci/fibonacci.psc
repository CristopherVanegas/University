SubProceso fibonacci(arr, d, i)
	Si (i == 0) Entonces						// returns the first value (0) of sequence
		arr[i] = 0;
		fibonacci(arr, d, i+1);
	SiNo
		Si (i == 1) Entonces					// returns the second value (1) of sequence
			arr[i] = 1;
			fibonacci(arr, d, i+1);
		FinSi
	FinSi
	
	Si (i > 1) Y (i < d) Entonces			// recursion case
		arr[i] = arr[i-1] + arr[i-2];
		fibonacci(arr, d, i+1);
	FinSi									// base case (if any of these conditions is fulfilled it's not gonna call again the recursive func)
	
FinSubProceso


SubProceso show(arr, d)
	Definir i Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Escribir arr[i];
	FinPara
FinSubProceso


Proceso main
	Definir n, arr, d Como Entero;
	leer n;
	d = n;
	Dimension arr[d];
	
	fibonacci(arr, d, 0);
	show(arr, d);
FinProceso
