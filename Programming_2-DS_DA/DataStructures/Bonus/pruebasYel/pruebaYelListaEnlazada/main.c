#include <stdio.h>
#include <stdlib.h>

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
        {
            ultimo_nodo = ultimo_nodo->siguiente;
        }
        ultimo_nodo->siguiente = nuevo_nodo;
    }
}
//crear una funcion para imprimir la lista enlazada que reciba como parametro un puntero a la cabeza de la lista
void imprimir_lista(struct Nodo *cabeza)
{
    struct Nodo *nodo_actual = cabeza;
    while (nodo_actual !=NULL)
    {
        printf("| %d | ", nodo_actual->valor);
        nodo_actual = nodo_actual->siguiente;
    }
    printf("\n");
}
void eliminar_nodo_ultimo()
{
    struct Nodo *ultimo_nodo = cabeza;
    struct Nodo *anterior = NULL;

    if(ultimo_nodo== NULL)
    {
        printf("La lista enlazada esta vacia");
    }
    else
    {
        if(ultimo_nodo->siguiente==NULL)
        {
            free(ultimo_nodo);
            ultimo_nodo=NULL;
        }
        else
        {
            while (ultimo_nodo->siguiente != NULL)
            {
                anterior = ultimo_nodo;
                ultimo_nodo = ultimo_nodo->siguiente;
            }
            anterior->siguiente = NULL;
            free(ultimo_nodo);
        }
    }
    printf("\n");
}

void eliminar_nodo_primero()
{
    struct Nodo *ultimo_nodo = cabeza;

    if(cabeza= NULL)
    {
        printf("La lista enlazada esta vacia");
    }
    else
    {
        cabeza = cabeza->siguiente;
        free(ultimo_nodo);
        printf("\n");
    }
}
void eliminar_nodo_especifico(int valor)
{
    struct Nodo *nodo_ultimo = cabeza;
    struct Nodo *anterior= NULL;
    //Buscar el nodo que contiene el valor a eliminar
    while (nodo_ultimo !=NULL && nodo_ultimo->valor != valor)
    {
        anterior= nodo_ultimo;
        nodo_ultimo= nodo_ultimo->siguiente;
    }

    //si el valor no se encontro en la lista
    if (nodo_ultimo==NULL)
    {
        printf("El elemento no se encontro en la lista!! \n");
        return;
    }

    //si el nodo a eliminar es el primer nodo de la lista
    if (anterior == NULL)
    {
        cabeza = nodo_ultimo->siguiente;
    }

    //si el nodo a eliminar es cualquier otro nodo de la lista
    else
    {
        anterior->siguiente = nodo_ultimo->siguiente;
    }
    //liberar la memoria asignada al nodo que se esta eliminando
    free(nodo_ultimo);
}



int main()
{
    struct Nodo *cabeza = NULL;
    char continuar[2];
    int opcion=0, salir=0, valor_ingresado=0;

    do
    {
        printf("\n MENU DE LA APLICACION: \n");
        printf("\t1) Insertar\n");
        printf("\t2) Mostrar\n");
        printf("\t3) Eliminar ultimo nodo\n");
        printf("\t4) Eliminar primer nodo\n");
        printf("\t5 Eliminar nodo especifico\n");
        printf("\t6) Insertar forma 2\n");
        printf("\t7) Salir\n");
        printf("Elige una opcion del menu: ");
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1: //insertar
            do
            {
                printf("Ingrese un valor para agregar a su lista enlazada: ");
                scanf(" %d", &valor_ingresado);

                agregar_nodo(&cabeza, valor_ingresado);

                printf("Desea continuar (si/no): ");
                scanf(" %s", continuar);

            }
            while (strcmp(continuar, "no")!=0);
            break;

        case 2:
            imprimir_lista(cabeza);
            break; //Mostrar lista enlazada
        case 3:

            eliminar_nodo_ultimo();

            break;// eliminar ultimo nodo

        case 4:
            eliminar_nodo_primero();

            break; //eliminar primer nodo
        case 5:
        {
            if(cabeza==NULL)
            {
                printf("La lista enlazada esta vacia");

                break;
            }
            else
            {
                printf("Ingrese el elemento que desea eliminar de su lista enlazada: ");
                scanf(" %d", &valor_ingresado);
                eliminar_nodo_especifico(valor_ingresado);

                break; // Eliminar nodo especifico
            }
        }

        }
    }
    while(opcion != 7);
}
