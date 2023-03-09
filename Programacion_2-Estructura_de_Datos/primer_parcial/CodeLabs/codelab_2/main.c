#include <stdio.h>
#include <stdlib.h>

int calificaciones[10][10] = {0};
char nombre[10][20];
float promedio[10] = {0.0};
int n, i, j, temp;

int main()
{
    printf("Cuantos alumnos desea capturar? ");
    scanf("%d", &n);


    // ingreso de datos
    for (i = 0; i < n; i++) {
        // (fflush) sirve para vaciar o limpiar el buffer del teclado.
        fflush(stdin);
        printf("Nombre del estudiante %d? ", i + 1);

        // se usa gets para cadena de caracteres, este ai guarda espacia t en blanco y lo incluye como parte de la cadena.
        gets(nombre[i]);
        for (j = 0; j < 3; j++) {
            printf("Calificacion [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &calificaciones[i][j]);
        }

        printf("\n");
    }


    // Procesamiento de Datos
    temp = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            temp = temp + calificaciones[i][j];
        }

        promedio[i] = (temp/3.0);
        temp = 0;
    }


    // Resultados
    printf("\n-----------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        printf("Nombre del estudiante %d: ", i + 1);
        puts(nombre[i]);

        for(j = 0; j < 3; j++) {
            printf("Calificacion [%d][%d] = %d\n", i + 1, j + 1, calificaciones[i][j]);
        }

        printf("\nPromedio %.2f\n", promedio[i]);
    }

    return 0;
}
