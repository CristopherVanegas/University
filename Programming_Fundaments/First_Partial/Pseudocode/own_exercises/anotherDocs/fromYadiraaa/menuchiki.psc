// Presenta el menu de opciones del programa
Funcion opc=menuPrincipal(tit,vector) 
	Definir opc Como Caracter
	Escribir tit
	Para indice<-1 Hasta 8 Hacer
		Escribir vector[indice]
	Fin Para
	Escribir "Elija Opcion[1..8]: " Sin Saltar
	Leer opc
	
FinFuncion
// Funcion sin parametros que suma dos numeros 
Funcion sumarSinparametros()
	Definir resp,num1,num2 Como Entero
	Escribir "Ingrese Numero1: " Sin Saltar
	Leer num1
	Escribir "Ingrese Numero2: " Sin Saltar
	Leer num2
	resp = num1+num2
	Escribir num1,"+",num2,"=",resp
FinFuncion
// recibe dos numeros y presenta la suma siempre y cuando el primero sea mayor que el segundo
Funcion sumarConParametros(num1,num2)
	Definir resp Como Entero
	Si num1 > num2 Entonces
		resp = num1+num2
		Escribir num1,"+",num2,"=",resp
	SiNo
		Escribir "No se pudo realizar la suma" 
		Escribir "El numero1: ",num1," debe ser mayor al numero2 ",num2
	Fin Si
FinFuncion
// Funcion sin parametros que elige que operacion realizar
Funcion operacionConParametros(signo,num1,num2)
	Definir resp Como Entero
	Si signo = "+" Entonces
		resp<-num1+num2
		Escribir resp, "=" num1, "+", num2
	SiNo
		Si signo= "-" Entonces
			Resp<-num1-num2
			Escribir resp, "=" num1, "-", num2
		SiNo
			Si signo= "*" Entonces
				Mul<-num1*num2
				Escribir resp, "=", num1, "*", num2
			SiNo
				Si signo= "/" Entonces
					resp<-num1/num2
					Escribir resp, "=", num1, "/", num2
				SiNo
					Escribir "Operacion no valida"
				Fin Si
			Fin Si
		Fin Si
	Fin Si
FinFuncion
// Funcion con parametros que elige el mayor entre 2 numeros
Funcion mayordedosnumerosConParametros(num1,num2)
	Definir resp Como Entero
	Si num1 > num2 Entonces
		resp = num1
		Escribir num1, " es mayor a: ", num2
	SiNo
		Escribir num2, " es mayor a ", num1
	FinSi
FinFuncion
// Funcion con parametros que elige el mayor entre 3 numeros
Funcion mayordetressnumerosConParametros(num1,num2, num3)
	Definir resp Como Entero
	Si num1 > num2 & num1 > num3 Entonces
		resp = num1
		Escribir num1, " es mayor a: ", num2 " y a ", num3
	SiNo
		Si num2 > num1 & num2 > num3 Entonces
			resp = num2
			Escribir num2, " es mayor a ", num1 " y ", num3
		SiNo
			Escribir num3, " es mayor a ", num1 " y ", num2
		FinSi	
	FinSi
		
FinFuncion
// Funcion con parametros que presenta una secuencia 
Funcion secuenciaConParametros(i,f,inc)
	Para indice<-i Hasta f Con Paso inc Hacer
			Escribir indice 
	FinPara
FinFuncion
Funcion secuenciaMultipleConParametros(i,f,mult)
	Para indice<-i Hasta f Hacer
		Si indice mod mult =0 Entonces
			Escribir indice
		Fin Si
	FinPara
FinFuncion
Algoritmo Menu
	// se crea un arreglo de diez elementos
	Dimension opciones[10]
	Definir opcion Como Caracter
	Definir numero1,numero2,numero3 Como Real
	Definir indice Como Entero
	opciones[1]="1) Suma1 de dos numeros"
    opciones[2]="2) Suma2 de dos numeros"
    opciones[3]="3) Operaciones Matematicas"
    opciones[4]="4) Mayor de dos numeros"
    opciones[5]="5) Mayor de tres numeros"
    opciones[6]="6) Presentar los numeros del 1 al 100"
    opciones[7]="7) Presentar los multiplos de una secuencia"
    opciones[8]="8) Salir"
	opcion=""
	Mientras opcion <> "8" Hacer
	  Borrar Pantalla		
	  opcion=menuPrincipal("******* M E N U  P R I N C I P A L ********",opciones) 
	  Borrar Pantalla
	  Segun opcion Hacer
		"1":
			Escribir "******* S U M A  D E  D O S  N U M E R O S *******"
			sumarSinParametros()
			Escribir "Espere un momento para regrezar al Menu Principal..." 
			Esperar 3 Segundos
		"2":
			Escribir "******* S U M A  N U M E R O 1  M A Y O R  A L  N U M E R O 2 *******"
			Escribir "Ingrese Numero1: " Sin Saltar
			Leer numero1
			Escribir "Ingrese Numero2: " Sin Saltar
			Leer numero2
			sumarConParametros(numero1,numero2)
			Escribir "Presione cualquier tecla para continuar..." 
			Esperar Tecla
			//sumarConParametros(10,8) s eenvia valores quemados
		"3":
			Escribir "******** O P E R A C I O N E S  M A E T E M A T I C A S ********"
			Escribir "Ingrese signo" Sin Saltar
			Leer signo
			Escribir "Ingrese Numero1: " Sin Saltar
			Leer numero1
			Escribir "Ingrese Numero2: " Sin Saltar
			Leer numero2
			operacionConParametros(signo,numero1,numero2)
			Escribir "Presione cualquier tecla para continuar..." 
			Esperar Tecla
		"4":
			Escribir "******** M A Y O R  D E  D O S  N U M E R O S********"
			Escribir "Ingrese Numero1: " Sin Saltar
			Leer numero1
			Escribir "Ingrese Numero2: " Sin Saltar
			Leer numero2
			mayordedosnumerosConParametros(numero1,numero2)
			Escribir "Presione cualquier tecla para continuar..." 
			Esperar Tecla
		"5" :
			Escribir "******** M A Y O R  D E  T R E S  N U M E R O S********"
			Escribir "Ingrese Numero1: " Sin Saltar
			Leer numero1
			Escribir "Ingrese Numero2: " Sin Saltar
			Leer numero2
			Escribir "Ingrese Numero3: " Sin Saltar
			Leer numero3
			mayordetressnumerosConParametros(numero1,numero2,numero3)
			Escribir "Presione cualquier tecla para continuar..." 
			Esperar Tecla
		"6" :
			Escribir "*****C A N T I D A D  D E   N U M E R O S*******"
			Escribir "Ingrese inicio de secuencia: " Sin Saltar
			Leer i
			Escribir "Ingrese fin de secuencia: " Sin Saltar
			Leer f
			Escribir "Ingrese incremento " Sin Saltar
			Leer mult
			secuenciaConParametros(i,f,mult)
			Escribir "Presione cualquier tecla para continuar..." 
			Esperar Tecla
		"7" :
			Escribir "*****C A N T I D A D  D E   N U M E R O S*******"
			Escribir "Ingrese inicio de secuencia: " Sin Saltar
			Leer i
			Escribir "Ingrese fin de secuencia: " Sin Saltar
			Leer f
			Escribir "Ingrese multiplo " Sin Saltar
			Leer mult
			secuenciaMultipleConParametros(i,f,mult)
			Escribir "Presione cualquier tecla para continuar..." 
			Esperar Tecla
		"8":
			Escribir "El programa ha Finalizado..."	
		De Otro Modo:
			Escribir "Opcion Incorrecta"
	   Fin Segun
    FinMientras
	
  //sumarSinParametros()	
FinAlgoritmo
