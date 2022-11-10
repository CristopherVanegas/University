Proceso cgg
	Definir num, bi, base, resi Como Real;
	base=1;
	bi=0;
	Escribir "Ingresar numero";
	Leer num;
	Mientras num>0 Hacer
		resi = num%2;
		bi= bi+resi*base;
		num = trunc(num/2);
		base=base*10;
	FinMientras
	Escribir bi;
FinProceso
