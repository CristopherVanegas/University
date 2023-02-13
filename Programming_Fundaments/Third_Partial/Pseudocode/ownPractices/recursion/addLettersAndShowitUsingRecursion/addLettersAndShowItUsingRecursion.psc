// 1. Crear un programa que pida un numero y se incerten letras del abecedario
// aleatorias en un array.
// 2. Para eso iterar sin bucle (o sea usar una funcion recursiva).
// 3. Usar subprocesos y funciones en lo posible.


Funcion l = randomLetter()
	Definir l, abecedario Como Caracter;
	Definir a Como Entero;
	abecedario = "abcdefghijklmnopqrstuvwxyz";
	a = Aleatorio(0, Longitud(abecedario)-1);
	
	l = Mayusculas(Subcadena(abecedario, a, a));					// returns a letter
FinFuncion


SubProceso recursion(arr, i, d)
	Si (i < d) Entonces							// recursion case & base case
		arr[i] = randomLetter();
		recursion(arr, i+1, d);
		Escribir "Position ", i, ": ", arr[i];
	FinSi
FinSubProceso


Proceso main
	Definir arr Como Caracter;
	Definir d Como Entero;
	Escribir "How many vocals do you want? ", Sin Saltar; Leer d;	// d = 5
	Dimension arr[d];
	
	recursion(arr, 0, d);
FinProceso
