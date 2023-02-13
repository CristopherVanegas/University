Proceso isCousin
	Definir bidimentionalMatrix, container, n, m, i, j, uNum, x, residuo Como Entero;
	m = 3;
	n = 4;
	Dimension bidimentionalMatrix[m, n];
	Dimension container[6];
	
	// Asks for the numbers
	Para i=0 Hasta 5 Con Paso 1 Hacer
		Escribir " > Please enter a number to fill out the container. numbers inserted -> [", i+1, "/ 6]";
		Leer container[i];
	FinPara
	
	
	Para i=0 Hasta 5 Con Paso 1 Hacer
		
		Si container[i] == 0 O container[i] == 1 O container[i] == 4 Entonces
			Escribir " >>> The number ", container[i], " is NOT a COUSIN number. (special case)";
		SiNo
			
			x = 2;
			residuo = 1;
			Mientras x>container[i] Y residuo<>0 Hacer
				Si container[i] % x == 0 Entonces
					Escribir " >>> The number ", container[i], " is NOT a COUSIN number.";	
				FinSi
				residuo = container[i] % x;
				x = x + 1;
				Escribir " >>> The number ", container[i], " IS a COUSIN number.";
			FinMientras
			
//			Para x=2 Hasta container[i]-1 Con Paso 1 Hacer
//				Si container[i] % x == 0 Entonces
//					Escribir " >>> The number ", container[i], " is NOT a COUSIN number.";	
//				FinSi
//			FinPara
//			Escribir " >>> The number ", container[i], " IS a COUSIN number.";
		FinSi
		
	FinPara
FinProceso
