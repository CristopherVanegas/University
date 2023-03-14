#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int facultades[5][2][3]; // Filas, Columnas, Profundidad / Facultad.
int r = 5;
int c = 2;
int p = 3;


int main()
{
    srand(time(NULL));

    // Inicializa Tablas
    for (int k = 0; k < p; k++) // Profundidad
    {
        for (int i = 0; i < r; i++) // Fila
        {
            for (int j = 0; j < c; j++) // Columna
            {
                facultades[i][j][k] = 1 + rand() % 10;

            }
        }
    }

    // Mostrar Tablas
    for (int k = 0; k < p; k++) // Profundidad
    {
        for (int i = 0; i < r; i++) // Fila
        {
            if (i == 0)
            {
                printf("|---- Tabla numero %d ----|\n\n", k + 1);
                printf("  Male | Female\n");
            }

            for (int j = 0; j < c; j++) // Columna
            {

                // Condicional para imprimir leyenda de cursos.
                if (j == (c - 1))
                {
                    if (facultades[i][j][k] > 9)
                        printf("   %d   | Curso %d", facultades[i][j][k], i + 1);
                    else if (facultades[i][j][k] < 10)
                        printf("   %d    | Curso %d", facultades[i][j][k], i + 1);
                }
                else
                {
                    if (facultades[i][j][k] > 9)
                        printf("   %d  ", facultades[i][j][k]);
                    else if (facultades[i][j][k] < 10)
                        printf("   %d   ", facultades[i][j][k]);
                }
            }
            printf("\n");
        }

        printf("\n\n\n");
    }

    return 0;
}


