// Est. Cristopher Vanegas //

Proceso invertirCadena
	Definir i Como Entero;
	Definir text,  nText Como Caracter;
	nText = "";
	leer text;
	
	Para i = Longitud(text) Hasta 0 Con Paso -1 Hacer
		nText = Concatenar(nText, Subcadena(text, i, i));
	FinPara
	
	Escribir nText;

	
FinProceso
