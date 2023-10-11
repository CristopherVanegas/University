// Est. Cristopher Vanegas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cantones = 1;
int parroquias = 1;
int ciudadelas = 2;
int manzanas = 5;
int villas = 10;

int matrix[10][5][2][1][1]; // Villas, Manzanas, Ciudadela, Parroquia, Canton

int main()
{
    srand(time(NULL));

    // Insercion de datos aleatoria
    for (int canton = 0; canton < cantones; canton++)   // Cantones
    {
        for (int p = 0; p < parroquias; p++)                // Parroquias
        {
            for (int ciudadela = 0; ciudadela < ciudadelas; ciudadela++)    // Ciudadelas
            {
                for (int m = 0; m < manzanas; m++)          // Manzanas
                {
                    for (int v = 0; v < villas; v++)        // Villas
                    {
                        matrix[v][m][ciudadela][p][canton] = 150 + rand() % (250 - 150);
                    }
                }
            }
        }
    }


    // Imprime datos
    for (int canton = 0; canton < cantones; canton++)   // cantones
    {
        if (canton == 0)
            printf("|-------------------------------------------| CANTON GUAYAQUIL |-------------------------------------------|\n");

        for (int p = 0; p < parroquias; p++)
        {
            if (p == 0)
                printf("                                            | PARROQUIA TARQUI | \n\n");

            for (int ciudadela = 0; ciudadela < ciudadelas; ciudadela++)
            {
                if (ciudadela == 0)
                    printf("                                            [   Mucho Lote 1   ] \n\n");
                else if (ciudadela == 1)
                    printf("                                            [   Mucho Lote 2   ] \n\n");

                for (int m = 0; m < manzanas; m++)  // manzana / fila
                {
                    // Condicional para imprimir la letenda de las villas
                    if (m == 0)
                    {
                        for (int villa_leyenda = 0; villa_leyenda < villas; villa_leyenda++) {
                            printf("  Villa %d ", villa_leyenda + 1);
                        }
                        printf("\n");
                    }
                    for (int v = 0; v < villas; v++)    // villa / columna
                    {
                        // Condicional para imprimir la leyenda de las manzanas
                        if (v == villas - 1)
                            printf("  %dkW   | Mz %d", matrix[v][m][ciudadela][p][canton], m + 1);
                        else
                            printf("  %dkW   ", matrix[v][m][ciudadela][p][canton]);
                    }
                    printf("\n");
                }

                printf("\n\n\n");
            }
        }
        printf("|----------------------------------------------------------------------------------------------------------|\n");

    }


    return 0;
}
