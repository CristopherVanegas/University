//	///////////////////////	//
//	Est. Cristopher Vanegas	//
//	///////////////////////	//

Funcion palabraInvertida = ObtenerInvertir(matriz, d)
	Definir i Como Entero;
	Definir palabraInvertida Como Caracter;
	palabraInvertida = "";
	
	Para i = d-1 Hasta 0 Con Paso -1 Hacer
		palabraInvertida = Concatenar(palabraInvertida, matriz[i, i]);
	FinPara
FinFuncion

SubProceso ingresarPalabra(matriz, d, i, palabra)
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		matriz[i, i] = Subcadena(palabra, i, i);
	FinPara
FinSubProceso

SubProceso mostrarMatriz(matriz, d, i, j)
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Escribir "  |", Sin Saltar;
		Para j = 0 Hasta d-1 Con Paso 1 Hacer
			Escribir "  ", matriz[i, j], "  ", Sin Saltar;
		FinPara
		Escribir "|  ";

	FinPara
FinSubProceso

SubProceso llenarMatriz(matriz, d, i, j)
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Para j = 0 Hasta d-1 Con Paso 1 Hacer
			matriz[i, j] = "-";
		FinPara
	FinPara
FinSubProceso

Proceso main
	Definir matriz, palabra, palabraInvertida Como Caracter;
	Definir d Como Entero;
	Escribir "Ingrese una la longitud de la palabra: ", Sin Saltar; Leer d;
	
	Repetir
		Escribir "Ingrese una palabra con dicha longitud: ", Sin Saltar; Leer palabra;
		Si Longitud(palabra) <> d Entonces
			Escribir "";
			Escribir "Por favor ingrese una palabra con la longitud que ingresó!";
		SiNo
			Escribir "Su palabra cumple con la longitud que ingresó!";
			Escribir "";
		FinSi
	Hasta Que Longitud(palabra) == d;
	
	Dimension matriz[d, d];
//	Escribir palabra;	// para comprobar que la palabra se guardo
	
	llenarMatriz(matriz, d, 0, 0);	// (matriz, dimension, iterador i)
	ingresarPalabra(matriz, d, 0, palabra);	// (matriz, dimension, iterador i, palabra)
	mostrarMatriz(matriz, d, 0, 0);	// (matriz, dimension, iterador i, iterador j)
	
	Escribir "La palabra que ingresó es ", palabra;
	Escribir "Y la palabra invertida es ", ObtenerInvertir(matriz, d);

FinProceso
