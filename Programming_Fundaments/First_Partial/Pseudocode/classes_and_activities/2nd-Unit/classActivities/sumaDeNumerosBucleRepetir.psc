// Est. Cristopher Vanegas
Algoritmo sumaDeNumerosBucleRepetir
	Definir contador, lim, num, resultado Como Entero;
	resultado = 0;
	Escribir "Ingresar los n�meros que desea ingresar: ";
	Leer lim;
	
	contador = 0;
	Repetir
		Escribir "Ingresar un n�mero para sumar con el resultado total, el n�mero no puede ser 0: ";
		Leer num;
		
		Si num <> 0 Entonces
			resultado = resultado+ num;
		SiNo
			Escribir "No se puede ingresar 0!";
			contador = lim;
			
		FinSi
		contador = contador + 1;
	Hasta Que contador >= lim
	Escribir "El resultado es: ", resultado;
FinAlgoritmo
