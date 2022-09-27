Algoritmo sumaNumeros
	Definir contador, lim, num, resultado Como Entero;
	resultado = 0;
	Escribir "Ingresar los números que desea ingresar: ";
	Leer lim;
	
	// estructura hacer
	
	// estructura repetir 
	
	Para contador=1 Hasta lim Con Paso 1 Hacer
		Escribir "Ingresar un número para sumar con el resultado total, el número no puede ser 0: ";
		Leer num;
		
		Si num != 0 Entonces
			resultado = resultado+ num;
		SiNo
			Escribir "No se puede ingresar 0!";
			contador = lim;
			//Escribir "Ingresar un número para sumar con el resultado total, el número no puede ser 0: ";
			//Leer num;
			
		Fin Si
	Fin Para
	Escribir "El resultado es: ", resultado;
	
FinAlgoritmo
