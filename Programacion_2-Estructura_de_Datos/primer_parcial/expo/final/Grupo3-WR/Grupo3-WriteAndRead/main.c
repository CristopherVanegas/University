#include <stdio.h>
#include <stdlib.h>

void escribir_archivo() {
    FILE *archivo;
    char texto[100];

    // Abre el archivo en modo escritura
    archivo = fopen("archivo.txt", "w");


    // Pide al usuario que ingrese texto y lo escribe en el archivo
    printf("Ingrese texto para escribir en el archivo:\n\n");
    fgets(texto, 100, stdin);
    fprintf(archivo, "\n%s", texto);

    // Cierra el archivo
    fclose(archivo);

    printf("\n<Texto escrito en el archivo correctamente>\n\n");
}

void leer_archivo() {
    FILE *archivo;
    char caracter;

    // Abre el archivo en modo lectura
    archivo = fopen("archivo.txt", "r");

    // Si el archivo no se pudo abrir, muestra un mensaje de error y termina la función
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n\n");
        return;
    }

    // Lee y muestra cada caracter del archivo
    printf("<Texto contenido en el archivo>\n");
    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    // Cierra el archivo
    fclose(archivo);
}

int main() {
    // Llama a la función para escribir en el archivo
    escribir_archivo();

    // Llama a la función para leer el archivo
    leer_archivo();

    return 0;
}
