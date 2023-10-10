// 1. Crear un programa que pida un numero y se incerten vocales
// aleatorias en un array.
// 2. Para eso iterar sin bucle (o sea usar una funcion recursiva).
// 3. Usar subprocesos y funciones en lo posible.


Funcion v = randomVocals()
	Definir v Como Caracter;
	Definir opt Como Entero;
	opt = Aleatorio(1, 5);
	Segun opt Hacer
		1:
			v = "A";
		2:
			v = "E";
		3:
			v = "I";
		4:
			v = "O";
		5:
			v = "U";
	FinSegun
FinFuncion


SubProceso recursion(arr, i, d)
	Si (i < d) Entonces							// recursion case & base case
		arr[i] = randomVocals();
		recursion(arr, i+1, d);
		Escribir "Position ", i, ": ", arr[i];
	FinSi
FinSubProceso


Proceso main
	Definir arr Como Caracter;
	Definir d Como Entero;
	Escribir "How many vocals do you want? "; Leer d;
	Dimension arr[d];
	recursion(arr, 0, d);
FinProceso
