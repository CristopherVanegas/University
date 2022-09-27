// Est. Cristopher Vanegas
Algoritmo sumaNumerosBucleHacer
	Definir contador, lim, num, resultado Como Entero;
	resultado = 0;
	Escribir "Ingresar los números que desea ingresar: ";
	Leer lim;
	
	contador = 1;
	Mientras contador <= lim Hacer
		Escribir "Ingresar un número para sumar con el resultado total, el número no puede ser 0: ";
		Leer num;
		
		Si num <> 0 Entonces
			resultado = resultado+ num;
		SiNo
			Escribir "No se puede ingresar 0!";
			contador = lim;
		FinSi
		contador = contador + 1;
	FinMientras
	
	Escribir "El resultado es: ", resultado;
FinAlgoritmo
