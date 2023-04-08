//  Est. Cristopher Vanegas  //
//  Taller 2 - Seg. Parcial  //
//  Listas con Enlace Doble  //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct Nodo
{
    int valor;
    struct Nodo *sig;
    struct Nodo *ant;
};

struct Nodo *inicio = NULL;
struct Nodo *fin = NULL;

void continuar()
{
    printf("\n\n [] Presione cualquier tecla para continuar!\n\n");
    getch();
}

struct Nodo * crearNodo()
{
    // reservo memoria para el nuevo nodo!
    struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    // inicializo el nuevo nodo!
    /* nuevoNodo->valor = 1 + rand() % 25; */

    system("cls");
    printf(" [] CREANDO NODO!\n");
    printf("\t[] Ingrese un valor entero para el nodo!\n");
    printf("\t[valor] :");
    fflush(stdin);
    scanf("%d", &nuevoNodo->valor);

    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    printf("\n\n [] Nodo creado con exito!\n");

    return nuevoNodo;
}

void crearNodo_pila()
{
    system("cls");
    printf("Generando un nuevo nodo con valor numerico aleatorio entre 1 y 25...\n");

    struct Nodo *nuevoNodo = crearNodo();

    // si no hay nodos agrega uno!
    if (inicio == NULL)
    {
        nuevoNodo->ant = NULL;
        nuevoNodo->sig = NULL;

        inicio = nuevoNodo;
        fin = nuevoNodo;
    }

    // si hay un nodo luego del inicio entonces recorre hasta el ultimo nodo y lo agrega luego de este!
    else if (inicio != NULL)
    {
        struct Nodo *actual = inicio;

        // mientras no halla un null entonces lo recorre!
        while (actual->sig != NULL)
        {
            actual = actual->sig;
        }

        // cambio el null de actual->sig por la direccion del nuevo nodo a la pila!
        actual->sig = nuevoNodo;

        // cambio ->sig y ->ant del nuevo nodo!
        nuevoNodo->sig = NULL;
        nuevoNodo->ant = actual;

        // actualizo el nuevo nodo "fin" por nuevo nodo!
        fin = nuevoNodo;
    }
}

int askForPos()
{
    int pos;
    do
    {
        system("cls");
        printf(" INGRESE UNA POSICION ESPECIFICA\n");
        printf("\n\t[] Ingrese la posicion donde desea efectuar una operacion!\n");
        printf("\t[] Recuerde que todos los nodos a partir de eso se desplazaran una posicion!\n");
        printf("\t[] Tenga en cuenta que las posiciones comienzan desde 0!\n");
        printf("\t[posicion] : ");
        fflush(stdin);
        scanf("%d", &pos);
    }
    while (pos < 0);

    return pos;
}

void crearNodo_pos_especifica(int pos)
{
    struct Nodo *nuevoNodo = crearNodo();
    continuar();
    struct Nodo *actual = inicio;
    struct Nodo *anterior = NULL;
    int count;

    system("cls");
    printf(" CREANDO NODO EN POSICION ESPECIFICA\n");
    // me aseguro que hallan nodos, caso contrario aviso y creo uno nuevo!
    if (inicio == NULL)
    {
        printf(" [] La lista esta vacia, se procede a crear un nuevo nodo!\n");
        inicio = nuevoNodo;
        fin = nuevoNodo;
        return;
    }

    /*  Test  */
    // printf("Posicion deseada: %d", pos);
    // continuar();

    // resta -1 al contador, porque nuestros nodos se posicionan desde 0!
    // pos = pos - 1;
    count = 0;

    // 1. Si la posicion deseada es 0 entonces muevo la cabeza + 1 a la derecha!
    if (pos == 0)
    {
        nuevoNodo->sig = inicio;
        inicio->ant = nuevoNodo;
        nuevoNodo->ant = NULL;

        inicio = nuevoNodo;
        return;
    }

    // 2. Si no itero la lista / cola hasta posicionarme donde deseo agregar el nodo!
    else
    {
        while (actual != NULL)
        {
            if (pos == count)
            {
                // realizo las dos conexiones izquierdas del nuevo nodo!
                nuevoNodo->ant = anterior;
                anterior->sig = nuevoNodo;

                // realizo las dos conexiones derechas del nuevo nodo!
                nuevoNodo->sig = actual;
                actual->ant = nuevoNodo;

                printf(" [] Nodo posicionado con exito!\n");
                return;
            }

            anterior = actual;
            actual = actual->sig;
            count++;
        }

    }

    printf("\n\t[]Posicion fuera de los limites de la pila / cola!\n");
    free(nuevoNodo);
}

void eliminarPosEspecifica(int pos)
{
    int count;

    system("cls");
    printf(" [] ELIMINANDO NODO EN POSICION ESPECIFICA\n");
    // me aseguro que hallan nodos, caso contrario aviso y creo uno nuevo!
    if (inicio == NULL)
    {
        printf(" [] La lista esta vacia! Deseas crear un nuevo nodo? (any / n): ");
        if (getch() == 'n')
        {
            struct Nodo *nuevoNodo = crearNodo();
            inicio = nuevoNodo;
            fin = nuevoNodo;
            printf("\n [] Listo! Nuevo nodo creado!\n");
            continuar();
        }
        return;
    }

    /*  Test  */
    // printf("Posicion deseada: %d", pos);
    // continuar();

    count = 0;

    // 1. Si la posicion deseada es 0 entonces igualo la cabeza al siguiente nodo y elimino el primero!
    if (pos == 0)
    {
        struct Nodo *temp = inicio;
        inicio = inicio->sig;
        inicio->ant = NULL;
        free(temp);
        return;
    }

    // 2. Si no itero la lista / cola hasta posicionarme donde deseo eliminar el nodo!
    else
    {
        struct Nodo *actual = inicio;
        struct Nodo *anterior = NULL;

        while (actual != NULL)
        {
            if (pos == count)
            {
                // realizo las dos conexiones entre anterior y siguiente del actual!
                anterior->sig = actual->sig;
                actual->sig->ant = anterior;
                free(actual);

                printf(" [] Nodo eliminado con exito!\n");
                printf(" [] A continuacion se muestran los nodos!");
                continuar();
                mostrar_lista();
                return;
            }

            anterior = actual;
            actual = actual->sig;
            count++;
        }

    }

    printf("\n[]Posicion fuera de los limites de la pila / cola!\n");
}

void mostrar_lista()
{
    struct Nodo *actual = inicio;

    system("cls");
    printf(" [] Imprimiendo lista!\n");

    // Verifico si la lista esta vacia por medio de la existencia del nodo inicio!
    if (inicio == NULL)
    {
        printf("\n\n [] La lista esta vacia!\n\n");
    }

    // recorro y muestro
    else
    {
        while (actual != NULL)
        {
            printf(" >  %d ", actual->valor);
            actual = actual->sig;
        }
    }

    printf("\n\n");
    printf("\t[] Primer elemento es %d", inicio->valor);
    printf("\t[] Ultimo elemento es %d", fin->valor);
    printf("\n");
}

void eliminarComoPila()
{
    system("cls");
    printf(" [] Eliminando ultimo valor de la pila!\n");
    mostrar_lista();
    continuar();

    printf(" [] Ultimo valor en la pila es: %d", fin->valor);
    continuar();
    printf(" [] Eliminando...");

    struct Nodo *temp = fin;
    fin = fin->ant;
    fin->sig = NULL;
    free(temp);

    mostrar_lista();
    printf("\n\n [] Nodo eliminado con exito!\n");
    continuar();
}

void eliminarComoCola()
{
    system("cls");
    printf(" [] Eliminando primer valor de la cola!\n");
    mostrar_lista();
    continuar();

    printf(" [] Ultimo valor en la cola es: %d", inicio->valor);
    continuar();
    printf(" [] Eliminando...\n");

    if (inicio->sig == NULL)
    {
        printf("\n [] Solo queda un nodo!\n");

        struct Nodo *temp = inicio;
        free(temp);
        inicio = NULL;
        fin = NULL;
        printf("\n\n [] Nodo eliminado!\n");
    }

    else
    {
        struct Nodo *temp = inicio;

        inicio = inicio->sig;
        free(temp);

        mostrar_lista();
        printf("\n\n [] Nodo eliminado con exito!\n");
    }
    continuar();
}


void menu()
{
    printf("LISTA DOBLEMENTE ENLAZADA!\n");

    for (;;)
    {
        int o;

        do
        {
            system("cls");
            printf("[*] Elige una opcion para comenzar!\n\n");
            printf(" 1 > Crear un nodo a la pila/cola!\n");
            printf(" 2 > Crear un nodo en una posicion especifica!\n");
            printf(" 3 > Mostrar la lista doblemente enlazada!\n");
            printf(" 4 > Borrar un nodo a la pila!\n");
            printf(" 5 > Borrar un nodo a la cola!\n");
            printf(" 6 > Borrar un nodo en una posicion especifica!\n");
            printf(" 7 > Salir!\n");
            printf("\n\n[ ] opcion: ");
            fflush(stdin);
            scanf("%d", &o);

        }
        while (o < 1 && o > 6);

        switch(o)
        {
        case 1:
        {
            crearNodo_pila();
        }
        break;

        case 2:
        {
            crearNodo_pos_especifica(askForPos());
        }
        break;

        case 3:
        {
            mostrar_lista();
        }
        break;

        case 4:
        {
            eliminarComoPila();
        }
        break;

        case 5:
        {
            eliminarComoCola();
        }
        break;

        case 6:
        {
            eliminarPosEspecifica(askForPos());
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

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
