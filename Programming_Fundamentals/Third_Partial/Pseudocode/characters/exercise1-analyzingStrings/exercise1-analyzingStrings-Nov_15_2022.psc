// Crear una solución que pida una cadena y luego un carácter por teclado
// (valida que sea solo un carácter)
// Y muestra cuantas veces aparece el carácter en la cadena.

// Est. Cristopher Vanegas

Proceso main
	Definir qOfRep, qOfV Como Entero;
	Definir str, char Como Caracter;
	
	Escribir "Ingresa un string: ", Sin Saltar; Leer str;
	Escribir "Ingresa un caracter a buscar: ", Sin Saltar; Leer char;
	
	// loop
	Mientras (Longitud(char) <> 1) Hacer
		Escribir "";
		Escribir "La longitud del caracter que mandas a buscar es mayor a 1";
		Esperar 1 Segundos;
		Limpiar Pantalla;
			
		Escribir "Ingresa un caracter a buscar en ", str, " : ", Sin Saltar;
		Leer char;
	FinMientras
	
	// validation
	qOfRep = buscarChar(str, char);
	qOfV = buscarYContarVocales(str);
	
	Si qOfRep > 0 O qOfV > 0 Entonces
		Escribir "";
		Escribir "Se encontraron ", qOfRep, " veces el character ", char ," en (", str, ")";
		Escribir "Se encontraron ", qOfV, " vocales en (", str, ")";
	FinSi
	
	// End of program
	Escribir "Fin del programa";
FinProceso

SubAlgoritmo qOfRep = buscarChar(str, char)
	Definir i, acum, qOfRep Como Entero;
	acum = 0;
	Para i=0 Hasta Longitud(str)-1 Con Paso 1 Hacer
		Si Subcadena(str, i, i) == char Entonces
			acum = acum + 1;
		FinSi
	FinPara
	
	qOfRep = acum;
FinSubAlgoritmo

SubAlgoritmo qOfV = buscarYContarVocales(str)
	Definir i, j, acum, qOfV, d Como Entero;
	Definir vocals Como Caracter;
	d = 10;
	Dimension vocals[d];
	vocals[0] = "a"; vocals[1] = "e"; vocals[2] = "i"; vocals[3] = "o"; vocals[4] = "u";
	vocals[5] = "A"; vocals[6] = "E"; vocals[7] = "I"; vocals[8] = "O"; vocals[9] = "U";
	acum = 0;
	Para i=0 Hasta Longitud(str)-1 Con Paso 1 Hacer
		Para j = 0 Hasta d-1 Con Paso 1 Hacer
			Si Subcadena(str, i, i) == vocals[j] Entonces
				acum = acum + 1;
			FinSi
		FinPara
	FinPara
	qOfV = acum;
	
	// cuenta vocales
	Para j = 0 Hasta d-1 Con Paso 1 Hacer
		acum = 0;
		Para i=0 Hasta Longitud(str)-1 Con Paso 1 Hacer
			Si Subcadena(str, i, i) == vocals[j] Entonces
				acum = acum + 1;
			FinSi
			
		FinPara
		Escribir "Exiten ", acum, " vocales ", vocals[j];
	FinPara
FinSubAlgoritmo

