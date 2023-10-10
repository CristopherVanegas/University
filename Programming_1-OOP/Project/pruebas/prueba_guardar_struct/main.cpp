#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

struct Product
{
    string description;
    int cant;
    int precio;

};

int id = 0;

struct Factura
{
    string name;
    int ID;
    string date[3]; // d, m, y
    Product detalleProductos[10];
    int total;
};


// creo un array de tipo factura para guardar estas estructuras de datos.
Factura facturas[255];


void gotoxy(int x, int y);

int main()
{
    srand(time(NULL));

    int d;

    cout << "Ingrese la cantidad de facturas: "; cin >> d;

    for (int i = 0; i < d; i++) {/*
        facturas[i] = {
            ("Clientes: " + to_string(i + 1)),
            (rand() + 9999),
            [to_string((1 + rand() % 31)), to_string((1 + rand() % 12)), to_string((2004 + rand() % 2023))],
            {
                "Product" + to_string(i + 1),
                1 + rand() % 10,
                1 + rand() % 500
            },
            99999
        };
        */

        facturas[i].name = "Cliente " + to_string(i + 1);
        facturas[i].ID = (rand() + 9999);

        facturas[i].date[0] = to_string((1 + rand() % 31));
        facturas[i].date[1] = to_string((1 + rand() % 12));
        facturas[i].date[2] = to_string((2004 + rand() % 2023));

        facturas[i].detalleProductos[i].cant = 1 + rand() % 10;
        facturas[i].detalleProductos[i].description = "Product" + to_string(i + 1);
        facturas[i].detalleProductos[i].precio = 1 + rand() % 500;

        facturas[i].total = 99999;
    }

    system("cls");

    for (int i = 0; i < d; i++) {
        gotoxy(0, i); cout << facturas[i].name;
    }
    return 0;
}

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
