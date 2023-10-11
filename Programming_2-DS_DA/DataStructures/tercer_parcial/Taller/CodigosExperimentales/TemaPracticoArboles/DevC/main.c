#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Nodo {
    struct Nodo *der;
    struct Nodo *izq;
    
    char desc[50];
    int cod;
    float precio;
};


struct Nodo *nuevoNodo(char str[50]) {
	// Solicitar memoria
	size_t tamanioNodo = sizeof(struct Nodo);
	struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
	
	// Asignar la descripcion e iniciar hojas
	/*
	printf(" > Ingrese la descripcion del producto: ");
	fflush(stdin);
	fgets(nodo->desc, 50, stdi);
	*/
	
	strcpy(nodo->desc, str);
	// nodo->desc = str;		
	nodo->izq = nodo->der = NULL;
	return nodo;
}

void insertar(struct Nodo *nodo, char str[50]) {
	// nuevo nodo?
	if (nodo == NULL) {
		nodo = nuevoNodo(str);
	}
	
	// Izquierda o Derecha?
	// Si es mayor va a la derecha
	else if (strcmp(str, nodo->desc) > 0) {
		// Tienes espacio a la derecha?
		if (nodo->der == NULL) {
			nodo->der = nuevoNodo(str);
		} else {
			// Si la derecha ya esta ocupada, recursividad ;)
			insertar(nodo->der, str);
		}
	}
	else if (strcmp(str, nodo->desc) < 0){
		// Si no, a la izquierda
		if (nodo->izq == NULL) {
			nodo->izq = nuevoNodo(str);
		} else {
			// Si la izquierda ya esta ocupada, recursividad ;)
			insertar(nodo->izq, str);
		}
	}
}


/*
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
		printf(" > %d ", nodo->desc);
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
*/


void preorden(struct Nodo *nodo) {
	if (nodo != NULL) {
		printf(" > %d ", nodo->desc);
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}


void menu()
{
	struct Nodo *raiz = NULL;
	
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
        	char str[50];
        	printf(" > Ingrese str: ");
        	fflush(stdin);
        	fgets(str, 50, stdin);
        	printf("\n");
            insertar(raiz, str);
        }
        break;

        case 2:
        {
            // eliminoPorCod(&inicio);
        }
        break;

        case 4:
        {
            preorden(raiz);
        }
        break;

        case 7:
        {
            system("cls");
            exit(1);
        }
        break;
        }

        getch();
    }
}


int main(int argc, char *argv[]) {
	menu();
	return 0;
}
