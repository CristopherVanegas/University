Algoritmo menuCalculadora
	Definir num_A, num_B, opt Como Entero;
	Definir resultado Como Real;
	
	Escribir "Por favor ingresar un opci�n: ";
	Escribir " [1] multiplicaci�n";
	Escribir " [2] divisi�n";
	Leer opt;
	Segun opt Hacer
		1:
			Escribir "";
			Escribir " > [1] multiplicaci�n";
			Escribir " [2] divisi�n";
			
			Escribir ">>> Por favor ingresar n�mero 1: ";
			Leer num_A;
			Escribir ">>> Por favor ingresar n�mero 2: ";
			Leer num_B;
			resultado = num_A * num_B;
			Escribir "La multiplicaci�n de ", num_A, " por ", num_B, ": ", resultado;
		2:
			Escribir "";
			Escribir " [1] multiplicaci�n";
			Escribir " > [2] divisi�n";
			
			Escribir ">>> Por favor ingresar n�mero 1: ";
			Leer num_A;
			Escribir ">>> Por favor ingresar n�mero 2: ";
			Leer num_B;
			resultado = num_A / num_B;
			Escribir "La divisi�n de ", num_A, " por ", num_B, ": ", resultado;
			
		De Otro Modo:
			Escribir "Opci�n erroneo, programa terminado!"
	Fin Segun
FinAlgoritmo
