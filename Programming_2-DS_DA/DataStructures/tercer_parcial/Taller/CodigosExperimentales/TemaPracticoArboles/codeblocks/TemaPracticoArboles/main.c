/*   Est. Cristopher Vanegas   */
/*   Taller Practico           */
/*   Arboles Binarios          */
/*   Tienda de Souvenirs       */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct nodo {
    char descripcion[100];
    char codigo[4];
    float precio;
    int cantidad;

    struct nodo* izquierda;
    struct nodo* derecha;
} Nodo;

void continuar() {
    printf("\nContinuar (Press any key)...");
    getch();
}

Nodo* nuevo_nodo(char* descripcion, char* codigo, float precio, int cantidad) {
    /* reserva memoria */
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));

    /* define las variables */;
    strcpy(nodo->descripcion, descripcion);
    strcpy(nodo->codigo, codigo);
    nodo->precio = precio;
    nodo->cantidad = cantidad;

    /* inicializa las hojas como null*/
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

Nodo* insertar_nodo(Nodo* raiz, char* descripcion, char* codigo, float precio, int cantidad) {
    if (raiz == NULL) {
        return nuevo_nodo(descripcion, codigo, precio, cantidad);
    }
    // descripcion del nuevo nodo es menor a raiz, entonces va a la izquierda.
    if (strcmp(descripcion, raiz->descripcion) < 0) {
        raiz->izquierda = insertar_nodo(raiz->izquierda, descripcion, codigo, precio, cantidad);
    }
    // es mayor, va a la derecha.
    else {
        raiz->derecha = insertar_nodo(raiz->derecha, descripcion, codigo, precio, cantidad);
    }
    return raiz;
}


void anchura(Nodo *nodo) {
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
		printf(" > %s, %s, %.2f, %d\n", nodo->descripcion, nodo->codigo, nodo->precio, nodo->cantidad);
    }

	else if (nivel > 1) {
		printNivel(nodo->izquierda, nivel-1);
		printNivel(nodo->derecha, nivel-1);
	}
}



int alturaArbol(Nodo *nodo) {
	if (nodo == NULL) {
		return 0;
	}
	else {
		int alturaIzquierda = alturaArbol(nodo->izquierda);
		int alturaDerecha = alturaArbol(nodo->derecha);

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
		printf(" > %s, %s, %.2f, %d\n", nodo->descripcion, nodo->codigo, nodo->precio, nodo->cantidad);
		preorden(nodo->izquierda);
		preorden(nodo->derecha);
	}
}


void imprimir_inorden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    imprimir_inorden(nodo->izquierda);
    printf("%s, %s, %.2f, %d\n", nodo->descripcion, nodo->codigo, nodo->precio, nodo->cantidad);
    imprimir_inorden(nodo->derecha);
}


void imprimir_postorden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    imprimir_postorden(nodo->izquierda);
    imprimir_postorden(nodo->derecha);
    printf("%s, %s, %.2f, %d\n", nodo->descripcion, nodo->codigo, nodo->precio, nodo->cantidad);
}

void busquedaPorDescripcion(Nodo *nodo, char descripcion[100]) {
    if (nodo == NULL) {
        return;
    }
    busquedaPorDescripcion(nodo->izquierda, descripcion);
    if (strcmp(nodo->descripcion, descripcion) == 0) {
        printf("%s, %s, %.2f, %d\n", nodo->descripcion, nodo->codigo, nodo->precio, nodo->cantidad);
        return;
    }
    busquedaPorDescripcion(nodo->derecha, descripcion);
}


void menu()
{
	Nodo *raiz = NULL;

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
            printf("\t7) Salir\n");
            printf("Elige una opcion del menu: ");
            fflush(stdin);
            scanf("%d", &o);

        }
        while (o < 1 && o > 7);

        switch(o)
        {
        case 1:
        {
            char desc[100], codigo[4];
            int cantidad;
            float precio;

            printf(" > Ingrese la descripcion del producto: ");
            fflush(stdin);
            gets(&desc);
            // fgets(nodo->desc, 50, stdin);

            printf(" > Ingrese el codigo del producto: ");
            fflush(stdin);
            gets(&codigo);
            // fgets(nodo->cod, 4, stdin);

            printf(" > Ingrese el precio del producto: ");
            fflush(stdin);
            scanf("%f", &precio);

            printf(" > Ingrese la cantidad del producto: ");
            fflush(stdin);
            scanf("%d", &cantidad);

            raiz = insertar_nodo(raiz, desc, codigo, precio, cantidad);
        }
        break;

        case 2:
        {
            char descripcion[100];

            printf(" > Ingrese la descripcion del producto: ");
            fflush(stdin);
            gets(&descripcion);

            /*
            if (busquedaPorDescripcion(raiz, descripcion) == 1) {
                printf("\n El producto fue encontrado...\n");
            } else {
                printf("\n El producto no fue encontrado...\n");
            }
            */

            busquedaPorDescripcion(raiz, descripcion);
        }
        break;

        case 3: {
            anchura(raiz);
        } break;

        case 4:
        {
            preorden(raiz);
        }
        break;

        case 5: {
            imprimir_inorden(raiz);
        } break;

        case 6: {
            imprimir_postorden(raiz);
        }
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
