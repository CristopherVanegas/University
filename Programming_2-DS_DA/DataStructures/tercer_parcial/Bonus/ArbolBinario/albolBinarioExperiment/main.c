//   Est. Cristopher Vanegas   //
//   Arbol Binario - Lec/Esc   //
//   [] Binary Files           //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Nodo
{
    int num;
    struct Nodo *der;
    struct Nodo *izq;
};

struct Nodo *raiz, *nuevoNodo1, *nuevoNodo2;

void continuar()
{
    printf("\nPresione una tecla para continuar...");
    getch();
}

void arbolSencillo()
{
    system("cls");
    printf("Arbol Binario Sencillo!\n");

    /*   Creo el Nodo Raiz   */
    printf("\nRaiz:");
    raiz = (struct Nodo *) malloc(sizeof(struct Nodo));
    raiz->der=NULL;
    raiz->izq=NULL;
    raiz->num=2;
    printf(" %d\n\n", raiz->num);


    /*   Creo el Nodo Izq   */
    printf("\nIzq:");
    nuevoNodo1 = (struct Nodo *) malloc(sizeof(struct Nodo));
    nuevoNodo1->der=NULL;
    nuevoNodo1->izq=NULL;
    nuevoNodo1->num=-1;
    /*   Lo asigno en Raiz->Izq   */
    raiz->izq = nuevoNodo1;
    /*   Imprimo el valor de raiz->izq->num   */
    printf(" %d\n\n", raiz->izq->num);
    /*   Libero memoria   */
    // free(nuevoNodo1);


    /*   Creo el Nodo Der   */
    printf("\nDer:");
    nuevoNodo2 = (struct Nodo *) malloc(sizeof(struct Nodo));
    nuevoNodo2->der=NULL;
    nuevoNodo2->izq=NULL;
    nuevoNodo2->num=5;
    /*   Lo asigno a Raiz->Der   */
    raiz->der = nuevoNodo2;
    /*   Imprimo el valor de raiz->der->num   */
    printf(" %d\n\n", raiz->der->num);
    /*   Libero memoria   */
    // free(nuevoNodo2);


    printf("\nImprimiendo valores luego de haber liberado memoria!\n");
    printf("Raiz: %d\n", raiz->num);
    printf("Izq: %d\n", raiz->izq->num);
    printf("Der: %d\n\n", raiz->der->num);
    continuar();

}

void escribirTresNodos()
{
    system("cls");
    printf("\nEscribiendo data\n");

    FILE *f = fopen("data.dat", "wb");
    if (f == NULL)
    {
        printf("\nArchivo no encontrado...");
        continuar();

    }
    else
    {
        fwrite(raiz, sizeof(struct Nodo), 1, f);
        fwrite(nuevoNodo1, sizeof(struct Nodo), 1, f);
        fwrite(nuevoNodo2, sizeof(struct Nodo), 1, f);
        printf("\nArchivo escrito con exito!..");
        continuar();
    }

    fclose(f);
}

void leerData()
{
    system("cls");
    printf("\nLeyendo data\n");

    FILE *f = fopen("data.dat", "rb");
    if (f == NULL)
    {
        printf("Archivo no encontrado...");
        continuar();

    }
    else
    {

        /*---------[] Leo archivos Binarios con estructuras punteros------------*/

        int count = 1;
        int filesRead = 0;

        struct Nodo *nodo = (struct Nodo *) malloc(sizeof(struct Nodo));
        filesRead = filesRead + fread(nodo, sizeof(struct Nodo), 1, f);

        while (!feof(f))
        {
            printf(" > Nodo %d: %d \n\n", count++, nodo->num);
            free(nodo);

            struct Nodo *nodo = (struct Nodo *) malloc(sizeof(struct Nodo));
            filesRead = filesRead + fread(nodo, sizeof(struct Nodo), 1, f);
        }

        /*----------------------------------------------------------------------*/

        printf("\nArchivos leidos %d \n", filesRead);
    }

    fclose(f);
}


int main()
{
    arbolSencillo();
    escribirTresNodos();
    leerData();


    return 0;
}
