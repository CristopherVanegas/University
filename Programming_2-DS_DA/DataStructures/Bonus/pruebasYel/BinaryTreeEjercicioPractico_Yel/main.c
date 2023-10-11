//TALLER DE ARBOLES_TIENDA DE SOUVENIR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de un nodo de la lista

typedef struct NodoTienda
{
    char cod_producto[4];
    char desc_producto[50];
    int cantidad;
    float precio;
    struct NodoTienda *der;
    struct NodoTienda *iz;
};

struct NodoTienda *cabeza = NULL;

struct NodoTienda *nuevoNodo(char cod_producto[4], char desc_producto[50], int cantidad, float precio)
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct NodoTienda);
    struct NodoTienda *nodo = (struct NodoTienda *) malloc(tamanioNodo);

    // Asignar el dato e iniciar hojas
    strcpy(nodo->cod_producto, cod_producto);
    strcpy(nodo->desc_producto, desc_producto);
    nodo->cantidad = cantidad;
    nodo->precio = precio;
    nodo->iz = NULL;
    nodo->der = NULL;
    return nodo;
}


void insertar(struct NodoTienda *nodo, char cod_producto[4], char desc_producto[50], int cantidad, float precio)
{
    if (cabeza == NULL)
    {
        return nuevoNodo(cod_producto,desc_producto, cantidad, precio);
        // Izquierda o Derecha?
        // Si es mayor va a la derecha
        if (strcmp(desc_producto, nodo->desc_producto)> 0 )
        {
            // Tienes espacio a la derecha?
            if (nodo->der == NULL)
            {
                nodo->der = nuevoNodo(cod_producto,desc_producto, cantidad, precio);
            }
            else
            {
                // Si la derecha ya esta ocupada, recursividad ;)
                insertar(nodo->der, cod_producto,desc_producto, cantidad, precio);
            }
        }
        else
        {
            // Si no, a la izquierda
            if (nodo->iz == NULL)
            {
                nodo->iz = nuevoNodo(cod_producto,desc_producto, cantidad, precio);
            }
            else
            {
                // Si la izquierda ya esta ocupada, recursividad ;)
                insertar(nodo->iz, cod_producto,desc_producto, cantidad, precio);
            }
        }
    }
}

void anchura( struct NodoTienda *nodo)
{
    int altura = alturaArbol(nodo);
    int i;
    for (i = 1; i <= altura; i++)
    {
        printNivel(nodo, i);
    }
}

void printNivel(struct NodoTienda *nodo, int nivel)
{
    if (nodo == NULL)
    {
        return;
    }

    if (nivel == 1)
    {
        printf(" > %s  > %s  > %i  > %2.f  <", nodo->cod_producto,nodo->desc_producto, nodo->cantidad, nodo->precio);
    }
    else if (nivel > 1)
    {
        printNivel(nodo->iz, nivel-1);
        printNivel(nodo->der, nivel-1);
    }
}

int alturaArbol(struct NodoTienda *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    else
    {
        int alturaIzquierda = alturaArbol(nodo->iz);
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

void preorden(struct NodoTienda *nodo, char cod_producto[4], char desc_producto[50], int cantidad, float precio)
{
    if (nodo != NULL)
    {
        printf(" > %s  > %s  > %i  > %2.f  <", nodo->cod_producto,desc_producto, cantidad, precio);
        preorden(nodo->iz,cod_producto, desc_producto, cantidad, precio);
        preorden(nodo->der,cod_producto, desc_producto, cantidad, precio);
    }
}

void inorden(struct NodoTienda *nodo, char cod_producto[4], char desc_producto[50], int cantidad, float precio)
{
    if (nodo != NULL)
    {
        inorden(nodo->iz,cod_producto, desc_producto, cantidad, precio);
        printf("> %s  > %s  > %i  > %2.f  <", nodo->cod_producto,desc_producto, cantidad, precio);
        inorden(nodo->der,cod_producto, desc_producto, cantidad, precio);
    }
}

void postorden(struct NodoTienda *nodo, char cod_producto[4], char desc_producto[50], int cantidad, float precio)
{
    if (nodo != NULL)
    {
        postorden(nodo->iz,cod_producto, desc_producto, cantidad, precio);
        postorden(nodo->der,cod_producto, desc_producto, cantidad, precio);
        printf(" > %s > %s > %i > %2.f <", nodo->cod_producto, desc_producto, cantidad, precio);
    }
}

void imprimir_lista(struct NodoTienda *cabeza)
{
    struct NodoTienda *nodo = cabeza;
    if (nodo == NULL)
    {
        printf("La lista enlazada esta vacia");
    }
    else
    {

        printf("Listado de souvenirs: ");
        while (nodo != NULL)
        {
            printf("\n %s ", nodo->cod_producto);
            printf("\n %s ", nodo->desc_producto);
            printf("\n %d ", nodo->cantidad);
            printf("\n %2.f ", nodo->precio);
            nodo = nodo->iz;
            nodo = nodo->der;
        }
    }
    printf("\n");
}

int main()
{
    int opcion=0, salir=0, valor_ingresado=0, cantidad=0, posicion_prod=0;
    char continuar[2],desc_producto[50],cod_producto[4];
    float precio;

    do
    {
        system("cls");
        printf("\n MENU TIENDA DE SOUVENIRS ECOTEC: \n");
        printf("\t1) Compra a proveedores(Ingreso al inventario)\n");
        printf("\t2) Busqueda de productos por descripcion\n");
        printf("\t3) Consulta de todos los productos en anchura\n");
        printf("\t4) Consulta de todos los productos en preorden\n");
        printf("\t5) Consulta de todos los productos en inorden\n");
        printf("\t6) Consulta de todos los productos en postorden\n");
        printf("\t7) Salir\n");
        printf(" Elige una opcion del menu: ");
        scanf(" %d",&opcion);
        switch(opcion)
        {
        case 1: //insertar

            do
            {
                printf("Ingrese el codigo del producto: ");
                scanf(" %s",&cod_producto);
                printf("Ingrese la descripcion del producto: ");
                scanf(" %s",&desc_producto);
                printf("Ingrese la cantidad del producto: ");
                scanf(" %i",&cantidad);
                printf("Ingrese el precio del producto: ");
                scanf(" %f",&precio);


                if (cabeza == NULL)
                {
                    cabeza =  nuevoNodo(cod_producto,desc_producto, cantidad, precio);
                }
                insertar(cabeza, cod_producto,desc_producto,cantidad,precio);
                printf("Desea continuar (si/no): ");
                scanf(" %s", continuar);
            }
            while (strcmp(continuar, "no")!=0);
            break;
        case 2:
        {
            imprimir_lista(cabeza);
            break;
        }

        case 3:
        {
            printf("\n Imprimiendo en anchura\n");
            anchura(cabeza);
            break; //mostrar lista enlazada
        }

        case 4:
        {
            printf("\n Imprimiendo en preorden\n");
            preorden(cabeza,cod_producto,desc_producto,cantidad,precio);
            break;
        } //eliminar ultimo nodo}
        case 5:
            printf("\n Imprimiendo en inorden\n");
            inorden(cabeza,cod_producto,desc_producto,cantidad,precio);
            break;
        case 6:
        {
            printf("\n Imprimiendo en postorden\n");
            postorden(cabeza,cod_producto,desc_producto,cantidad,precio);
        }
        case 7:
            salir = 1;
            break;
        default:
            printf("\nOpcion incorrecta\n");

        }
    }
    while (salir != 1);

    printf("\nPrograma terminado\n");
    return 0;
}
