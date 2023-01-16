SubProceso verificar(string, nString Por Referencia)
	Definir i, j, c Como Entero;
	Definir letra Como Caracter;
	Definir lg, v Como Logico;
	
	c = Longitud(string);
	
	Repetir
		// prints String
		
		
		// prints nString
		Escribir "nString: ", Sin Saltar;
		Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
			Escribir nString[i], Sin Saltar;
		FinPara
		Escribir "";
		Escribir "Tus intentos son: ", c;
		Escribir "";
		
		Escribir "ingrese una letra: "; Leer letra;
		
		// itera en la palabara para verificar la letra ingresada
		Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
			Si (letra == Subcadena(string, i, i)) Entonces
				nString[i] = letra;
				
				Si (i <> 0) Entonces
					Si (nString[i-1] == "-") Entonces
						lg = Falso;
					FinSi
				SiNo
					lg = Verdadero;
				FinSi
				
				c = c;
				// escribe la palabra que se va completando
				Para j = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
					Escribir nString[j], Sin Saltar;
				FinPara
			SiNo
				lg = Falso;
//				c = c - 1;
//				i = Longitud(string);
			FinSi
			
		FinPara
		
		
		// verifica si se agrego la letra, si no resta 1 a las vidas
		Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
			Si (nString[i] == letra) Entonces
				v = Verdadero;
				i = Longitud(string);
			SiNo
				v = Falso;
			FinSi
		FinPara
		
		Si (v == Falso) Entonces
			c = c - 1;
		FinSi
		Limpiar Pantalla;
	Hasta Que (lg == Verdadero O c == 0);
	
	
	Si (lg == Verdadero) Entonces
		Escribir "GANASTE :) !";
	SiNo
		Si (c == 0) Entonces
			Escribir "PERDISTE :( !";
		FinSi
	FinSi
FinSubProceso


Proceso main
	Definir string Como Caracter;
	Definir nString Como Caracter;
	
	string = "celular";
	Dimension nString[Longitud(string)];
	
	// set the nString to -----------
	Definir i Como Entero;
	Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
		nString[i] = "-";
	FinPara
	
	
	// asks for letters and shows
	verificar(string, nString);
FinProceso
