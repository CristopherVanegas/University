SubProceso mostrar_matriz_asc ( arreglo )
	Definir f, c Como Real;
	Para f=0 Hasta 4 Con Paso 1 Hacer
		Para c=0 Hasta 2 Con Paso 1 Hacer
			Escribir "La posicion ordenada manera ascendete (",f,",",c,") es: ", arreglo[f,c];
		FinPara
	FinPara
FinSubProceso

SubProceso ord_matriz_asc (arreglo)
	Definir f, c, aux, k como Real;
	//	Ash's Algorythm
	Para f=0 Hasta 4 Con Paso 1 Hacer
		Para c=0 Hasta 2 Con Paso 1 Hacer
			Para k=c+1 Hasta 2 Con Paso 1 Hacer
				Si arreglo[f,k] < arreglo[f,c] Entonces
					aux=arreglo[f,c];
					arreglo[f,k]=arreglo[f,c];
					arreglo[f,c]=aux;
				FinSi
			FinPara
		FinPara
	FinPara
	
	//	Cristopher's Algorythm
	Para c=0 Hasta 2 Con Paso 1 Hacer
		Para f=0 Hasta 4 Con Paso 1 Hacer
			Para k=f+1 Hasta 4 Con Paso 1 Hacer
				Si arreglo[k,c] < arreglo[f,c] Entonces
					aux=arreglo[k,c];
					arreglo[k,c]=arreglo[f,c];
					arreglo[f,c]=aux;
				FinSi
			FinPara
		FinPara
	FinPara
FinSubProceso

SubProceso suma_fila0 (arreglo)
	Definir sumafila, prom_fisica, c  Como Real;
	sumafila=0;
	prom_fisica=0;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		sumafila=(sumafila+arreglo[0,c]);
		prom_fisica=sumafila/3;
	FinPara
	Escribir "El promedio de Fisica es: ", prom_fisica;
FinSubProceso

SubProceso suma_fila1 (arreglo)
	Definir sumafila1, prom_mate, c  Como Real;
	sumafila1=0;
	prom_mate=0;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		sumafila1=(sumafila1+arreglo[1,c]);
		prom_mate=sumafila1/3;
	FinPara
	Escribir "El promedio de Matematicas es: ", prom_mate;
FinSubProceso

SubProceso suma_fila2 (arreglo)
	Definir sumafila2, prom_quimica, c  Como Real;
	sumafila2=0;
	prom_quimica=0;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		sumafila2=(sumafila2+arreglo[2,c]);
		prom_quimica=sumafila2/3;
	FinPara
	Escribir "El promedio de Quimica es: ", prom_quimica;
FinSubProceso

SubProceso suma_fila3 (arreglo)
	Definir sumafila3, prom_ciencias, c  Como Real;
	sumafila3=0;
	prom_ciencias=0;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		sumafila3=(sumafila3+arreglo[3,c]);
		prom_ciencias=sumafila3/3;
	FinPara
	Escribir "El promedio de Ciencias es: ", prom_ciencias;
FinSubProceso

SubProceso suma_fila4 (arreglo)
	Definir sumafila4, prom_esta, c  Como Real;
	sumafila4=0;
	prom_esta=0;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		sumafila4=(sumafila4+arreglo[4,c]);
		prom_esta=sumafila4/3;
	FinPara
	Escribir "El promedio de Estadistica es: ", prom_esta;
FinSubProceso


SubProceso mostrarmatriz (arreglo)
	Definir f, c Como Real;
	Para f=0 Hasta 4 Con Paso 1 Hacer
		Para c=0 Hasta 2 Con Paso 1 Hacer
			Escribir "La posicion (",f,",",c,") es: ", arreglo[f,c];
		FinPara
	FinPara
FinSubProceso

SubProceso llenarmatriz (arreglo)
	Definir f, c Como Real;
	Para f=0 Hasta 4 Con Paso 1 Hacer
		Para c=0 Hasta 2 Con Paso 1 Hacer
			arreglo[f,c]=Aleatorio(0,20);
		FinPara
	FinPara
FinSubProceso

Proceso Examen
	Definir nums, arreglo, k, aux, f, c Como Real;
	Dimension nums[5,3];
	llenarmatriz(nums);
	mostrarmatriz(nums);
	Escribir "";
	suma_fila0(nums);
	suma_fila1(nums);
	suma_fila2(nums);
	suma_fila3(nums);
	suma_fila4(nums);
	Escribir "";
	ord_matriz_asc(nums);
	mostrar_matriz_asc(nums);
	
	Escribir "";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		Escribir " ", nums[0,c], " " Sin Saltar; 
	FinPara
	Escribir "|" Sin Saltar;
	
	Escribir "";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		Escribir " ", nums[1,c], " " Sin Saltar;
	FinPara
	Escribir "|" Sin Saltar;
	
	Escribir "";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		Escribir " ", nums[2,c], " " Sin Saltar;
	FinPara
	Escribir "|" Sin Saltar;
	
	Escribir "";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		Escribir " ", nums[3,c], " " Sin Saltar;
	FinPara
	Escribir "|" Sin Saltar;
	
	Escribir "";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta 2 Con Paso 1 Hacer
		Escribir " ", nums[4,c], " " Sin Saltar;
	FinPara
	Escribir "|" Sin Saltar;
	Escribir "";
	
FinProceso
