Algoritmo promedioTresNotas
	Definir nota_1, nota_2, nota_3 Como Entero;
	Definir promedioNota Como Real;
	
	Escribir "Ingresar nota 1: "
	Leer  nota_1;
	Escribir "Ingresar nota 2: "
	Leer  nota_2;
	Escribir "Ingresar nota 3: "
	Leer  nota_3;
	
	promedioNota = (nota_1+nota_2+nota_3)/3;
	Escribir "";
	Escribir ">>> Promedio de las notas es: ", promedioNota;
	
	Si (promedioNota >= 69) Entonces
		Escribir "Aprobado!";
	SiNo
			Si ((promedioNota > 62) && (promedioNota < 70)) Entonces
				Escribir "Directito a supletorio papi";
			finSi
		SiNo
			Escribir "Reprobado";
		finSi	
	finSi
FinAlgoritmo
