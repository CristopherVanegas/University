Proceso main
	Definir opt Como Entero;
	Escribir "Seleccione 1 para nMenor y 2 para nMayor: ";
	Escribir " [1] N�mero menor ";
	Escribir " [2] N�mero mayor ";
	Escribir "";
	Escribir ">>> Respuesta: ";
	Leer opt;
	Escribir "";
	Escribir "";
	
	Segun opt Hacer
		1:
			numeroMenor();
		2:
			numeroMayor();

		De Otro Modo:
			Escribir " ---- �Opci�n no valida! ---- ";
	FinSegun
FinProceso

SubProceso numeroMayor()
	Definir n, gNum, num, c Como Entero;
	Escribir " > Ingresar cuantos n�meros ingresar�: ";
	Leer n;
	Escribir "";
	
	gNum = 0;
	Para c = 1 Hasta n Con Paso 1 Hacer
		Escribir " | Ingresar un n�mero: ";
		Leer num;
			
		Si gNum < num Entonces
			gNum = num;
		FinSi
			
		Si (c == n) Entonces
			Escribir "N�meros maximos.";
		FinSi
	FinPara
	Escribir "N�mero mayor: ", gNum;
	Escribir "";
FinSubProceso

SubProceso numeroMenor()
	Definir n, mNum, num, c Como Entero;
	Escribir " > Ingresar cuantos n�meros ingresar�: ";
	Leer n;
	Escribir "";
	
	// Primer n�mero para evaluar los dem�s.
	Escribir " | Ingresar su primer n�mero: ";
	Leer num;
	mNum = num;
	
	// Loop para evaluar los dem�s con n-1 porque anteriormente se pidi� uno para comenzar.
	Para c = 1 Hasta n-1 Con Paso 1 Hacer
		Escribir " | Ingresar un n�mero: ";
		Leer num;
		
		Si mNum > num Entonces
			mNum = num;
		FinSi
			
		Si (c == n) Entonces
			Escribir "N�meros maximos!";
		FinSi
	FinPara
	
	// Resultado
	Escribir "N�mero menor: ", mNum;
	Escribir "";
FinSubProceso
