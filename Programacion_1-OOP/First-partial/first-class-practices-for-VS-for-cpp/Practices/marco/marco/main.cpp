#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);  // declaracion de gotoxy, funcion para obtener coordenada en la consola.
void marco(int minXY, int endX, int endY, int ms);

int main()
{
    marco(2, 115, 21, 5); // marco(125 = X, 21 = Y);  // crea los marcos
    return 0;
}

void marco(int minXY, int endX, int endY, int ms) {
    // variables delimitadoras para X y Y

    // paredes arriba/abajo
    for (int i = minXY; i <= endX; i++) {
            gotoxy(i, minXY); cout << char(205);    // horizontal arriba
            gotoxy(i, endY); cout << char(205);    // horizontal abajo
            Sleep(ms);
    }

    // paredes laterales
    for (int j = minXY; j <= endY; j++) {
            gotoxy(minXY, j); cout << char(178);        // vertical izquierda
            gotoxy(endX, j); cout << char(178);       // vertical derecha
            Sleep(ms);
    }

    // re-escribe las esquinas
    gotoxy(minXY, minXY); cout << char(220);
                Sleep(ms);

    gotoxy(minXY, endY); cout << char(223);
                Sleep(ms);

    gotoxy(endX, endY); cout << char(223);
                Sleep(ms);

    gotoxy(endX, minXY); cout << char(220);
                Sleep(ms);


    gotoxy(0, endY + 2);
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
