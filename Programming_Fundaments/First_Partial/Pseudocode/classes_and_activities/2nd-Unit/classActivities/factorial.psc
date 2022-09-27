// Est. Cristopher Vanegas
Algoritmo factorial
	Definir numToFactorial, i, resultado Como Entero;
	Escribir "Ingrese un número para factorar: ";
	Leer numToFactorial;
	
	resultado = 1;
	Para i = 1 Hasta numToFactorial Con Paso 1 Hacer
		resultado = resultado * i;
	FinPara
	
	Escribir "Resultado: " , resultado;
FinAlgoritmo
