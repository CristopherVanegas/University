// 	INGRESAR TRES NUMEROS Y ENCONTRAR EL MAYOR
// EST. CRISTOPHER VANEGAS

Algoritmo numeroMayor
	Definir num_A, num_B, num_C, greatest_n Como Entero;
	Escribir "Ingrese un n�mero para A: ";
	Leer num_A;
	Escribir "Ingrese un n�mero para B: ";
	Leer num_B;
	Escribir "Ingrese un n�mero para C: ";
	Leer num_C;
	
	greatest_n = num_A;
	Si (greatest_n <= num_B) Entonces
		greatest_n = num_B;
	SiNo
		Si (greatest_n <= num_C) Entonces
			greatest_n = num_C;
		FinSi
	Fin Si
	
	Si (greatest_n <= num_C) Entonces
		greatest_n = num_C;
	SiNo
		Si (greatest_n <= num_B) Entonces
			greatest_n = num_B;
		FinSi
	Fin Si
	
	Escribir "";
	Escribir "El n�mero mayor es: ", greatest_n;
	
FinAlgoritmo
