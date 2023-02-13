// Est. Cristopher Vanegas //

Proceso countWords
	Definir i, words Como Entero;
	Definir text Como Caracter;
	
	Leer text;
	
	words = 0;
	Para i = 0 Hasta Longitud(text)-1 Con Paso 1 Hacer
		Si Subcadena(text, i, i) == " " Y Subcadena(text, i+1, i+1) <> " " Y Subcadena(text, i-1, i-1) <> " " Entonces	// Only if the value of substring (i, i) is a space (" ") and in front of and behinds the caracter is different from a space (" ") adds 1 to "words".
			words = words + 1;
		FinSi
	FinPara
	
	Escribir "";
	Escribir text;
	Escribir "Posee ", words+1, " palabras!";
FinProceso
