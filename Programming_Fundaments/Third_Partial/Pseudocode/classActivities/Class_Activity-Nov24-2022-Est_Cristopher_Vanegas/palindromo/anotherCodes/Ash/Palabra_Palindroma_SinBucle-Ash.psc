Proceso Palabra_Palindroma_Sin_Bucle
	Definir palabra como caracter;
	Definir long Como Entero;
	
	Escribir "Ingrese una palabra (SIN ESPACIOS AL FINAL)";
	Leer palabra;
	long=Longitud(palabra);
	Si Subcadena(palabra,long-1,long-1)==Subcadena(palabra,0,0) Entonces
		Si Subcadena(palabra,long-2,long-2)==Subcadena(palabra,1,1) Entonces
		FinSi
		Escribir "La palabra si es palindroma";
	SiNo
		Escribir "La palabra no es palindroma";
	FinSi
FinProceso
