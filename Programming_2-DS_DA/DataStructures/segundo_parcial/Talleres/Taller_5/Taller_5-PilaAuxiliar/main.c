//   Est. Cristopher Vanegas   //
/*
    * CREAR UNA PILA Y BUSCAR UN ELEMENTO A ELIMINAR.
    * PARA ESTO SE NECESITA CREAR UNA PILA AUXILIAR PARA PASAR
      TODOS LOS ELEMENTOS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pila[5];
int  aux[5];
int d = 5;


void mostrarPila(int arr[]);
void llenarPila(int arr[]);


int main()
{
    do
    {
        system("cls");
        printf("\t\t\t\t\t | PILA AUXILIAR |\n");

        // Obtengo que elemento de la pila desea eliminar.
        llenarPila(pila);
        printf("\n > Que elemento de la pila desea eliminar?\n");
        mostrarPila(pila);
        printf(" > ");
        fflush(stdin);
        int opt;
        scanf("%d", &opt);


        // Paso a la pila auxiliar los datos arriba del dato a eliminar.
        /* opt-- es porque cuando se muestran los indices se cuenta desde 1 y no desde 0 */

        int qAux = 0;  // Cantidad de elementos de la pila Auxiliar.
        for (int i = d-1; i > opt-1; i--)
        {
            aux[qAux] = pila[i];
            pila[i] = 0;
            qAux++;
        }

        mostrarPila(aux);

        int iPila = opt-1;  // Indice para la pila original, se le resta 2 para reescribir el valor que se desea eliminar.
        for (int i = 0; i < qAux-1; i++)
        {
            pila[iPila] = aux[i];
            iPila++;
        }

        printf("\n\n");
        mostrarPila(pila);

        printf("\n\n > Print any key to continue or 'n' to exit!");
    }
    while (getch() != 'n');

    return 0;
}


void mostrarPila(int arr[])
{
    for (int i = 0; i < d; i++)
    {
        printf("%d: %d\n", i + 1, arr[i]);
        Sleep(50);
    }
    printf("\n");
}


void llenarPila(int arr[])
{
    for (int i = 0; i < d; i++)
    {
        arr[i] = 1 + rand() % 100;
    }
}
