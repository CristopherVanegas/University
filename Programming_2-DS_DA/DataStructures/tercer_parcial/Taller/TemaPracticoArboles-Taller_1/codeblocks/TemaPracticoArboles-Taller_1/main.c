#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
    struct Nodo *der;
    struct Nodo *izq;

    char desc[50];
    char cod[4];
    int cant;
    float precio;
} Nodo;

void continuar() {
    printf("\nContinuar (Press any key)...");
    getch();
}


Nodo *nuevoNodo() {
	// Solicitar memoria
    Nodo *nodo = (struct Nodo *) malloc(sizeof(Nodo));

	/* -Asignar las propiedades e inicializo las hojas- */

	printf(" > Ingrese la descripcion del producto: ");
	fflush(stdin);
	gets(&nodo->desc);
	// fgets(nodo->desc, 50, stdin);

	printf(" > Ingrese el codigo del producto: ");
	fflush(stdin);
	gets(&nodo->cod);
	// fgets(nodo->cod, 4, stdin);

	printf(" > Ingrese el precio del producto: ");
	fflush(stdin);
	scanf("%f", &nodo->precio);

	printf(" > Ingrese la cantidad del producto: ");
	fflush(stdin);
	scanf("%d", &nodo->cant);

	nodo->izq = nodo->der = NULL;

	/* ------------------------------------------------ */
	return nodo;
}

void insertar(Nodo **nodo, Nodo *nNodo) {
    if (nNodo == NULL) {
        nNodo = nuevoNodo();
    }

	// nuevo nodo?
	if (*nodo == NULL) {
		*nodo = nNodo;
	}

	// Izquierda o Derecha?
	// Si es mayor va a la derecha
	else if (strcmp(nNodo->desc, (*nodo)->desc) > 0) {
		// Tienes espacio a la derecha?
		if ((*nodo)->der == NULL) {
			(*nodo)->der = nNodo;
		} else {
			// Si la derecha ya esta ocupada, recursividad ;)
			insertar(&((*nodo)->der), nNodo);
		}
	}
	else if (strcmp(nNodo->desc, (*nodo)->desc) < 0) {
		// Si no, a la izquierda
		if ((*nodo)->izq == NULL) {
			(*nodo)->izq = nNodo;
		} else {
			// Si la izquierda ya esta ocupada, recursividad ;)
			insertar(&((*nodo)->izq), nNodo);
		}
	}
}


void anchura(Nodo **nodo) {
	int altura = alturaArbol(*nodo);
	int i;
	for (i = 1; i <= altura; i++) {
		printNivel(nodo, i);
	}
}


void printNivel(Nodo *nodo, int nivel) {
	if (nodo == NULL) {
		return;
	}

	if (nivel == 1) {
		printf(" > %d ", nodo->desc);
	}

	else if (nivel > 1) {
		printNivel(nodo->izq, nivel-1);
		printNivel(nodo->der, nivel-1);
	}
}


int alturaArbol(Nodo *nodo) {
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


void preorden(Nodo *nodo) {
	if (nodo != NULL) {
		printf(" > %s \n", nodo->desc);
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}


void menu()
{
	struct Nodo **raiz = NULL;

    for (;;)
    {
        int o;

        do
        {
            system("cls");
            printf("MENU TIENDA DE SOUVENIRS ECOTEC:\n");
            printf("\t1) Compra a proveedores (Ingreso al inventario)\n");
            printf("\t2) Busqueda por descripcion de producto\n");
            printf("\t3) Consultar todos los productos en anchura\n");
            printf("\t4) Consultar todos los productos en pre-orden'\n");
            printf("\t5) Consultar todos los productos en in-orden'\n");
            printf("\t6) Consultar todos los productos en post-orden'\n");
            printf("\t7) Salir'\n");
            printf("Elige una opcion del menu: ");
            fflush(stdin);
            scanf("%d", &o);

        }
        while (o < 1 && o > 7);

        switch(o)
        {
        case 1:
        {
            insertar(&raiz, NULL);
        }
        break;

        case 2:
        {
            // eliminoPorCod(&raiz);
        }
        break;

        case 3: {
            anchura(&raiz);
        } break;

        case 4:
        {
            preorden(*raiz);
        }
        break;

        case 7:
        {
            system("cls");
            exit(1);
        }
        break;
        }

        continuar();
    }
}


int main(int argc, char *argv[]) {
	menu();
	return 0;
}
