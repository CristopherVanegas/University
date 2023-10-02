#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <windows.h>

using namespace std;

string names[10] = {
    "Yadira",
    "Lenin",
    "Tiff",
    "Mabe",
    "Eddy",
    "Andy",
    "Moya",
    "Davide",
    "Cristopher",
    "Emilio"
};

int ventas[10]; // 500 - 2000
int descuento[10]; // < vals1

int d = 10;
float desc = 0.4;

void mostrarDatos();
int mayorVentaNeta(int arr_vent[], int arr_desc[], int d);
float promVentas(int arr[], int d);
int mayorCliente(int arr[], int d);
void aplicarDescuento(int arr[], int d);
void randomVals(int arr[], int d);
void gotoxy(int x,int y);
void graficarDiagramaBarras(int arr[], int d);

int main()
{
    srand(time(NULL));
    randomVals(ventas, d);
    aplicarDescuento(descuento, d);

    mostrarDatos();

    cout << endl << endl;

    // 1) quien es el mayor cliente
    cout << " [ console ] El mayor cliente es " << names[mayorCliente(ventas, d)] << endl;

    // 2) Promedio ventas
    cout << " [ console ] El promedio de ventas es " << promVentas(ventas, d) << endl;

    // 3) quien tiene > ventaNeta = (venta - desc)
    cout << " [ console ] El que mayor venta neta posee es " << names[mayorVentaNeta(ventas, descuento, d)] <<endl;

    graficarDiagramaBarras(ventas, d);

    cout << endl;

    return 0;
}

void graficarDiagramaBarras(int arr[], int d) {
    for (int i = 0; i < d; i++) {   // Eje Y
        gotoxy(2, i + 10); cout << "[] " << names[i];

        int pts = round(arr[i] / 100);
        for (int j = 0; j < pts; j++) {
            gotoxy(17 + (j * 2), i + 10); cout << char(219);
        }
    }
}

void mostrarDatos() {
    for (int i = 0; i < 10; i++) {
        gotoxy(2 + (i * 12), 1); cout << names[i];
        gotoxy(2 + (i * 12), 2); cout << ventas[i];
        gotoxy(2 + (i * 12), 3); cout << descuento[i];
    }
}

int mayorVentaNeta(int arr_vent[], int arr_desc[], int d) {
    int indx = 0;
    int aux = 0;
    for (int i = 0; i < d; i++) {
        if ((arr_vent[i] - arr_desc[i]) > aux) {
            aux = (arr_vent[i] - arr_desc[i]);
            indx = i;
        }
    }
    return indx;
}

float promVentas(int arr[], int d) {
    int a = 0;
    for (int i = 0; i < d; i++) {
        a += arr[i];
    }
    return a / 10;
}

int mayorCliente(int arr[], int d) {
    int indx = 0;
    int ventasAux = 0;
    for (int i = 0; i < d; i++) {
        if (arr[i] > ventasAux) {
            ventasAux = arr[i];
            indx = i;
        }
    }
    return indx;
}

void aplicarDescuento(int arr[], int d) {
    for (int i = 0; i < d; i++) {
        arr[i] = ventas[i] * desc;
    }
}

void randomVals(int arr[], int d) {
    for (int i = 0; i < d; i++) {
        arr[i] = 500 + rand() % 2000;
    }
}

void gotoxy(int x,int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
