#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

struct Nodo *nuevoNodo(int dato) {
	// Solicitar memoria
	size_t tamanioNodo = sizeof(struct Nodo);
	struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);

	// Asignar el dato e iniciar hojas
	nodo->dato = dato;
	nodo->izq = nodo->der = NULL;
	return nodo;
}

void insertar(struct Nodo *nodo, int dato) {
	// Izquierda o Derecha?
	// Si es mayor va a la derecha
	if (dato > nodo->dato) {
		// Tienes espacio a la derecha?
		if (nodo->der == NULL) {
			nodo->der = nuevoNodo(dato);
		} else {
			// Si la derecha ya esta ocupada, recursividad ;)
			insertar(nodo->der, dato);
		}
	}
	else {
		// Si no, a la izquierda
		if (nodo->izq == NULL) {
			nodo->izq = nuevoNodo(dato);
		} else {
			// Si la izquierda ya esta ocupada, recursividad ;)
			insertar(nodo->izq, dato);
		}
	}
}

void anchura(struct Nodo *nodo) {
	int altura = alturaArbol(nodo);
	int i;
	for (i = 1; i <= altura; i++) {
		printNivel(nodo, i);
	}
}

void printNivel(struct Nodo *nodo, int nivel) {
	if (nodo == NULL) {
		return;
	}

	if (nivel == 1) {
		printf(" > %d ", nodo->dato);
	}

	else if (nivel > 1) {
		printNivel(nodo->izq, nivel-1);
		printNivel(nodo->der, nivel-1);
	}
}

int alturaArbol(struct Nodo *nodo) {
	if (nodo == NULL) {
		return 0;
	}
	else {
		int alturaIzquierda = alturaArbol(nodo->izq);
		int alturaDerecha = alturaArbol(nodo->der);

		if (alturaIzquierda > alturaDerecha) {
			// printf("Nivel...%d", alturaIzquierda);
			return alturaIzquierda + 1;
		}

		else {
			// printf("Nivel...%d", alturaDerecha);
			return alturaDerecha + 1;
		}
	}
}

void preorden(struct Nodo *nodo) {
	if (nodo != NULL) {
		printf(" > %d ", nodo->dato);
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}

void inorden(struct Nodo *nodo) {
	if (nodo != NULL) {
		inorden(nodo->izq);
		printf(" > %d ", nodo->dato);
		inorden(nodo->der);
	}
}

void postorden(struct Nodo *nodo) {
	if (nodo != NULL) {
		postorden(nodo->izq);
		postorden(nodo->der);
		printf(" > %d ", nodo->dato);
	}
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Nodo *raiz = nuevoNodo(9);
	insertar(raiz, 20);
	insertar(raiz, 3);
	insertar(raiz, -2);
	insertar(raiz, 97);
	insertar(raiz, 90);
	insertar(raiz, 15);
	insertar(raiz, 1);
	insertar(raiz, -5);
	insertar(raiz, 10);
	insertar(raiz, 2);

	printf("\n Imprimiendo en anchura\n");
	anchura(raiz);
	printf("\n Imprimiendo en preorden\n");
	preorden(raiz);
	printf("\n Imprimiendo en inorden\n");
	inorden(raiz);
	printf("\n Imprimiendo en postorden\n");
	postorden(raiz);

	return 0;
}
