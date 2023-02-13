// ---- BINARY TO DEC & DEC TO BINARY CONVERSION ---- //
// -------------------- Members --------------------- //
// 	* Cristopher Vanegas
// 	* Andy Apolinario
// 	* Maria Belén García
// 	* Emilio Aguirre
//
// ---------------------------------------------------//

Algoritmo arrayClaseFormal
	main_menu();
FinAlgoritmo

SubAlgoritmo main_menu()
	Definir opt, n Como Entero;
	n = 8;
	
	Escribir "Welcome to the binary convertion program!";
	Escribir "Please choose one of these methods: ";
	Escribir " [1] decimalToBin()";
	Escribir " [2] binToDecimal();";
	Leer opt;
	
	Segun opt Hacer
		1:
			decToBin();
		2:
			binToDec(n);
			
		De Otro Modo:
			Escribir "Error 404, Option not found!";
	FinSegun
	
FinSubAlgoritmo

SubAlgoritmo  get_bin_from_user(bin, n)
	Definir i, uNum Como Entero;
	
	// reverse loop to get bin nums.
	Para i=n-1 Hasta 0 Con Paso -1 Hacer
		Escribir " > Please enter a value for binary number position [ ", 8-i, "/ ", n, " ]: ";
		Leer uNum;
		
		Si uNum == 1 O uNum == 0 Entonces
			bin[i] = uNum;
		SiNo
			Escribir "Sorry but this can only keep binary numbers!";
			Escribir "End Of Program.";
			
			Para i=0 Hasta n-1 Con Paso 1 Hacer
				bin[i] = 0;
			FinPara
			
			// linear loop to show the array.
			Escribir " > The complete array is: ", Sin Saltar;
			Para i=0 Hasta n-1 Con Paso 1 Hacer
				Escribir "  ", bin[i], Sin Saltar;
			FinPara
			Escribir "";
			i = 0;
		FinSi
	FinPara
FinSubAlgoritmo

SubAlgoritmo binToDec(n)
	Definir bin, dec, i Como Entero;
	Definir c Como Real;
	Dimension bin[n];
	
	get_bin_from_user(bin, n);
	
	dec = 0;
	c = 128;
	
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Si bin[i] == 1 Entonces
			dec = dec + c;
		FinSi
		
		c = c / 2;
		Escribir dec, "   ", c;
	FinPara
	
	// linear loop to show the array.
	Escribir " > The complete array is: ", Sin Saltar;
	Para i=0 Hasta n-1 Con Paso 1 Hacer
		Escribir "  ", bin[i], Sin Saltar;
	FinPara
	Escribir "   which is equal to ", dec;
FinSubAlgoritmo

SubAlgoritmo decToBin()
	Definir dec, decBinModel, binArr, acum Como Entero;
	Escribir " > Please enter a decimal number not higher to 255 to convert to Binary: ";
	Leer dec;
	
	Si dec < 256 Entonces
		// Escribir "Correct values!";
		Dimension decBinModel[8];
		decBinModel[0] = 128;
		decBinModel[1] = 64;
		decBinModel[2] = 32;
		decBinModel[3] = 16;
		decBinModel[4] = 8;
		decBinModel[5] = 4;
		decBinModel[6] = 2;
		decBinModel[7] = 1;
		
		// COMPROBAR QUE EL NUMERO SEA MAYOR AL VALOER EN LA POSICIÓN PARA RESTARLO Y QUE EL RESIDUO SE PUEDA RESTAR CON OTRO VALOR EN EL NÚMERO.
		Definir i Como Entero;
		acum = dec;
		Para i=0 Hasta 7 Con Paso 1 Hacer
			Si acum >= decBinModel[i] Entonces
				acum = acum - decBinModel[i];
				decBinModel[i] = 1;
			Sino
				decBinModel[i] = 0;
			FinSi
		FinPara
		
		Escribir " > The binary number for ", dec, " is ", decBinModel[0], decBinModel[1], decBinModel[2], decBinModel[3], decBinModel[4], decBinModel[5], decBinModel[6],decBinModel[7];
		
		
		// FINALMENTE SE ESCRIBE EL ARRAY DEL BINARIO YA SEA POSICIÓN POR POSCIÓN O SE CREA UN NUEVO STRING.
		
	SiNo
		Escribir " Number is higher to 255, error!";
	FinSi
FinSubAlgoritmo

	