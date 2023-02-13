// Est. Cristopher Vanegas

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <cmath>

using namespace std;

int r = 3;
int c = 12;
string tabla[3][12];
string nombres[12] = {
    "Pablo",
    "Cristopher",
    "Natt",
    "Emilio",
    "Alondra",
    "Damian",
    "Melva",
    "Francisco",
    "Stephany",
    "Andy",
    "Mabe",
    "Luis"
};

void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void llenarTabla() {
    for (int i = 0; i < c; i++) {
        //cout << ">> Ingrese nombre del cliente: ";
        //cin >> tabla[0][i];
        tabla[0][i] = nombres[i];
    }
    for (int i = 0; i < c; i++) {
        tabla[1][i] = to_string(1 + rand() % 500);
    }
    for (int i = 0; i < c; i++) {
        tabla[2][i] = to_string(1 + rand() % 100);
    }
}

int promedio() {
    int a = 0;
    for (int i = 0; i < c; i++) {
        a = a + stoi(tabla[1][i]);
    }

    return trunc(a/c);
}

void mayorValor() {
    int mayor = stoi(tabla[1][0]);
    int ind = 0;
    string persona;

    for (int i = 1; i < c; i++) {

        if (mayor < (stoi(tabla[1][i]))) {
            mayor = (stoi(tabla[1][i]));
            ind = i;
        }
    }

    persona = nombres[ind];
    gotoxy(2, 18); cout << ">>> El cliente con valores mayores es " << persona << " con $" << mayor << endl;
    // return 0;
}

void mostrarTabla() {

    gotoxy(5, 1); cout << "NOMBRES";
    gotoxy(5*5, 1); cout << "VALORES";
    gotoxy(5*7, 1); cout << "DESCUENTO";

    gotoxy(2, 2); cout << "-----------------------------------------------";

    for (int i = 0; i < c; i++) {
        gotoxy(5, i + 4); cout << tabla[0][i];
        gotoxy(5*5, i + 4); cout << "$" << tabla[1][i];
        gotoxy(5*7, i + 4); cout << tabla[2][i];
    }

    gotoxy(2, 16); cout << "-----------------------------------------------";


    // int indiceValorMayor = mayorValor();
    // gotoxy(2, 18); cout << ">>> El cliente con valores mayores es: " << tabla[0, mayorValor()] << endl;
    mayorValor();
    gotoxy(2, 19); cout << ">>> El promedio es de $" << promedio() << endl;
}

int main()
{
    srand(time(NULL));
    llenarTabla();
    mostrarTabla();
    return 0;
}
