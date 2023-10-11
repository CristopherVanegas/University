#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Nodo
{
    char desc[100];
    char codigo[4];
    int cant;
    float precio;

    struct Nodo *izq;
    struct Nodo *der;
};

void continuar() {
    printf("\n > Press any key to continue...");
    getch();
}

struct Nodo *nuevoNodo(char *desc, char *cod, int cant, float precio)
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);

    // Asignar el dato e iniciar hojas
    strcpy(nodo->desc, desc);
    strcpy(nodo->codigo, cod);
    nodo->cant = cant;
    nodo->precio = precio;

    nodo->izq = nodo->der = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, char *desc, char *cod, int cant, float precio)
{
    if (nodo == NULL) {
        nodo = nuevoNodo(desc, cod, cant, precio);
    }

    // Izquierda o Derecha?
    // Si es mayor va a la derecha
    else if (strcmp(nodo->desc, desc) > 0)
    {
        // Tienes espacio a la derecha?
        if (nodo->der == NULL)
        {
            nodo->der = nuevoNodo(desc, cod, cant, precio);
        }
        else
        {
            // Si la derecha ya esta ocupada, recursividad ;)
            insertar(nodo->der, desc, cod, cant, precio);
        }
    }
    else
    {
        // Si no, a la izquierda
        if (nodo->izq == NULL)
        {
            nodo->izq = nuevoNodo(desc, cod, cant, precio);
        }
        else
        {
            // Si la izquierda ya esta ocupada, recursividad ;)
            insertar(nodo->izq, desc, cod, cant, precio);
        }
    }
}

void anchura(struct Nodo *nodo)
{
    int altura = alturaArbol(nodo);
    int i;
    for (i = 1; i <= altura; i++)
    {
        printNivel(nodo, i);
    }
}

void printNivel(struct Nodo *nodo, int nivel)
{
    if (nodo == NULL)
    {
        return;
    }

    if (nivel == 1)
    {
        printf("\n > %s, %s, %d, %.2f ", nodo->desc, nodo->codigo, nodo->cant, nodo->precio);
    }

    else if (nivel > 1)
    {
        printNivel(nodo->izq, nivel-1);
        printNivel(nodo->der, nivel-1);
    }
}

int alturaArbol(struct Nodo *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    else
    {
        int alturaIzquierda = alturaArbol(nodo->izq);
        int alturaDerecha = alturaArbol(nodo->der);

        if (alturaIzquierda > alturaDerecha)
        {
            // printf("Nivel...%d", alturaIzquierda);
            return alturaIzquierda + 1;
        }

        else
        {
            // printf("Nivel...%d", alturaDerecha);
            return alturaDerecha + 1;
        }
    }
}

void preorden(struct Nodo *nodo)
{
    if (nodo != NULL)
    {
        printf("\n > %s, %s, %d, %.2f ", nodo->desc, nodo->codigo, nodo->cant, nodo->precio);
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

void inorden(struct Nodo *nodo)
{
    if (nodo != NULL)
    {
        inorden(nodo->izq);
        printf("\n > %s, %s, %d, %.2f ", nodo->desc, nodo->codigo, nodo->cant, nodo->precio);
        inorden(nodo->der);
    }
}

void postorden(struct Nodo *nodo)
{
    if (nodo != NULL)
    {
        postorden(nodo->izq);
        postorden(nodo->der);
        printf("\n > %s, %s, %d, %.2f ", nodo->desc, nodo->codigo, nodo->cant, nodo->precio);
    }
}

void busquedaPorDescripcion(struct Nodo *nodo, char *descripcion) {
    if (nodo != NULL)
    {
        inorden(nodo->izq);
        if (strcmp(nodo->desc, descripcion) == 0) printf("\n > %s, %s, %d, %.2f ", nodo->desc, nodo->codigo, nodo->cant, nodo->precio);
        inorden(nodo->der);
    }
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
            char *descripcion;
            char codigo[4];
            int cantidad;
            float precio;

            printf(" > Ingrese la descripcion del producto: ");
            fflush(stdin);
            gets(&descripcion);

            printf(" > Ingrese el codigo del producto: ");
            fflush(stdin);
            gets(&codigo);

            printf("%s, %s", descripcion, codigo);
            getch();

            printf(" > Ingrese el precio del producto: ");
            fflush(stdin);
            scanf("%f", &precio);

            printf(" > Ingrese la cantidad del producto: ");
            fflush(stdin);
            scanf("%d", &cantidad);

            insertar(raiz, descripcion, codigo, cantidad, precio);

        }
        break;

        case 2:
        {
            char *descripcion;

            printf(" > Ingrese la descripcion del producto: ");
            fflush(stdin);
            // gets(descripcion);
            gets(&descripcion);
            busquedaPorDescripcion(raiz, descripcion);
        }
        break;

        case 3:
        {
            printf("\n Imprimiendo en anchura\n");
            anchura(raiz);
        }
        break;

        case 4:
        {
            printf("\n Imprimiendo en preorden\n");
            preorden(raiz);
        }
        break;

        case 5:
        {
            printf("\n Imprimiendo en inorden\n");
            inorden(raiz);
        }
        break;

        case 6:
        {
            printf("\n Imprimiendo en postorden\n");
            postorden(raiz);
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


int main(int argc, char *argv[])
{
    menu();
    return 0;
}
