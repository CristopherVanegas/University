Proceso Funciones_Cadena
	Definir cad1,cad2 como cadena;
	Definir num como Entero;
	
	cad1<-"inform�tica";
	Escribir "La longitud de cad1 es ",longitud(cad1);
	Escribir "El primer car�cter de cad1 es ", subcadena(cad1,0,0);
	Escribir "El �ltimo car�cter de cad1 es ", subcadena(cad1,longitud(cad1)-1,longitud(cad1)-1);
	Escribir "La cad1 en may�sculas es ",mayusculas(cad1);
	
	cad2<-concatenar(cad1," es muy interesante");
	Escribir cad2;
	num<-ConvertirANumero("10");
	Escribir num;
	
	Escribir Concatenar("El n�mero es ",ConvertirATexto(num));
	Escribir "El n�mero es ",num;	
FinProceso