// ////////////////////////////////////////// //
// ----- ESTUDIANTE CRISTOPHER VANEGAS ----- //
//			  DATE: NOV 29 2022			   //
// ///////////////////////////////////////// //

SubProceso v = generatorOfVocals()									// generates vocals using random() "aleatorio()" and switch(){} "segun".
	Definir v Como Caracter;
	Definir n Como Entero;
	n = Aleatorio(1, 5);
	Segun n Hacer
		1:
			v = "a";
		2:
			v = "e";
		3:
			v = "i";
		4:
			v = "o";
		5:
			v = "u";
	FinSegun
FinSubProceso

SubProceso fillOutWithVocals(arr Por Referencia, d Por Valor)			// Fill out the unidimentional array with vocals.
	Definir i Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		arr[i] = generatorOfVocals();
	FinPara
FinSubProceso

SubProceso showArr(arr Por Referencia, d Por Referencia)				// Shows the unidimentional array using a for loop or "para".
	Definir i Como Entero;
	Para i = 0 Hasta d-1 Con Paso 1 Hacer
		Escribir "Vocal for position ", i, " in array is: ", arr[i]; 
	FinPara
FinSubProceso

Proceso main															// Main process where is created the unidimentional array and used fillOutWithVocals() and showArr()
	Definir arr Como Caracter;
	Definir d Como Entero;
	Escribir "Please enter the dimension for your unidimensional array: ", Sin Saltar;
	Leer d;
	Dimension arr[d];
	
	fillOutWithVocals(arr, d);
	showArr(arr, d);
FinProceso
