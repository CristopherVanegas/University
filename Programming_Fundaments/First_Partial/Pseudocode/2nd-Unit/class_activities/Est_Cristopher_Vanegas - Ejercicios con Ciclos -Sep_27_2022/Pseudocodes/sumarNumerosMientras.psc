// Est. Cristopher Vanegas
Algoritmo sumaNumerosBucleHacer
	Definir contador, lim, num, resultado Como Entero;
	Escribir "Ingresar los n�meros que desea ingresar: ";
	Leer lim;
	
	resultado = 0;
	contador = 1;
	Mientras contador <= lim Hacer
		Escribir "Ingresar un n�mero para sumar con el resultado total, el n�mero no puede ser 0: ";
		Leer num;
		
		Si num <> 0 Entonces
			resultado = resultado + num;
		SiNo
			Escribir "No se puede ingresar 0!";
			contador = lim;
		FinSi
		contador = contador + 1;
	FinMientras
	
	Escribir "El resultado es: ", resultado;
FinAlgoritmo
