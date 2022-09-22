Algoritmo condicionalSegun
	Definir  valor Como Entero;
	valor = 0;
	Escribir "Ingrese un número que represente el día de la semana (1 - 7):";
	Leer valor;
	Segun valor hacer
		1:
			Escribir "Es Lunes!";
		2:
			Escribir "Es Martes!";
		3:
			Escribir "Es Miércoles!";
		4:
			Escribir "Es Jueves!";
		5:
			Escribir "Es Viernes!";
		6:
			Escribir "Es Sábado!";
		7:
			Escribir "Es Domingo!";
		De Otro Modo:	// Default case
			Escribir "No es ningún número válido!";
	FinSegun
FinAlgoritmo
