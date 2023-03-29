#include <stdio.h>
#include <stdlib.h>

int crear_fichero();
int leer_fichero();

struct Producto
{
    char codigo_inventario[10];
    char descripcion[50];
    float precio;
};

struct Producto listaProducts[10];
FILE *arch;

int main()
{
    int rtn;
    rtn = crear_fichero();
    rtn = leer_fichero();
    return 0;
}

int crear_fichero ()
{
    FILE *arch;
    int i, er_dev = 0;

    if ((arch = fopen("arch.dat", "ab")) == NULL)
    {
        printf ("Error en apertura del fichero para escritura\n");
        er_dev = 1;
    }
    else
    {
        printf("Ingrese el codigo del producto: ");
        gets(listaProducts[0].codigo_inventario);
        fwrite(&listaProducts, sizeof(listaProducts), 1, arch);


        fclose (arch);
    }
    return er_dev;
}


int leer_fichero ()
{
    FILE *arch;
    int er_dev = 0;
    if ((arch = fopen("arch.dat", "rb")) == NULL)
    {
        printf ("Error en apertura del fichero para lectura \n");
        er_dev = 1;
    }
    else
    {
        fread (&listaProducts, sizeof(listaProducts), 1, arch);
        while (! feof(arch))
        {
            printf ("%s: %s: %i\n", listaProducts[0].codigo_inventario, listaProducts[0].descripcion, listaProducts[0].precio);
            fread (&listaProducts[0], sizeof(listaProducts), 1, arch);
        }
        fclose (arch);
    }
    return er_dev;
}


