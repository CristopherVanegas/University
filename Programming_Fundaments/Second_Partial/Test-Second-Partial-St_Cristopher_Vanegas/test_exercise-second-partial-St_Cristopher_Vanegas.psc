// ----- ESTUDIANTE CRISTOPHER VANEGAS ----- //
// ---------------- EXAMEN ----------------- //
Proceso main
	Definir matrix, m, n Como Entero;
	
	m = 5;	// initializing rows
	n = 3;	// initializing columns
	Dimension matrix[m, n];					// Creates the matrix
	
	matrixDeCeros(matrix, m, n);
	showMatrix(matrix, m, n);				// Muestra la matrix
	promPartials(matrix, m, n);				// Promedio de los parciales
	menu(matrix, m, n);						// Menu para ordenar
	showMatrix(matrix, m, n);				// Muestra la matrix
FinProceso

SubProceso promPartials(matrix, m, n)
	Definir prom_p_1, prom_p_2, prom_p_3 Como Real;
	Definir i, j, acum Como Entero;
	prom_p_1 = 0;
	prom_p_2 = 0;
	prom_p_3 = 0;
	
	Para j = 0 Hasta n-1 Con Paso 1 Hacer
		acum = 0;
		Para i=0 Hasta m-1 Con Paso 1 Hacer
			acum = acum + matrix[i, j];
		FinPara
		Segun j Hacer
			0:
				prom_p_1 = acum / m;
				Escribir ">>> Parcial ", j+1, ", suma es: ", acum;
				Escribir "numero de notas ", m;
				Escribir "promedio parcial ", j+1, " es ", prom_p_1;
				Escribir "";
			1:
				prom_p_2 = acum / m;
				Escribir ">>> Parcial ", j+1, ", suma es: ", acum;
				Escribir "numero de notas ", m;
				Escribir "promedio parcial ", j+1, " es ", prom_p_2;
				Escribir "";
			2:
				prom_p_3 = acum / m;
				Escribir ">>> Parcial ", j+1, ", suma es: ", acum;
				Escribir "numero de notas ", m;
				Escribir "promedio parcial ", j+1, " es ", prom_p_3;
				Escribir "";
		FinSegun
	FinPara
	Escribir "";
FinSubProceso

SubProceso matrixDeCeros(matrix, m, n)
	Definir i, j Como Entero;
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			matrix[i, j] = Aleatorio(0, 20);
		FinPara
	FinPara
FinSubProceso

SubAlgoritmo showMatrix(matrix, m, n)
	Definir i, j Como Entero;
	Escribir " > La matriz es: ";
	Para i=0 Hasta m-1 Con Paso 1 Hacer
		
		Escribir "  |  ", Sin Saltar;
		Para j=0 Hasta n-1 Con Paso 1 Hacer
			Escribir "  ", matrix[i, j], "  ", Sin Saltar;
		FinPara
		Escribir "  |  ", Sin Saltar;
		
		Segun i Hacer
			0:
				Escribir "FISICA";
			1:
				Escribir "MATEMATICAS";
			2:
				Escribir "QUIMICA";
			3:
				Escribir "CIENCIAS";
			4:
				Escribir "ESTADISTICAS";
		FinSegun
	FinPara
	Escribir "";
FinSubAlgoritmo

SubProceso menu(matrix, m, n)
	Definir opt Como Entero;
	Escribir "Desea ordenar las columnas o filas de sus datos?";
	Escribir " [1] Columnas";
	Escribir " [2] Filas";
	Leer opt;
	Escribir "";
	
	Segun opt Hacer
		1:
			ordenAscententeCol(matrix, m, n);			// Ordena Columnas
		2:
			ordenAscententeFil(matrix, m, n);			// Ordena Filas

		De Otro Modo:
			Escribir "Error 404 Option Not Found!";
			Escribir "End Of Program.";
	FinSegun
FinSubProceso

SubProceso ordenAscententeFil(matrix, m, n)
	Definir minor, i, j, k Como Entero;
	Escribir "Ordenando filas de forma ascendente", Sin Saltar;
	// CARGANDO
	Para i = 0 Hasta 2 Con Paso 1 Hacer
		Escribir ".", Sin Saltar;
		Esperar 1 Segundos;
	FinPara
	Escribir "";
	Escribir "Listo!";
	Escribir "";
	
	Para i = 0 Hasta m-1 Con Paso 1 Hacer
		Para j = 0 Hasta n-1 Con Paso 1 Hacer
			Para k = j + 1 Hasta n-1 Con Paso 1 Hacer
				Si matrix[i, j] > matrix[i, k] Entonces
					minor = matrix[i, k];
					
					// SWITCH
					matrix[i, k] = matrix[i, j];		// Row + 1 pasa a ser mayor que Row.
					matrix[i, j] = minor;			// Row	  pasa a ser el menor.
				FinSi
			FinPara
		FinPara
	FinPara
FinSubProceso

SubProceso ordenAscententeCol(matrix, m, n)
	Definir minor, i, j, k Como Entero;
	Escribir "Ordenando columnas de forma ascendente", Sin Saltar;
	Para i = 0 Hasta 2 Con Paso 1 Hacer
		Escribir ".", Sin Saltar;
		Esperar 1 Segundos;
	FinPara
	Escribir "";
	Escribir "Listo!";
	Escribir "";
	
	Para j=0 Hasta n-1 Con Paso 1 Hacer	// ITERATES COLUMNS
		Para i=0 Hasta m-1 Con Paso 1 Hacer	// ITERATES ROW
			Para k=i+1 Hasta m-1 Con Paso 1 Hacer // ITERATES ROWS + 1
				
				Si matrix[i, j] > matrix[k, j] Entonces	// Si matrix[ROW] > matrix[ROW + 1]
					minor = matrix[k, j];
					
					// SWITCH
					matrix[k, j] = matrix[i, j];		// Column + 1 pasa a ser Column.
					matrix[i, j] = minor;			// Column pasa a ser el menor.
				FinSi
			FinPara
		FinPara
	FinPara
FinSubProceso
	