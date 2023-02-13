// Ejercicio 4: Cargar un vector de 10 elementos y verificar posteriormente si el mismo está ordenado de menor a mayor.
// Source: https://www.tutorialesprogramacionya.com/cmasmasya/detalleconcepto.php?punto=15&codigo=142&inicio=0

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

string estaOrdenado(int arr[]);

int main()
{
    int arr[10];
    srand(time(NULL));

    for (int i = 0; i <= 9; i++) {
        arr[i] = 1 + rand() % 10;
        cout << i << ": " << arr[i] << endl;
    }


    cout << "Esta ordenado?: " << estaOrdenado(arr);

    return 0;
}
// 120 x 30
string estaOrdenado(int arr[]) {
    for (int i = 0; i < 10; i++) {
        if (arr[0] > arr[i]) {
            return "false";
        } else {
            continue;
        }
    }

    return "true";
}
