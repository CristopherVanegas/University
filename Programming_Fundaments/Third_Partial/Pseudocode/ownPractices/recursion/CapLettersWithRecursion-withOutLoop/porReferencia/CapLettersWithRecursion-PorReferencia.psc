// ////////////////////////////////////////////// //
// 			  Est. Cristopher Vanegas			  //
//               Date: Nov 24 2022                //
// ////////////////////////////////////////////// //

SubProceso nP = withoutLoopForCapLetters(nP Por Referencia, p Por Referencia, longitudP, i) 
	Si i < longitudP Entonces
		Si i == 0 Y Subcadena(p, i, i) <> " " Entonces
			nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
		SiNo
			Si Subcadena(p, i-1, i-1) == " " Y Subcadena(p, i, i) <> " " Y Subcadena(p, i+1, i+1) <> " " Entonces
				nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
			SiNo
				Si Subcadena(p, i-1, i-1) == " " Y Subcadena(p, i, i) <> " " Y Subcadena(p, i+1, i+1) == " " Entonces
					nP = Concatenar(nP, Mayusculas(Subcadena(p, i, i)));
				SiNo
					nP = Concatenar(nP, Minusculas(Subcadena(p, i, i)));
				FinSi
			FinSi
		FinSi
		
		i =  i + 1;
		np = withoutLoopForCapLetters(nP, p, longitudP, i);
	FinSi
FinSubProceso

Proceso main
	Definir p, nP Como Caracter;
	Escribir "Please enter a phrase you wanna add Cap Letters: ", Sin Saltar;
	Leer p;
//	p = " hello world";
	nP = "";
	nP = withoutLoopForCapLetters(nP, p, Longitud(p), 0);
	
	Escribir "Original Phrase: ", p;
	Escribir "Phrase with cap letters: ", nP;
FinProceso
