// Create a programa to send values by parameters in threads.
Funcion escribirMensaje(param1)
	Escribir " [-] El parámetro que se envió fue: ", param1;
FinFuncion

Algoritmo subProcesos
	Definir mensaje Como Caracter
	Leer mensaje;
	escribirMensaje(mensaje);
FinAlgoritmo
