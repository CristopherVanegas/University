// Est. Cristopher Vanegas
Algoritmo sumaDeNumerosBucleRepetir
	Definir lim, num, resultado Como Entero;
	Escribir "Ingresar los n�meros que desea sumar: ";
	Leer lim;
	
	resultado = 0;
	Repetir
		Escribir "Ingresar un n�mero para sumar con el resultado total, el n�mero no puede ser 0: ";
		Leer num;
		
		Si num <> 0 Entonces
			resultado = resultado+ num;
		SiNo
			Escribir "No se puede ingresar 0!";
			lim = 0;
		FinSi
		
		lim = lim - 1;
	Hasta Que lim <= 0
	
	Escribir "El resultado es: ", resultado;
FinAlgoritmo
