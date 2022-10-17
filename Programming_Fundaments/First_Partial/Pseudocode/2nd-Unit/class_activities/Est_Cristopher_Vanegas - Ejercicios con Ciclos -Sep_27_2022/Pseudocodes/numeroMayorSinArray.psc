Proceso main
	Definir opt Como Entero;
	Escribir "Seleccione 1 para nMenor y 2 para nMayor: ";
	Escribir " [1] Número menor ";
	Escribir " [2] Número mayor ";
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
			Escribir " ---- ¡Opción no valida! ---- ";
	FinSegun
FinProceso

SubProceso numeroMayor()
	Definir n, gNum, num, c Como Entero;
	Escribir " > Ingresar cuantos números ingresará: ";
	Leer n;
	Escribir "";
	
	gNum = 0;
	Para c = 1 Hasta n Con Paso 1 Hacer
		Escribir " | Ingresar un número: ";
		Leer num;
			
		Si gNum < num Entonces
			gNum = num;
		FinSi
			
		Si (c == n) Entonces
			Escribir "Números maximos.";
		FinSi
	FinPara
	Escribir "Número mayor: ", gNum;
	Escribir "";
FinSubProceso

SubProceso numeroMenor()
	Definir n, mNum, num, c Como Entero;
	Escribir " > Ingresar cuantos números ingresará: ";
	Leer n;
	Escribir "";
	
	// Primer número para evaluar los demás.
	Escribir " | Ingresar su primer número: ";
	Leer num;
	mNum = num;
	
	// Loop para evaluar los demás con n-1 porque anteriormente se pidió uno para comenzar.
	Para c = 1 Hasta n-1 Con Paso 1 Hacer
		Escribir " | Ingresar un número: ";
		Leer num;
		
		Si mNum > num Entonces
			mNum = num;
		FinSi
			
		Si (c == n) Entonces
			Escribir "Números maximos!";
		FinSi
	FinPara
	
	// Resultado
	Escribir "Número menor: ", mNum;
	Escribir "";
FinSubProceso
