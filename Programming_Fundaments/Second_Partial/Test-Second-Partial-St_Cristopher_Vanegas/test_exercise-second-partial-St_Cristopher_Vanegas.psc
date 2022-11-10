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
	ordenAscentente(matrix, n);			// Los ordena
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

SubProceso ordenAscentente(matrix, n)
	Definir m, i, j Como Entero;
	Escribir "Ordenando la matriz de forma ascendente", Sin Saltar;
	Para i = 0 Hasta 2 Con Paso 1 Hacer
		Escribir ".", Sin Saltar;
		Esperar 1 Segundos;
	FinPara
	Escribir "";
	Para i = 0 Hasta n-1 Con Paso 1 Hacer
		Para j = i+1 Hasta n-1 Con Paso 1 Hacer
			Si matrix[0, i] > matrix[0, j] Entonces
				m = matrix[0, i];
				
				matrix[0, i] = matrix[0, j];
				matrix[0, j] = m;
			Finsi
			Si matrix[1, i] > matrix[1, j] Entonces
				m = matrix[1, i];
				
				matrix[1, i] = matrix[1, j];
				matrix[1, j] = m;
			Finsi
			Si matrix[2, i] > matrix[2, j] Entonces
				
				m = matrix[2, i];
				matrix[2, i] = matrix[2, j];
				matrix[2, j] = m;
			Finsi
			Si matrix[3, i] > matrix[3, j] Entonces
				m = matrix[3, i];
				
				matrix[3, i] = matrix[3, j];
				matrix[3, j] = m;
			Finsi
			Si matrix[4, i] > matrix[4, j] Entonces
				
				m = matrix[4, i];
				matrix[4, i] = matrix[4, j];
				matrix[4, j] = m;
			Finsi
		FinPara
	FinPara
FinSubProceso
	