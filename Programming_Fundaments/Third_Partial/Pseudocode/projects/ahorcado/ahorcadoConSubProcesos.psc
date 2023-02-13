// ///////////////////// //
//	JUEGO DEL AHORCADO	//
// ///////////////////// //

Funcion vf = verificar(string, nString, i)
	Definir vf Como Logico;
	//	inicializo la verificación como verdadera y 
	//	solo cambiará cuando encuentre una diferencia
	//	entre el string original y el que adivina el usuario.
	vf = Verdadero;	
	
	Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
		Si Subcadena(string, i, i) <> nString[i] Entonces
			vf = Falso;
			
			i = Longitud(string);	// rompe el bucle
		FinSi
	FinPara
FinFuncion


SubProceso agregarLetra(string, nString, i, char)
	Definir isInIt Como Logico;
	isInIt = Verdadero;
	
	Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
		mostrarString(nString, string, 0);
		Leer char;
		
		//	condicional para agregar en el array nString[]
		Si char == Subcadena(string, i, i) Entonces
			nString[i] = char;
			
		//	Por ahora no es necesario un SiNo
		FinSi
		
		Si verificar(string, nString, 0) Entonces
			i = Longitud(string);
			//	Por ahora no es necesario un SiNo
		FinSi
		
		Limpiar Pantalla;
	FinPara
FinSubProceso


SubProceso mostrarString(nString, string, i)
	Escribir string;
	Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
		Escribir nString[i], Sin Saltar;
	FinPara
	Escribir "";
FinSubProceso


SubProceso llenarnString(nString, string, i)
	Para i = 0 Hasta Longitud(string)-1 Con Paso 1 Hacer
		nString[i] = "-";
	FinPara
FinSubProceso


Proceso main
	Definir string, nString Como Caracter;
	string = "hola";
	Dimension nString[Longitud(string)];
	llenarnString(nString, string, 0);
	agregarLetra(string, nString, 0, "");
FinProceso
