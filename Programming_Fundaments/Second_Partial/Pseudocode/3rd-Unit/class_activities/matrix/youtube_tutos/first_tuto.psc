// fuente: https://www.youtube.com/watch?v=1VShvozLXvw&ab_channel=DiloenTutosPc

Proceso main
	cousinValidation();
FinProceso

SubProceso isCousin = cousinValidation(num)
	Definir i, count, num Como Entero;
	Definir isCousin Como Logico;

	Escribir " > Please enter a number: ";
	Leer num;
	
	count = 0;
	Para i=1 Hasta num Con Paso 1 Hacer
		Si num%i=0 Entonces
			count = count + 1;
		FinSi
	FinPara
	
	Si count == 2 Entonces
		Escribir "Is a cousin number ", num;
	SiNo
		Escribir "Not a cousin number ", num;
	FinSi
FinSubProceso
	