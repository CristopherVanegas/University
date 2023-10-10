Proceso main
	Definir f, c, c1, c2, c3, matriz, num Como Entero;
	Dimension matriz[3, 4];
	
	Para f=0 Hasta 2 Con Paso 1 Hacer
		Para c = 0 Hasta 3 Con Paso 1 Hacer
			matriz[f, c] = 0;
		FinPara
	FinPara
	
	c = 0;
	c1 = 0;
	c2 = 0;
	c3 = 0;
	
	Para c = 1 Hasta 6 Hacer
		Escribir " >>> Enter values: ";
		Leer num;
		Si num%2 == 0 Entonces
			matriz[0, c1] = num;
			c1 = c1 + 1;
		SiNo
			Si isCousin(num)<>0 Entonces
				matriz[2, c3]=num;
				c3 = c3 + 1;
			SiNo
				matriz(1, c2) = num;
				c2 = c2 + 1;
			FinSi
		FinSi
	FinPara
	
	Para f = 0 Hasta 2 Con Paso 1 Hacer
		Escribir "";
		Escribir "[" Sin Saltar;
		Para c = 0 Hasta 3 Con Paso 1 Hacer
			Escribir " ", matriz[f, c], " " Sin Saltar;
		FinPara
		Escribir "]" Sin Saltar; 
	FinPara
FinProceso

SubProceso residuo = isCousin(num)
	Definir c, r Como Entero;
	c = 2;
	r = 1;
	
	Mientras c < num Y r <> 0 Hacer
		r = num % c;
		c = c + 1;
	FinMientras
FinSubProceso

	