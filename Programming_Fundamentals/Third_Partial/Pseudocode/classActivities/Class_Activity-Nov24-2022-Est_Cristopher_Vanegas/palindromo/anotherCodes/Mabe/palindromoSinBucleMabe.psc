Proceso palindromoSinBucleMabe
	Definir palabra, i, j Como Caracter;
	Definir long Como Entero;
	Escribir "Ingrese una palabra";
	Leer palabra; 
	long=Longitud(palabra); 
	//	Escribir Concatenar(Subcadena(palabra,0,0),Subcadena(palabra,1,1)); 
	//	Escribir Concatenar(Subcadena(palabra,long-1,long-1),Subcadena(palabra,long-2,long-2)); 
	Si Concatenar(Subcadena(palabra,long-1,long-1),Subcadena(palabra,long-2,long-2)) <> Concatenar(Subcadena(palabra,0,0),Subcadena(palabra,1,1)) Entonces
		Escribir "La palabra ", palabra, " no es un palindromo";
	SiNo
		Escribir "La palabra ", palabra, " es un palindromo";
	FinSi
FinProceso
