//   Codelab 7 - Primer Taller Segunda Parcial - Lista Enlazada Simple   //
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

//creo el Nodo Cabeza
struct Nodo *cabeza = NULL;

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
void deleteNode(struct Nodo *cabeza, int valor)
{
    struct Nodo *nodo_actual = cabeza;
    struct Nodo *nodo_anterior;
    printf("\n\nEliminar un nodo: \n");
    imprimir_lista(cabeza);

    while (nodo_actual != NULL)
    {

        if (nodo_actual->valor == valor)
        {
            nodo_anterior->siguiente = nodo_actual->siguiente;
            free(nodo_actual);
        }
        else
        {
            nodo_anterior = nodo_actual;
        }
    }
    printf("\n");
}

// funcion delete como pila
void deleteNodeStack(struct Nodo **cabeza)
{
    // 1. Verifico que la lista esta vacia
    if (*cabeza == NULL) printf("La lista esta vacia, no se puede eliminar ningun elemento!");

    // 2. Verifico si la lista contiene solo un nodo
    //      (*cabeza)-> utiliza la notacion de puntero o notacion indirecta
    if ((*cabeza)->siguiente == NULL)
    {
        free(*cabeza);
        *cabeza = NULL;
        printf("Se ha eliminado el unico nodo de la lista. \n");
    }

    // 3. Si la lista contiene mas de un nodo, recorrer la lista hasta llegar al penultimo nodo
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    while (actual->siguiente != NULL)
    {
        // Recorre la lista hasta llegar al penultimo nodo
        anterior = actual;
        actual = actual->siguiente;
    }

    // Establece el puntero "siguiente" del penultimo nodo como NULL
    anterior->siguiente = NULL;

    free(actual);
    printf("Se ha eliminado el ultimo nodo de la lista.\n");
}


void agregar()
{
    char opt;
    do
    {
        system("cls");
        printf("\nIngresar valor a la lista de nodos: ");
        int n;
        fflush(stdin);
        scanf("%d", &n);
        agregar_nodo( &cabeza, n);

        printf("\n > Desea ingresar otro? (y / n) \n");
        opt = getch();

    }
    while (opt != 'n');
}


void deleteOne(struct Nodo **cabeza)
{
    imprimir_lista(*cabeza);
    printf("\Seleccione el nodo a eliminar: ");
    int n;
    fflush(stdin);
    scanf("%d", &n);

    struct Nodo *actual = *cabeza;    // para guardar el actual
    struct Nodo *ant = NULL;          // para guardar el anterior

    // 1. Si el primer nodo es el que hace match con el valor a eliminar

    if (actual != NULL && actual->valor == n)
    {
        *cabeza = actual->siguiente;  // asigno a la cabecera el siguiente nodo del primero
        free(actual);                   // borro el nodo que hizo match, o sea el primero
    }


    // 2. Primero hago un bucle para descargar los que si estan y luego del bucle elimino el nodo objetivo

    while ((actual != NULL)  && (actual->valor != n))
    {
        ant = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        printf("Valor no encontrado!");
        return;
    }


    ant->siguiente = actual->siguiente;
    free(actual);
}

void continuar()
{
    printf(" > Presione cualquier tecla para continuar...");
    getch();
}

void menu ()
{
    int opt;
    do
    {
        do
        {
            system("cls");
            printf("\t\t< LISTA ENLAZADA SIMPLE >\n\n");
            printf(" [ ] Elija una opcion\n\n");
            printf("\t 1 > Agregar nodo\n");
            printf("\t 2 > Imprimir lista\n");
            printf("\t 3 > Eliminar el ultimo\n");
            printf("\t 4 > Eliminar un nodo\n");
            printf("\t 5 > Salir\n");
            printf("\n\n [ opcion ]: ");
            fflush(stdin);
            scanf("%d", &opt);
        }
        while (opt < 0 || opt > 6);

        switch (opt)
        {
        case 1:
        {
            agregar();
        }
        break;

        case 2:
        {
            imprimir_lista (cabeza);
        }
        break;

        case 3:
        {
            deleteNodeStack(&cabeza);
        }
        break;

        case 4:
        {
            deleteOne(&cabeza);
        }
        break;

        case 5:
        {
            system("cls");
            exit(1);
        }
        break;
        }

        continuar();
    }

    while (opt != 5);
}

int main()
{
    menu();
    return 0;
}
