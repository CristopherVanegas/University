Funcion validarprimo <- primo ( num )
	Definir validarprimo, i, num_divisiones Como Entero;
	num_divisiones=0;
	Para i=1 Hasta num Con Paso 1 Hacer
		Si num mod i == 0 Entonces
			num_divisiones=num_divisiones+1;
		FinSi
	FinPara
	Si num_divisiones = 2 Entonces
		validarprimo = 1;
	SiNo
		validarprimo = 0;
	FinSi
FinFuncion

Funcion validarimpar <- impar ( num )
	Definir validarimpar Como Entero;
	Si num mod 2 <> 0 Entonces
		validarimpar = 1;
	SiNo
		validarimpar = 0;
	FinSi
FinFuncion

Funcion validarpar <- par ( num )
	Definir validarpar Como Entero;
	Si num mod 2 = 0 Entonces
		validarpar = 1;
	SiNo
		validarpar = 0;
	FinSi
FinFuncion

Proceso Resolucion_Actividad
	Definir respuesta1, respuesta2, respuesta3, num_divisiones, i, num, x, matriz, f, c Como Entero;
	Definir n Como Entero; // independiente para las columnas
	n = 6; // para evitar el error de "numero escondido / perdido" al enviar números de una misma categoría.
	Dimension matriz[3, n]; // para que funcione debes comidificar el pseint para que te permita dimensionar con variables.
//	f=0;
//	c=0;
	
	Para f=0 Hasta 2 Con Paso 1 Hacer
		Para c=0 Hasta n-1 Con Paso 1 Hacer
			matriz[f,c]=0;
			Escribir "La posicion de los valores de la matriz (", f, ",", c, ") es: ",matriz[f,c];
		FinPara
	FinPara
	
	Para x=0 Hasta 5 Con Paso 1 Hacer
		Escribir "Ingrese el valor a validar: ";
		Leer num;
		respuesta1 = par ( num );
		Si respuesta1 == 1 Entonces
			Para c=0 Hasta n-1 Con Paso 1 Hacer
				Si matriz[0,c]=0 Entonces
					matriz[0,c]=num;
					respuesta3 = primo ( num );
					Si respuesta3 == 1 Entonces
						Para c=0 Hasta n-1 Con Paso 1 Hacer
							Si matriz[2,c]=0 Entonces
								matriz[2,c]=num;
								num=0;
							FinSi
						FinPara
					FinSi
					num=0;
				FinSi
			FinPara
		FinSi
		
		respuesta2 = impar ( num );
		Si respuesta2 == 1 Entonces
			Para c=0 Hasta n-1 Con Paso 1 Hacer
				Si matriz[1,c]=0 Entonces
					matriz[1,c]=num;
					respuesta3 = primo ( num );
					Si respuesta3 == 1 Entonces
						Para c=0 Hasta n-1 Con Paso 1 Hacer
							Si matriz[2,c]=0 Entonces
								matriz[2,c]=num;
								num=0;
							FinSi
						FinPara
					FinSi
					num=0;
				FinSi
			FinPara
		FinSi
	FinPara
	
	
	
	Para f=0 Hasta 2 Con Paso 1 Hacer
		Para c=0 Hasta 3 Con Paso 1 Hacer
			Escribir "La posicion de los valores de la matriz (", f, ",", c, ") es: ",matriz[f,c];
		FinPara
	FinPara
	
//	Para f=0 Hasta 2 Con Paso 1 Hacer
//		Escribir " ";
//		Escribir "|" Sin Saltar;
//		Para c=0 Hasta 3 Con Paso 1 Hacer
//			Escribir " ", matriz[f,c], " " Sin Saltar;
//		FinPara
//		Escribir "|" Sin Saltar;
//	FinPara
//	
	Escribir " ";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta n-1 Con Paso 1 Hacer
		Escribir " ", matriz[0,c], " " Sin Saltar;
	FinPara
	Escribir "| Es par" Sin Saltar;
	
	Escribir " ";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta n-1 Con Paso 1 Hacer
		Escribir " ", matriz[1,c], " " Sin Saltar;
	FinPara
	Escribir "| Es impar" Sin Saltar;
	
	Escribir " ";
	Escribir "|" Sin Saltar;
	Para c=0 Hasta n-1 Con Paso 1 Hacer
		Escribir " ", matriz[2,c], " " Sin Saltar;
	FinPara
	Escribir "| Es primo" Sin Saltar;
	
	
//	Para f=0 Hasta 2 Con Paso 1 Hacer
//		Escribir " ";
//		Para c=0 Hasta 3 Con Paso 1 Hacer
//			Escribir " ", matriz[0,c]," " Sin Saltar;
//			Si matriz[0,c]=0 Entonces
//				Escribir " ", "Es par";
//			FinSi
//		FinPara
//		
//		Para c=0 Hasta 3 Con Paso 1 Hacer
//			Escribir " ", matriz[1,c]," " Sin Saltar;
//			Si matriz[1,c]=0 Entonces
//				Escribir " ", "Es impar";
//			FinSi
//		FinPara
//		
//		Para c=0 Hasta 3 Con Paso 1 Hacer
//			Escribir " ", matriz[2,c]," " Sin Saltar;
//			Si matriz[2,c]=0 Entonces
//				Escribir " ", "Es primo";
//			FinSi
//		FinPara
//	FinPara
	
	
FinProceso