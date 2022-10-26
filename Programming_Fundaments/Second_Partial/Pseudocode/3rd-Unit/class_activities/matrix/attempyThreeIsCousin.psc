SubProceso esPrimo = verificarPrimo(num)
	Definir x Como Entero;
	Definir esPrimo Como Logico;
	Si (num == 0 | num == 1 | num == 4) Entonces
		esPrimo = Falso;
	FinSi
	
	x = 2;
	Mientras x<(num/2) Hacer
		Si num % x == 0 Entonces
			esPrimo = Falso;
		FinSi
		
		x = x + 1;
	FinMientras
	esPrimo = Verdadero;
	
FinSubProceso


Proceso main
	Definir numsParaProbar, i Como Entero;
	Dimension numsParaProbar[5];
	numsParaProbar[0] = 1;
	numsParaProbar[1] = 2;
	numsParaProbar[2] = 50;
	numsParaProbar[3] = 51;
	numsParaProbar[4] = 3;
	
	Para i = 0 Hasta 4 Con Paso 1 Hacer
		Escribir "El número ", numsParaProbar[i], " es primo: ", verificarPrimo(numsParaProbar[i]);
	FinPara
FinProceso


