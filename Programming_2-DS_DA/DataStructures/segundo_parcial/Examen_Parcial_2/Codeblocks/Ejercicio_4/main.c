//  Est. Cristopher Vanegas  //
//      Segundo Parcial      //
//  Programa hecho en lista  //
//      enlazada simple      //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct NodoTienda
{
    char cod_producto[4];
    char desc_producto[50];
    int cantidad;
    float precio;

    struct NodoTienda *sig;
};

struct NodoTienda *inicio = NULL;

void continuar()
{
    printf("\n\n [] Presione cualquier tecla para continuar... ");
    getch();
}

struct NodoTienda *crearNodo()
{
    // reservo memoria para el nodo.
    struct NodoTienda *nuevoNodo = malloc(sizeof(struct NodoTienda));
    // inicializo las propiedades del nodo.
    printf("    > Ingrese cod de producto (max 4 digts): ");
    fflush(stdin);
    fgets(nuevoNodo->cod_producto, 4, stdin);
    // gets(nuevoNodo->cod_producto);
    printf("    > Ingrese descripcion del producto (max 50 digts): ");
    fflush(stdin);
    fgets(nuevoNodo->desc_producto, 50, stdin);
    // gets(nuevoNodo->desc_producto);
    printf("    > Ingrese cantidad del producto: ");
    fflush(stdin);
    scanf("%d", &nuevoNodo->cantidad);
    printf("    > Ingrese precio del producto: ");
    fflush(stdin);
    scanf("%f", &nuevoNodo->precio);

    return nuevoNodo;
};

void agregoACola(struct NodoTienda **cabeza)
{
    do
    {
        system("cls");
        printf(" [] Compra de producto al proveedor\n");

        struct NodoTienda *nuevoNodo = crearNodo();

        if (*cabeza == NULL)
        {
            *cabeza = nuevoNodo;
        }
        else
        {
            struct NodoTienda *actual = *cabeza;
            while (actual->sig != NULL)
            {
                actual = actual->sig;
            }

            actual->sig = nuevoNodo;
        }

        system("cls");
        printf(" [] Desea agregar otro nodo? (any / n): ");
    }
    while (getche() != 'n');
}



void mostrarCola(struct NodoTienda **inicio) {
    struct NodoTienda *actual = *inicio;

    system("cls");
    printf(" [] Inventario\n");

    // Verifico si la lista esta vacia por medio de la existencia del nodo inicio!
    if (*actual == NULL)
    {
        printf("\n\n [] El inventario esta vacio!\n\n");
        return;
    }

    // recorro y muestro
    while (actual->sig != NULL)
    {
        printf("  >>  Codigo del producto: %s\n", actual->cod_producto);
        printf("  >>  Descripcion del producto: %s\n", actual->desc_producto);
        printf("  >>  Cantidad del producto: %d\n", actual->cantidad);
        printf("  >>  Precio del producto: %.2f \n\n\n", actual->precio);
        actual = actual->sig;
    }
}

void eliminoPorCod(struct Nodo **cabeza)
{
    struct NodoTienda *nodo_actual = *cabeza;
    struct NodoTienda *nodo_anterior;
    char cod[4];

    printf("\n\n [] Venta a Clientes\n\n");
    printf("\n\n [] Ingrese el codigo del producto (max 4 dgts): \n\n");
    gets(cod);

    while (nodo_actual != NULL)
    {
        if (strcmp(nodo_actual->cod_producto, cod))
        {
            nodo_anterior->sig = nodo_actual->sig;
            free(nodo_actual);
        }
        else
        {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->sig;
        }
    }
    printf("\n");
}


void menu()
{
    for (;;)
    {
        int o;

        do
        {
            system("cls");
            printf("MENU TIENDA DE SOUVENIRS ECOTEC:\n");
            printf("\t1) Compra a proveedores (Ingreso al inventario)\n");
            printf("\t2) Venta a clientes (Salida de Inventario)\n");
            printf("\t3) Consula de productos\n");
            printf("\t4) Salir\n");
            printf("Elige una opcion del menu: ");
            fflush(stdin);
            scanf("%d", &o);

        }
        while (o < 1 && o > 4);

        switch(o)
        {
        case 1:
        {
            agregoACola(&inicio);
        }
        break;

        case 2:
        {
            eliminoPorCod(&inicio);
        }
        break;

        case 3:
        {
            mostrarCola(&inicio);
        }
        break;

        case 4:
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
    menu();

    return 0;
}
