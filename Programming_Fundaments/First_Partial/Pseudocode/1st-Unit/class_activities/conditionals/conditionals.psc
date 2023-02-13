Algoritmo conditional
	Definir valor Como Entero;
	valor = 0;
	Escribir "Escribir valor a evaluar";
	Leer valor;
	// <> == != OR O AND Y || &&
	Si (valor > 1) && (valor < 6) Entonces
		Escribir "El número es mayor a 1 y menor a 6, número: ", valor;
	SiNo
		Escribir "El número no se encuentra en el rango de [2, 5]";
	finSi
FinAlgoritmo
