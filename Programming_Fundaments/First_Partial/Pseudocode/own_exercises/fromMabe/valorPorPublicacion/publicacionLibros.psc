Proceso publicacionLibros
	Definir numLibros, paginas Como Entero;
	Definir edicionNacional, edicion2005 Como Caracter;
	Definir valorTotal Como Real;
	valorTotal = 0;
	
	// welcome
	Escribir "Programa para calcular el valor de publicaci�n";
	
	
	// get variables
	Escribir "Ingresar cuando libros desea publicar: ";
	Leer numLibros;
	
	Definir counter Como Entero;
	counter = 1;
	Mientras counter <= numLibros Hacer
		Escribir "Datos de publicaci�n para el libro ", counter, " :";
		Escribir "Cuantas p�ginas posee el libro?: ";
		Leer paginas;
		Escribir "La edici�n es nacional?: (N para no / S para Si)";
		Leer edicionNacional;
		Escribir "La edici�n es de 2005?: (N para no / S para Si)";
		Leer edicion2005;
		
		Si ((edicionNacional == 'N') || (edicion2005 == 'S')) Entonces
			valorTotal = valorTotal + (paginas * 100);
			valorTotal = valorTotal + (valorTotal * 0.1);
		SiNo
			valorTotal = valorTotal + (paginas * 100);
		FinSi
		counter = counter + 1;
	FinMientras
	
	Escribir "El valor total es: ", valorTotal;
FinProceso
