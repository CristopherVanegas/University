#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int matrizCliente[5][12];
    int matrizVentas[5][12];
    int matrizMayorClienteVentas[2][10] =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}

    };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; i < 12; j++)
        {
            matrizCliente[i][j] = rand() % 10;
            matrizVentas[i][j] = 100 + rand() % 900;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; i < 12; j++)
        {
            //0 es la fila de contador - 1 fila de los precios
            //matrizCliente 0-9 por eso 10 espacios y en esos indices va guardando la informacion
            //ejem el num 9 se repite 8 veces, matrizMayorClienteVentas[0][9] se guardata el 8
            //y en el de abajo de ira sumando los precios que corresponden al 9 en la posicion 9
            matrizMayorClienteVentas[0][matrizCliente[i][j]] = matrizMayorClienteVentas[0][matrizCliente[i][j]] + 1;
            matrizMayorClienteVentas[1][matrizCliente[i][j]] = matrizMayorClienteVentas[1][matrizCliente[i][j]] + matrizCliente[i][j];
            //matrizCliente[i][j]
        }
    }
    int var = matrizMayorClienteVentas[0][0];
    int indice;
    for (int i = 0; i < 11; i++)
    {
        if (var < matrizMayorClienteVentas[0][i])
        {
            var = matrizMayorClienteVentas[0][i];
            indice = i;
        }
    }
    cout << indice;
    return 0;
}