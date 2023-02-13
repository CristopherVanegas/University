Proceso crecimientoBacterial
	Definir t Como Entero;
	Escribir "Ingrese el tiempo t: ";
	Leer t;
	Escribir "Q vale ", calc(t), " en un tiempo ", t;
FinProceso

SubProceso Q = calc(t)
	Definir q Como Real;
	q = ((3^t)/ln(3)) + 9.090;
FinSubProceso
	