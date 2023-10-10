// Est. Cristopher Vanegas
Algoritmo main
	pairOrNotTenFirstNumbers();
FinAlgoritmo

SubAlgoritmo pairOrNotTenFirstNumbers()
	Definir numArr, i Como Entero;
	Dimension numArr[10];
	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		numArr[i] = Aleatorio(0, 100);
	FinPara
	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		Si (numArr[i] % 2 == 0) Entonces
			Escribir " > ", numArr[i], " It is pair!";
		SiNo
			Escribir " > ", numArr[i], " It is not pair!";
		FinSi
	FinPara
	
	Escribir " > The complete array using random ints is: ";
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir " > Index value for array: ", numArr[i];
	FinPara
FinSubAlgoritmo
