// Create a programa to send values by parameters in threads.
Funcion escribirMensaje(param1)
	Escribir param1;
FinFuncion

Algoritmo subProcesos
	Definir t Como Caracter
	Leer t;
	escribirMensaje(t);
FinAlgoritmo
