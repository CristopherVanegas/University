//	///////////////////////	//
//	Est. Cristopher Vanegas	//
//	///////////////////////	//

SubProceso mostrar(matriz, d, i, j)
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Escribir "  |", Sin Saltar;
		Para j = 0 Hasta d-1 Con Paso 1 Hacer
			Escribir "   ", matriz[i ,j], "   ", Sin Saltar;
		FinPara
		Escribir "|  ";
	FinPara
FinSubProceso


//	Llenar diagonal de Derecha a Izquierda
SubProceso llenarDiagonal(palabra, matriz, d, j)
	Para j = 0 Hasta d-1 Con Paso 1 Hacer	//	Itera filas
		//	matriz[fila del 0 hasta d-1, columna d-1 -valorDelIterador hasta 0 para ir de d-1 a 0]
		matriz[j ,d-1-j] = Subcadena(palabra, j, j);	// agrega de forma diagonal.
	FinPara
FinSubProceso

Funcion invertida = obtenerInversa(palabra, matriz, d, i)
	Definir invertida Como Caracter;
	invertida = "";
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		invertida = Concatenar(invertida, matriz[d-1-i, i]);
	FinPara
FinFuncion

SubProceso llenar(matriz, d, i, j)
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Para j = 0 Hasta d-1 Con Paso 1 Hacer
			matriz[i ,j] = "-";
		FinPara
	FinPara
FinSubProceso

Proceso main
	Definir matriz, palabra Como Caracter;
	Definir d Como Entero;
	
	
	Escribir "Ingrese la dimensión de la palabra: ", Sin Saltar; Leer d;
	Dimension matriz[d, d];
	llenar(matriz, d, 0, 0);
	
	Repetir
		Escribir "Ingrese una palabra que cumpla con la dimensión: ", Sin Saltar; Leer palabra;
		
		Si(Longitud(palabra) <> d) Entonces
			Escribir "";
			Escribir "La palabra no cumple con la dimensión ingresada!";
		SiNo
			Escribir "La palabra cumple con la dimensión!";
			Escribir "";
		FinSi
	Hasta Que (Longitud(palabra) == d)
	
	llenarDiagonal(palabra, matriz, d, 0);
	mostrar(matriz, d, 0, 0);
	
	
	Escribir "";
	Escribir "La palabra que ingresó fue ", palabra;
	Escribir "La palabra invertida que ingresó fue ", obtenerInversa(palabra, matriz, d, 0);
FinProceso
