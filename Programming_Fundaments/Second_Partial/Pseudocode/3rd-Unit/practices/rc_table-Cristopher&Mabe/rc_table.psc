// Definir matriz de 2xn 																	?
// Hacer un programa el cual el usuario ingrese n numeros.									?
// Calcular su raiz cuadrada. Si es una raiz exacta guardarla en la fila 1 del arreglo		?
// Si es una raiz inexacta guargarlo en la fila 2 arreglo.
// Ordenarlos de menor a mayor y mostrar la matriz ordenada

Proceso main
	Definir m, n, opt Como Entero;
	Definir matrix Como Real;
	Escribir "Por favor ingrese cuantos números ingresará: ";
	Leer n;
	m = 2;
	Dimension matrix[m, n];
	Escribir "";
	
	matrixDeCeros(matrix, m, n);
	pregunta_y_orderna(matrix, m, n);
	show(matrix, m, n);
	
	Escribir "Desea ordenar sus datos en orden incrementado? ( Escribir 1 | 2 ) ";
	Escribir "[1] Si";
	Escribir "[2] No";
	Leer opt;
	
	Segun opt Hacer
		1:
			ordenIncrementado(matrix, n);
			show(matrix, m, n);
		2:
			Escribir "Fin del programa.";
			
		De Otro Modo:
			Escribir "Error 404, opción no encontrada.";
			Escribir "Fin del programa.";
	FinSegun
	
FinProceso

SubProceso matrixDeCeros(matrix, m, n)
	Definir i, j Como Entero;
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			matrix[i, j] = 0;
		FinPara
	FinPara
FinSubProceso

SubProceso show(matrix, m, n)
	Definir j Como Entero;
	Escribir " > La matriz es: ";
	
	Escribir "  |  ", Sin Saltar;
	Para j=0 Hasta n-1 Con Paso 1 Hacer
		Escribir "  ", matrix[0, j], "  ", Sin Saltar;
	FinPara
	Escribir "  |  RAIZ EXACTA  ";
	
	Escribir "  |  ", Sin Saltar;
	Para j=0 Hasta n-1 Con Paso 1 Hacer
		Escribir "  ", matrix[1, j], "  ", Sin Saltar;
	FinPara
	Escribir "  |  RAIZ INEXACTA  ";
FinSubProceso

SubProceso answer = isRCP(num)
	Definir answer Como Logico;
	Definir rcVal Como Real;
	rcVal = RC(num);
	
	answer = Falso;
	Si (rcVal - trunc(rcVal)) == 0 Entonces	// Verifica si es entero.
		answer = Verdadero;
	FinSi
FinSubProceso

SubProceso pregunta_y_orderna(matrix, m, n)
	Definir uNum, i, j, rcp_c, rcpi_c Como Entero;
	
	rcp_c = 0;
	rcpi_c = 0;
	
	// Pide números
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Escribir " > Please enter a number, numbers inserted -> [", i+1, "/", n, "]";
		Leer uNum;
		Escribir "";
		
		// raiz cuadrada perfecta
		Si isRCP(uNum) Entonces
			matrix[0, rcp_c] = uNum;
			rcp_c = rcp_c + 1;
		FinSi
		
		// raiz cuadrada imperfecta
		Si !isRCP(uNum) Entonces
			matrix[1, rcpi_c] = uNum;
			rcpi_c = rcpi_c + 1;
		FinSi
	FinPara
FinSubProceso

SubProceso ordenIncrementado(matrix, n)
	Definir m, i, j Como Entero;
	Para i = 0 Hasta n-1 Con Paso 1 Hacer	// original
		Para j = i+1 Hasta n-1 Con Paso 1 Hacer	// adelantado
			Si matrix[0, i] > matrix[0, j] Y matrix[0, j] <> 0 Entonces
				m = matrix[0, i];
				
				matrix[0, i] = matrix[0, j];
				matrix[0, j] = m;
			Finsi
			Si matrix[1, i] > matrix[1, j] Y matrix[1, j] <> 0 Entonces
				m = matrix[1, i];
				
				matrix[1, i] = matrix[1, j];
				matrix[1, j] = m;
			Finsi
		FinPara
	FinPara
FinSubProceso