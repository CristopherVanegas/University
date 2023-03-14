#include <stdio.h>
#include <stdlib.h>

int writeFile();

int main()
{
    printf("File manipulation!\n");
    switch(writeFile())
    {
    case 0:
    {
        printf("El archivo ha sido creado con exito!");
    }
    break;

    case 1:
    {
        printf("Error al ejecutar la creacion del archivo!");
    }
    break;

    }
    printf("");

    return 0;
}

int writeFile()
{
    FILE *archivo;
    archivo = fopen("archivo_1.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Esta es una cadena de caracteres.\n");
    fclose(archivo);
    return 0;
}


