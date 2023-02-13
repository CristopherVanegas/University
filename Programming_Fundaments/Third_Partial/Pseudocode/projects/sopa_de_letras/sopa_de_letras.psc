SubProceso fillOutMatrix(matrix, m, n)
	Definir i, j Como Entero;
	Para i = 0 Hasta valor_final Con Paso paso Hacer
		Para variable_numerica<-valor_inicial Hasta valor_final Con Paso paso Hacer
			secuencia_de_acciones
		FinPara
	FinPara
FinSubProceso


Proceso main
	Definir matrix, m, n Como Entero;
	m = 10;
	n = 10;
	Dimension matrix[m, n];
	
	fillOutMatrix(matrix, m, n);
FinProceso
