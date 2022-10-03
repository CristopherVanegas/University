Proceso publicacionLibros
	Definir numLibros, paginas, valorPublicacion, counter Como Entero;
	Definir edicionNacional, edicion2005 Como Caracter;
	Definir valorTotal Como Real;
	valorTotal = 0;
	
	// welcome
	Escribir "Programa para calcular el valor de publicación";
	
	// get variables
	Escribir "Ingresar cuando libros desea publicar: ";
	Leer numLibros;
	
	// get total value
	counter = 1;
	Mientras counter <= numLibros Hacer
		valorPublicacion = 0;
		paginas = 0;
		Escribir "Datos de publicación para el libro ", counter, " :";
		Escribir "Cuantas páginas posee el libro?: ";
		Leer paginas;
		Escribir "La edición es nacional?: (N para no / S para Si)";
		Leer edicionNacional;
		Escribir "La edición es de 2005?: (N para no / S para Si)";
		Leer edicion2005;
		
		Si ((edicionNacional == 'N') && (edicion2005 == 'S')) Entonces
			valorPublicacion = (paginas * 100) + ((paginas * 100) * 0.2);
			Escribir "Valor del libro ", counter, " es: ", valorPublicacion;
			valorTotal = valorTotal + valorPublicacion;
			Escribir "";

		SiNo
			Si ((edicionNacional == 'S') & (edicion2005 == 'N')) Entonces
				valorPublicacion = valorPublicacion + (paginas * 100);
				Escribir "Valor del libro ", counter, " es: ", valorPublicacion;
				valorTotal = valorTotal + valorPublicacion;
				Escribir "";

			SiNo
				Si ((edicionNacional == 'N') || (edicion2005 == 'S')) Entonces
					valorPublicacion = (paginas * 100) + ((paginas * 100) * 0.1);
					Escribir "Valor del libro ", counter, " es: ", valorPublicacion;
					valorTotal = valorTotal + valorPublicacion;
					Escribir "";
				FinSi
			FinSi
		FinSi
		counter = counter + 1;
	FinMientras
	
	Escribir "El valor total es: ", valorTotal;
	Escribir "";
	FinProceso
