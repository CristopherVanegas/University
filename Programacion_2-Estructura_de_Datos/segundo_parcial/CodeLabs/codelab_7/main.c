//   Codelab 7 - Lista Enlazada Simple   //
//   Est. Cristopher Vanegas             //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//definir un estructura }para el nodo que contenga un valor y un puntero al siguiente nodo:
struct Nodo
{
    int valor;
    struct Nodo *siguiente;
};

//crear una funcion para crear un nuevo nodo
//que reciba como parametro el valor a almacenar en el nodo y devuelva un puntero al nodo creado:
struct Nodo *crear_nodo(int valor)
{
    struct Nodo *nuevo_nodo =malloc(sizeof(struct Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

//crear una funcion para agregar un nuevo nodo a la lista enlazada
//que reciba como parametros un puntero a la cabeza de la lista y el valor a agregar:
void agregar_nodo (struct Nodo **cabeza, int valor)
{
    struct Nodo *nuevo_nodo= crear_nodo(valor);
    if (*cabeza== NULL)
    {
        *cabeza = nuevo_nodo;
    }
    else
    {
        struct Nodo *ultimo_nodo = *cabeza;
        while (ultimo_nodo->siguiente !=NULL)
            ultimo_nodo = ultimo_nodo->siguiente;
        ultimo_nodo->siguiente= nuevo_nodo;
    }
}

//crear una funcion para imprimir la lista enlazada que reciba como parametro un puntero a la cabeza de la lista
void imprimir_lista(struct Nodo *cabeza)
{
    struct Nodo *nodo_actual = cabeza;
    printf("\n\nImprimiendo Lista:\n");
    while (nodo_actual !=NULL)
    {
        printf(" >  %d  ", nodo_actual->valor);
        nodo_actual=nodo_actual->siguiente;
    }
    printf("\n");
}

// funcion delete para un nodo en especifico
void deleteNode(struct Nodo *cabeza, int valor) {
    struct Nodo *nodo_actual = cabeza;
    struct Nodo *nodo_anterior;
    printf("\n\nEliminar un nodo: \n");
    imprimir_lista(cabeza);

    while (nodo_actual != NULL) {

            if (nodo_actual->valor == valor) {
                    nodo_anterior->siguiente = nodo_actual->siguiente;
                    free(nodo_actual);
            } else {
                nodo_anterior = nodo_actual;
            }
    }
    printf("\n");
}

// funcion delete como pila
void deleteNodeStack(struct Nodo *cabeza) {
    struct Nodo *nodo_actual = cabeza;
    struct Nodo *nodo_anterior;

    printf("\n\nEliminar ultimo nodo: \n");
    imprimir_lista(cabeza);

    while (nodo_actual != NULL) {
            if (nodo_actual->siguiente == NULL) {
                free(nodo_actual);
                nodo_anterior->siguiente = NULL;
            } else {
                nodo_anterior = nodo_actual;
            }
    }
    printf("\n");
}

int main()
{
    struct Nodo *cabeza = NULL;
    char opt;

    do {
        system("cls");
        printf("\nIngresar valor a la lista de nodos: ");
        int n;
        fflush(stdin);
        scanf("%d", &n);
        agregar_nodo( &cabeza, n);

        printf("\n > Desea ingresar otro? (y / n) \n");
        opt = getch();

    } while (opt != 'n');

    /*
    do {
        system("cls");
        printf("\Desea eliminar un nodo: ");
        int n;
        fflush(stdin);
        scanf("%d", &n);
        agregar_nodo( &cabeza, n);

        printf("\n > Desea ingresar otro? (y / n) \n");
        opt = getch();

    } while (opt != 'n');
    */

    // agregar_nodo (&cabeza, 1);
    // agregar_nodo (&cabeza, 2);
    // agregar_nodo (&cabeza, 3);
    imprimir_lista (cabeza);

    deleteNodeStack(cabeza);
    deleteNode(cabeza, 12);
    imprimir_lista(cabeza);
    return 0;
}
