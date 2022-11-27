SubProceso capLettersRecursion(nP Por Valor, p Por Valor, longitudP, i)	
	Si i < longitudP Entonces
		Si i == 0 Y Subcadena(p, i, i) <> " " Entonces
			nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
		SiNo
			Si Subcadena(p, i-1, i-1) == " " Y Subcadena(p, i, i) <> " " Y Subcadena(p, i+1, i+1) <> " " Entonces
				nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
			SiNo
				nP = Concatenar(nP, Minusculas(Subcadena(p, i, i)));
			FinSi
		FinSi
		
		i =  i + 1;
		capLettersRecursion(nP, p, longitudP, i);
	FinSi
FinSubProceso

Proceso main
	Definir p, nP Como Caracter;
	p = " hello world";
	nP = "";
	capLettersRecursion(nP, p, Longitud(p), 0);
	
	Escribir "Original Phrase: ", p;
	Escribir "Phrase with cap letters: ", nP;
	
FinProceso
