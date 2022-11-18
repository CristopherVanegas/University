// ///////////////////////////////////////// //
// ----- ESTUDIANTE CRISTOPHER VANEGAS ----- //
// ///////////////////////////////////////// //
Proceso main
	Definir name, matrix, pToken, cToken Como Caracter;
	Definir m, n, tokenOpt, winner Como Entero;
	m = 3; n = 3;
	Dimension matrix[m, n];
	
	// get name to show in future the score.
	name = greeting();
	fullfill(matrix, m, n);
	show(matrix, m, n);
	
	// menu para elegir ficha X || O
	Repetir
		Escribir "";
		Escribir "Por favor elija una ficha X o O: ";
		Escribir " [1] X";
		Escribir " [2] O";
		Leer tokenOpt;
		
		Si (tokenOpt < 1) O (tokenOpt > 2) Entonces
			Escribir "Error opción incorrecta...";
			Escribir "";
		FinSi
	Hasta Que (tokenOpt == 1) O (tokenOpt == 2)
	
	// game loop
	Segun tokenOpt Hacer
		1:
			pToken = "X";
			cToken = "O";
			
			Repetir
				play(matrix, m, n, pToken, cToken);		// Starts first
				winner = check(matrix, m, n, pToken, cToken);
				Limpiar Pantalla;
			Hasta Que ((winner == 1) O (winner == 0))
			
		2:
			pToken = "O";
			cToken = "X";
			
			Repetir
				play(matrix, m, n, pToken, cToken);		// Starts second
				winner = check(matrix, m, n, pToken, cToken);
				Limpiar Pantalla;
			Hasta Que ((winner == 1) O (winner == 0))
	FinSegun
	
	
	// Says who won
	Si winner == 1 Entonces
		Escribir "El ganador es ", name;
	SiNo
		Si winner == 0 Entonces
			Escribir "El ganador es la computadora, suerte en la próxima ;)";
		FinSi
	FinSi
FinProceso


SubAlgoritmo val = check(matrix, m, n, pToken, mToken)
	Definir val Como Entero;
	val = 2;	// initializates
	
	// verifica lineas horizontales
//	val = checkHorizontalLines(matrix, m, n, pToken, mToken);
	Segun checkHorizontalLines(matrix, m, n, pToken, mToken) Hacer
		1:
			val = 1;	// PLAYER WON
		0:
			val = 0;	// COMPUTER WON
	FinSegun
	
	// verifica lineas verticales
//	val = checkVerticalLines(matrix, m, n, pToken, mToken);
	Segun checkVerticalLines(matrix, m, n, pToken, mToken) Hacer
		1:
			val = 1;	// PLAYER WON
		0:
			val = 0;	// COMPUTER WON
	FinSegun
	
	// verifica diagonales
//	val = checkDiagonals(matrix, pToken, mToken);
	Segun checkHorizontalLines(matrix, m, n, pToken, mToken) Hacer
		1:
			val = 1;	// PLAYER WON
		0:
			val = 0;	// // COMPUTER WON
	FinSegun
FinSubAlgoritmo

SubAlgoritmo val = checkDiagonals(matrix, pToken, mToken)
	Definir val, pCont, mCont Como Entero;
	val = 2;	// initializates
	
	// ////////////////////////////////////////////////////////////////////////////////////////////// //
	// ///////////////////////////// CHECKS FROM LEFT TO RIGHT DIAGONAL ///////////////////////////// //
	pCont = 0;
	mCont = 0;
	
	Si (matrix[0, 0] == pToken) Y (matrix[1, 1] == pToken) Y (matrix[2, 2] == pToken) Entonces
		val = 1;				// Player wins
	SiNo
		Si (matrix[0, 0] == mToken) Y (matrix[1,1] == mToken) Y (matrix[2, 2] == mToken) Entonces
			val = 0;			// Computer wins
		FinSi
	FinSi
	
	// ////////////////////////////////////////////////////////////////////////////////////////////// //
	// ////////////////////////////////////////////////////////////////////////////////////////////// //


	// ////////////////////////////////////////////////////////////////////////////////////////////// //
	// ///////////////////////////// CHECKS FROM RIGHT TO LEFT DIAGONAL ///////////////////////////// //
	pCont = 0;
	mCont = 0;
	
	Si (matrix[0, 2] == pToken) Y (matrix[1,1] == pToken) Y (matrix[0, 2] == pToken) Entonces
		val = 1;				// Player wins
	SiNo
		Si (matrix[0, 2] == mToken) Y (matrix[1,1] == mToken) Y (matrix[0, 2] == mToken) Entonces
			val = 0;			// Computer wins
		FinSi
	FinSi
	// ////////////////////////////////////////////////////////////////////////////////////////////// //
	// ////////////////////////////////////////////////////////////////////////////////////////////// //
FinSubAlgoritmo


SubAlgoritmo val = checkVerticalLines(matrix, m, n, pToken, mToken)
	Definir val, pCont, mCont, i, j Como Entero;
	val = 2;	// initializates
	
	// Verifica lineas verticales
	Para j=0 Hasta n-1 Con Paso 1 Hacer	// itera filas
		pCont = 0;	// set player's counter to 0
		mCont = 0;	// set machine's counter to 0
		
		Para i=0 Hasta m-1 Con Paso 1 Hacer	// itera columnas
			Si matrix[i, j] == pToken  Entonces
				pCont = pCont + 1;						// add 1 to the player counter if a player's token was found.
			SiNo
				Si matrix[i, j] == mToken Entonces
					mCont = mCont + 1;					// add 1 to the machine counter if a machine's token was found.
				FinSi
			FinSi
		FinPara
		
		// check for winner
		Si pCont == 3 Entonces
			val = 1;							// player wins
		SiNo
			Si mCont == 3 Entonces
				val = 0;							// machine wins
			FinSi
		FinSi
	FinPara
FinSubAlgoritmo


SubAlgoritmo val = checkHorizontalLines(matrix, m, n, pToken, mToken)
	Definir val, pCont, mCont, i, j Como Entero;
	val = 2;	// initializates
	
	// verifica lineas horizontales
	Para i=0 Hasta m-1 Con Paso 1 Hacer	// itera filas
		pCont = 0;	// set player's counter to 0
		mCont = 0;	// set machine's counter to 0
		
		Para j=0 Hasta n-1 Con Paso 1 Hacer	// itera columnas
			Si matrix[i, j] == pToken Entonces
				pCont = pCont + 1;						// add 1 to the player counter if a player's token was found.
			SiNo
				Si matrix[i, j] == mToken Entonces
					mCont = mCont + 1;					// add 1 to the machine counter if a machine's token was found.
				FinSi
			FinSi
		FinPara
		
		// check for winner
		Si pCont == 3 Entonces
			val = 1;							// player wins
		SiNo
			Si mCont == 3 Entonces
				val = 0;							// machine wins
			FinSi
		FinSi
	FinPara
FinSubAlgoritmo


SubAlgoritmo play(matrix, m, n, pToken, cToken)
	Definir position Como Entero;
	
	// If PLAYER TOKEN is O, COMPUTER starts FIRST	//
	Si pToken == "O" Entonces
		setComputerToken(matrix, m, n, cToken);
	FinSi
	
	
	show(matrix, m, n);																		// Show matrix
	Escribir "Estás jugando con fichas ", pToken;
	Escribir "Para jugar debe enviar un número como se muestra en la matriz de al lado!";		// Ask player for a position
	Leer position;
	
	// verifies if the number (position) is valid!
	Mientras (position > 9) O (position < 1) Hacer
		Escribir "";
		Escribir "Por favor ingresa una posición valida!";
	FinMientras
	
	setToken(matrix, m, n, position, pToken);		// set the PLAYER TOKEN in the matrix
	
	
	// If PLAYER TOKEN is X, COMPUTER starts SECOND	//
	Si (pToken == "X") Entonces
		setComputerToken(matrix, m, n, cToken);
	FinSi
FinSubAlgoritmo


SubAlgoritmo setComputerToken(matrix, m, n, cToken)
	Definir i, j Como Entero;
	
	i = Aleatorio(0, m-1);
	j = Aleatorio(0, n-1);
	
	Mientras (matrix[i, j] <> "-") Hacer
		i = Aleatorio(0, m-1);
		j = Aleatorio(0, n-1);
	FinMientras
	
	Si (matrix[i, j] == "-") Entonces
		matrix[i, j] = cToken;
	FinSi
	
//	Repetir
//		Si (matrix[i, j] == "-") Entonces
//			matrix[i, j] = cToken;
//		FinSi
//	Hasta Que (matrix[i, j] = "-")
FinSubAlgoritmo


SubAlgoritmo setToken(matrix, m, n, position, token)
	Segun position Hacer
		1:
			Si matrix[0, 0] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[0, 0] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		2:
			Si matrix[0, 1] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[0, 1] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		3:
			Si matrix[0, 2] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[0, 2] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		4:
			Si matrix[1, 0] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[1, 0] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		5:
			Si matrix[1, 1] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[1, 1] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		6:
			Si matrix[1, 2] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[1, 2] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		7:
			Si matrix[2, 0] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[2, 0] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		8:
			Si matrix[2, 1] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[2, 1] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
		9:
			Si matrix[2, 2] == "-" Entonces	// If it is UNOCCUPIED it is gonna be set the value entered by PLAYER.
				matrix[2, 2] = token;
			SiNo
				Escribir "Esta casilla ya está ocupada, selecciona otra!";
			FinSi
	FinSegun
FinSubAlgoritmo


SubAlgoritmo name = greeting()
	Definir name Como Caracter;
	Escribir "Welcome to Three and Mark!";
	Escribir "Please enter your name: ", Sin Saltar;
	Leer name;
	Escribir "Ok ", name, " lets start the game!";
	Esperar 1 Segundos;
	Limpiar Pantalla;
FinSubAlgoritmo


SubAlgoritmo fullfill(matrix, m, n)
	Definir userAttempt, i , j Como Entero;
	
//	fullfill the matrix
	Para i = 0 Hasta m-1 Con Paso 1 Hacer
		Para j = 0 Hasta n-1 Con Paso 1 Hacer
			matrix[i, j] = "-";
		FinPara
	FinPara
FinSubAlgoritmo


SubAlgoritmo show(matrix, m, n)
	//	shows the matrix - just for testing
	Definir i, j Como Entero;
	
	Escribir "";
	Para i = 0 Hasta m-1 Con Paso 1 Hacer	//	rows
		Escribir "   |", Sin Saltar;
		Para j = 0 Hasta n-1 Con Paso 1 Hacer	// columns
			Escribir "   ", matrix[i, j], "   |", Sin Saltar;
		FinPara
		
		Segun i Hacer
			0:
				Escribir "     |   1   |   2   |   3   |   ";
			1:
				Escribir "     |   4   |   5   |   6   |   ";
			2:
				Escribir "     |   7   |   8   |   9   |   ";
		FinSegun
	FinPara
	
FinSubAlgoritmo

