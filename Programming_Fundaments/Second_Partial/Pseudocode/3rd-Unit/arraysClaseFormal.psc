Algoritmo arrayClaseFormal
	main_menu();
FinAlgoritmo

SubAlgoritmo main_menu()
	Definir opt Como Entero;
	Escribir "Welcome to the array program!";
	Escribir "Please choose one of these methods: ";
	Escribir " [1] randomNums()";
	Escribir " [2] randomNumsLoop()";
	Escribir " [3] enterData()";
	Escribir " [4] decimalToBin()";
	Escribir " [5] parOrNotTenFirstNumbers();";
	Leer opt;
	
	Segun opt Hacer
		1:
			randomNums();
		2:
			randomNumsLoop();
		3:
			enterData();
		4:
			decimalToBin();
		5:
			parOrNotTenFirstNumbers();
			
		De Otro Modo:
			Escribir "No correct option!";
	FinSegun
	
FinSubAlgoritmo

SubAlgoritmo randomNums()
	Definir numArr, i Como Entero;
	Dimension numArr[5];
	
	numArr[0] = Aleatorio(0, 100);
	numArr[1] = Aleatorio(0, 100);
	numArr[2] = Aleatorio(0, 100);
	numArr[3] = Aleatorio(0, 100);
	numArr[4] = Aleatorio(0, 100);
	
	Escribir " > The complete array is: ";
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir " > Index value for array: ", numArr[i];
	FinPara
FinSubAlgoritmo

SubAlgoritmo randomNumsLoop()
	Definir numArr, i Como Entero;
	Dimension numArr[5];
	
	Para i=0 Hasta 4 Con Paso 1 Hacer
		numArr[i] = Aleatorio(0, 100);
	FinPara
	
	Escribir " > The complete array using random ints is: ";
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir " > Index value for array: ", numArr[i];
	FinPara
FinSubAlgoritmo

SubAlgoritmo enterData()
	Definir numArr, i Como Entero;
	Dimension numArr[5];
	
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir " > Please enter a value for index [ ", i, " ]: ";
		Leer numArr[i];
	FinPara
	
	Escribir " > The complete array is: ";
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir numArr[i];
	FinPara
FinSubAlgoritmo

SubAlgoritmo decimalToBin()
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

SubAlgoritmo parOrNotTenFirstNumbers()
	Definir numArr, i Como Entero;
	Dimension numArr[10];
	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		numArr[i] = Aleatorio(0, 100);
	FinPara
	
	Para i=0 Hasta 9 Con Paso 1 Hacer
		Si (numArr[i] % 2 == 0) Entonces
			Escribir " > ", numArr[i], " It is pair!";
		SiNo
			Escribir " > ", numArr[i], " It is not pair!";
		FinSi
	FinPara
	
	Escribir " > The complete array using random ints is: ";
	Para i=0 Hasta 4 Con Paso 1 Hacer
		Escribir " > Index value for array: ", numArr[i];
	FinPara
FinSubAlgoritmo
	