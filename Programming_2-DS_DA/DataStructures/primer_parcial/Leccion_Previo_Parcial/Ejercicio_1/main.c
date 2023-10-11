//     Est. Cristopher Vanegas     //
// Err: El ingreso de datos no es aleatorio, el usuario debe agregar el dato. //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresarDatosAleatorios();
void mostrar();

int registroVenta[10][5][3]; // empleado(fila), columna(columna), departamento(profundidad).
int p = 3, c = 5, f = 10;


int main()
{
    srand(time(NULL));
    printf("                                               Ejercicio 1!\n");
    printf(" Departamento = Profundidad\n");
    printf(" Piso = Columna\n");
    printf(" Empleado = Fila\n\n");

    ingresarDatosAleatorios();
    mostrar();
    return 0;
}

void ingresarDatosAleatorios()
{
    for (int k = 0; k < p; k++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int i = 0; i < f; i++)
            {
                registroVenta[i][j][k] = 1 + rand() % 100;
            }
        }
    }
}

void mostrar()
{
    // Imprime datos
    for (int k = 0; k < p; k++)
    {
        printf("|-------------------------------------------| DEPARTAMENTO %i |-------------------------------------------|\n", k + 1);

        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (registroVenta[i][j][k] >= 0  && registroVenta[i][j][k] < 10) printf("  %d    ", registroVenta[i][j][k]);
                if (registroVenta[i][j][k] > 9  && registroVenta[i][j][k] < 100) printf("  %d   ", registroVenta[i][j][k]);
                if (registroVenta[i][j][k] > 99) printf("  %d  ", registroVenta[i][j][k]);
            }

            printf("\n");
        }
        printf("\n\n");

        printf("|----------------------------------------------------------------------------------------------------------|\n");
        printf("\n\n");
    }
}
