Proceso main
	Definir name Como Caracter;
	name = greeting();
	threeAndMarkAlg();
	
FinProceso

SubAlgoritmo name = greeting()
	Definir name Como Caracter;
	Escribir "Welcome to Three and Mark!";
	Escribir "Please enter your name: ", Sin Saltar;
	Leer name;
	Escribir "Ok ", name, " lets start the game!";
	Esperar 1 Segundos;
	Limpiar Pantalla;
FinSubAlgoritmo

SubAlgoritmo threeAndMarkAlg()
	Definir userAttempt Como Entero;
	Definir matrix Como Caracter;
	m = 3; n=3;
	Dimension matrix[m, n];
	
	Para variable_numerica<-valor_inicial Hasta valor_final Con Paso paso Hacer
		secuencia_de_acciones
	FinPara
FinSubAlgoritmo








