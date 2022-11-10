Proceso DecimalABinario
	Definir n, dec, modelobinario, i Como real;
	Dimension modelobinario[8];
	modelobinario[0]=128;
	modelobinario[1]=64;
	modelobinario[2]=32;
	modelobinario[3]=16;
	modelobinario[4]=8;
	modelobinario[5]=4;
	modelobinario[6]=2;
	modelobinario[7]=1;
	Escribir "Ingrese un numero que no sobrepase 255";
	Leer dec;
	Si dec<=255 Entonces
		Para i=0 Hasta 7 Con Paso 1 Hacer
			Si dec>=modelobinario[i] Entonces
				dec=dec-modelobinario[i];
				modelobinario[i]=1;
			SiNo
				Si dec<modelobinario[i] Entonces
					modelobinario[i]=0;
				FinSi
			FinSi
		FinPara
		Escribir "El numero de decimal a binario es: ", Sin Saltar;
		Para i=0 Hasta 7 Con Paso 1 Hacer
			Escribir "", modelobinario[i], Sin Saltar;
		FinPara
		Escribir "";
	SiNo
		Escribir "El numero es mayor a 255";
	FinSi
FinProceso
