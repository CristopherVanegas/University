Algoritmo sumaNumeros
	Definir contador, lim, num, resultado Como Entero;
	resultado = 0;
	Escribir "Ingresar los n�meros que desea ingresar: ";
	Leer lim;
	
	// estructura hacer
	
	// estructura repetir 
	
	Para contador=1 Hasta lim Con Paso 1 Hacer
		Escribir "Ingresar un n�mero para sumar con el resultado total, el n�mero no puede ser 0: ";
		Leer num;
		
		Si num != 0 Entonces
			resultado = resultado+ num;
		SiNo
			Escribir "No se puede ingresar 0!";
			contador = lim;
			//Escribir "Ingresar un n�mero para sumar con el resultado total, el n�mero no puede ser 0: ";
			//Leer num;
			
		Fin Si
	Fin Para
	Escribir "El resultado es: ", resultado;
	
FinAlgoritmo
