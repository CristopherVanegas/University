// Est. Cristopher Vanegas

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

float matriz[5][5];
float ventasTotalesProvincias[5] = {0, 0, 0, 0, 0};
float ventasTotalesSucursales[5] = {0, 0, 0, 0, 0};
float promedios[] = {0, 0, 0, 0, 0};

void gotoxy(int x,int y);
void llenarTabla();
void mostrarDatos();
void provinciaConMayorVenta();
void sucursalConMayorVenta();
void promedios_f();

string provincias[] = {
                          "Guayas",
                          "Manabi",
                          "Los Rios",
                          "Esmeraldas",
                          "Pichincha"
                      };

string sucursal[] = {
                        "Norte",
                        "Sur",
                        "Centro",
                        "Este",
                        "Oeste"
                    };

int main()
{
    srand(time(NULL));
    llenarTabla();
    mostrarDatos();
    provinciaConMayorVenta();
    sucursalConMayorVenta();
    promedios_f();

    return 0;
}

void promedios_f() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            switch (i) {
            case 0:
                promedios[i] = promedios[i] + matriz[i][j];
                break;
            case 1:
                promedios[i] = promedios[i] + matriz[i][j];
                break;
            case 2:
                promedios[i] = promedios[i] + matriz[i][j];
                break;
            case 3:
                promedios[i] = promedios[i] + matriz[i][j];
                break;
            case 4:
                promedios[i] = promedios[i] + matriz[i][j];
                break;
            }
        }
        promedios[i] = promedios[i]/5;
    }

    for (int i = 0; i < 5; i++) {
        gotoxy(1, i + 19); cout << "El promedio de la provincia " << provincias[i] << " es de $" << promedios[i];
    }

    cout << endl;
}

void provinciaConMayorVenta() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            switch (i) {
            case 0:
                ventasTotalesProvincias[i] = ventasTotalesProvincias[i] + matriz[i][j];
                break;
            case 1:
                ventasTotalesProvincias[i] = ventasTotalesProvincias[i] + matriz[i][j];
                break;
            case 2:
                ventasTotalesProvincias[i] = ventasTotalesProvincias[i] + matriz[i][j];
                break;
            case 3:
                ventasTotalesProvincias[i] = ventasTotalesProvincias[i] + matriz[i][j];
                break;
            case 4:
                ventasTotalesProvincias[i] = ventasTotalesProvincias[i] + matriz[i][j];
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        gotoxy(65, i + 2); cout << ventasTotalesProvincias[i];
    }

    int higher = ventasTotalesProvincias[0];
    int index;

    for (int i = 0; i < 5; i++) {
        if (ventasTotalesProvincias[4 - i] > higher) {
            higher = ventasTotalesProvincias[4 - i];
            index = i;
        }
    }

    gotoxy(1, 15); cout << "La provincia con mayor venta es: " << provincias[index] << " con: $" << higher;
}

void sucursalConMayorVenta() {

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            switch (j) {
            case 0:
                ventasTotalesSucursales[j] = ventasTotalesSucursales[j] + matriz[i][j];
                break;
            case 1:
                ventasTotalesSucursales[j] = ventasTotalesSucursales[j] + matriz[i][j];
                break;
            case 2:
                ventasTotalesSucursales[j] = ventasTotalesSucursales[j] + matriz[i][j];
                break;
            case 3:
                ventasTotalesSucursales[j] = ventasTotalesSucursales[j] + matriz[i][j];
                break;
            case 4:
                ventasTotalesSucursales[j] = ventasTotalesSucursales[j] + matriz[i][j];
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        gotoxy(i * 10 + 14, 7); cout << ventasTotalesSucursales[i];
    }

    int higher = ventasTotalesSucursales[0];
    int index;

    for (int i = 0; i < 5; i++) {
        if (ventasTotalesSucursales[4 - i] > higher) {
            higher = ventasTotalesSucursales[4 - i];
            index = i;
        }
    }

    gotoxy(1, 16); cout << "La sucursal con mayor venta es: " << sucursal[index] << " con: $" << higher << endl << endl;
}


void llenarTabla()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = 100 + rand() % 1000;
        }
    }
}

void mostrarDatos()
{
    for (int i = 0; i < 5; i++)
    {
        gotoxy(i * 10 + 14, 0);
        cout << sucursal[i];
        gotoxy(0, i + 2);
        cout << provincias[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            gotoxy(j * 10 + 14, i + 2); cout << matriz[i][j];
        }
    }
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
