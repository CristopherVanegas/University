#include <stdio.h>
#include <stdlib.h>

int writeFile(FILE *archivo);
int showFile(FILE *archivo);

int main()
{
    printf("| -------------------------------- FILE MANIPULATION! -------------------------------- |\n");
    FILE *archivo;  // File variable;

    writeFile(archivo);
    showFile(archivo);

    return 0;
}

int writeFile(FILE *archivo)
{
    archivo = fopen("archivo_1.txt", "w");

    if (archivo == NULL)
        printf("    >>> Error al leer el archivo!");
    else
    {
        printf("    >>> El archivo no existia, por lo tanto, archivo creado con exito!\n");
        fprintf(archivo, "Esta es una cadena de caracteres.\n");
    }

    fclose(archivo);
    printf("\n");
    return 0;
}

int showFile(FILE *archivo)
{
    archivo = fopen("archivo_1.txt", "r");
    char linea[100];
    fgets(linea, 100, archivo);

    if (archivo == NULL)
        printf("    >>> El archivo ha sido creado con exito!\n");
    else
    {
        printf("    >>> Leyendo con exito!\n");
        printf("     >> Leyendo la primera linea: %s\n", linea);
    }

    fclose(archivo);
    printf("\n");
    return 0;
}


