Algoritmo condicionalSegun
	Definir  valor Como Entero;
	valor = 0;
	Escribir "Ingrese un n�mero que represente el d�a de la semana (1 - 7):";
	Leer valor;
	Segun valor hacer
		1:
			Escribir "Es Lunes!";
		2:
			Escribir "Es Martes!";
		3:
			Escribir "Es Mi�rcoles!";
		4:
			Escribir "Es Jueves!";
		5:
			Escribir "Es Viernes!";
		6:
			Escribir "Es S�bado!";
		7:
			Escribir "Es Domingo!";
		De Otro Modo:	// Default case
			Escribir "No es ning�n n�mero v�lido!";
	FinSegun
FinAlgoritmo
