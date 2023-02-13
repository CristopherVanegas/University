//	FILA B	//

SubProceso letras = letrasAleatorias()
	Definir letras Como Caracter;
	Definir n Como Entero;
	n = Aleatorio(1, 10);
	Segun n Hacer
		1:
			letras = "a";
		2:
			letras = "b";
		3:
			letras = "c";
		4:
			letras = "d";
		5:
			letras = "e";
		6:
			letras = "f";
		7:
			letras = "g";
		8:
			letras = "h";
		9:
			letras = "i";
		10:
			letras = "j";
	FinSegun
FinSubProceso

SubProceso llenarLetras(arr Por Valor, d)
	Definir i Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		arr[i] = letrasAleatorias();
	FinPara
FinSubProceso

SubProceso mostrar(arr, d)
	Definir i Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Escribir "La letra en la posición ", i, " es: ", arr[i];
	FinPara
FinSubProceso

Proceso main
	Definir arr Como Caracter;
	Definir d Como Entero;
	Escribir "Ingrese la dimensión para su array unidimensional: ", Sin Saltar;
	Leer d;
	
	Dimension arr[d];
	
	llenarLetras(arr, d);
	mostrar(arr, d);
FinProceso
