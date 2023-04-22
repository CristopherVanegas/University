#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcularLongitudDeFilaYColumna() {
    int matriz[3][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int longitud_fila = sizeof(matriz) / sizeof(matriz[0]);
    int longitud_columna = sizeof(matriz) / (longitud_fila * sizeof(matriz[0][0]));

    printf("La longitud de una fila es %d\n", longitud_fila);
    printf("La longitud de una columna es %d\n", longitud_columna);

}

void matrixComoParametro(char *matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = rand() % 11;
            printf(" > %d \n", matrix[i][j]);
        }
    }
}

int main()
{
    srand(time(NULL));
    char matrix[3][4];
    matrixComoParametro(&matrix[0][0]);


    return 0;
}
