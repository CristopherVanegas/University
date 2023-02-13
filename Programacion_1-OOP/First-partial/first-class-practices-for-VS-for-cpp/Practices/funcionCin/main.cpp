// Objetivo: Definir bien los tipos de datos para evitar errores de dato.

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void promedioDosNums();
void cicloInfinito();
void deseaContinuar();
void promedio();
void getcheYchetch();

int main()
{
    // promedioDosNums();
    // cicloInfinito();
    // deseaContinuar();
    // promedio();
    getcheYchetch();

    return 0;
}

void getcheYchetch() {
    /*
        La funcion getch() no muestra lo que se ingreso.
        La funcion getche() muestra lo que se ingreso.
    */
    char numero;
    do {
        numero = getch();
        cout << "Tecla presionada: " << numero << endl;
        if (kbhit()) {
            if (numero == 'q') {
                cout << "Presionaste q";
            }
        }

    } while (numero!='n');
}

void promedioDosNums() {
    float a, b;
    float prom;

    cin >> a;
    cin >> b;

    prom = (a + b)/2;
    cout << prom << endl;
}

void cicloInfinito() {
    for(;;) {
        string opt;
        cout << "Press \"e\" to exit" << endl;
        cin  >> opt;

        if (opt == "e") {
            break;
        }
    }
}

void deseaContinuar() {
    string seguir;

    do {
        cout << "Desea continuar? ";
        cin >> seguir;
    } while (seguir != "n");
}

void promedio() {
    float numero, sumador = 0, c = 0, promedio;
    string seguir;

    // cout << "Cuantos numeros quiere promediar? ";
    // cin << numero;

    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
        sumador = sumador + numero;

        cout << "Desea continuar? ";
        cin >> seguir;
        c++;
    } while (seguir != "n");

    promedio = sumador / c;
    cout << "El promedio es: " << promedio << endl;
}
