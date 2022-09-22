Algoritmo menuCalculadora
	Definir num_A, num_B, opt Como Entero;
	Definir resultado Como Real;
	
	Escribir "Por favor ingresar un opción: ";
	Escribir " [1] multiplicación";
	Escribir " [2] división";
	Leer opt;
	Segun opt Hacer
		1:
			Escribir "";
			Escribir " > [1] multiplicación";
			Escribir " [2] división";
			
			Escribir ">>> Por favor ingresar número 1: ";
			Leer num_A;
			Escribir ">>> Por favor ingresar número 2: ";
			Leer num_B;
			resultado = num_A * num_B;
			Escribir "La multiplicación de ", num_A, " por ", num_B, ": ", resultado;
		2:
			Escribir "";
			Escribir " [1] multiplicación";
			Escribir " > [2] división";
			
			Escribir ">>> Por favor ingresar número 1: ";
			Leer num_A;
			Escribir ">>> Por favor ingresar número 2: ";
			Leer num_B;
			resultado = num_A / num_B;
			Escribir "La división de ", num_A, " por ", num_B, ": ", resultado;
			
		De Otro Modo:
			Escribir "Opción erroneo, programa terminado!"
	Fin Segun
FinAlgoritmo
