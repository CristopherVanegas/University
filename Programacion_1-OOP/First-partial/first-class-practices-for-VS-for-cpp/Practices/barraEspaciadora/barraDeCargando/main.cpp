#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);  // declaracion de gotoxy, funcion para obtener coordenada en la consola.

int main()
{
    gotoxy(7, 12);
    cout << "|" << endl;

    for (int i = 8; i <= 34; i++) {
        gotoxy(i, 11);
        cout << "-" << endl;
    }

    gotoxy(35, 12);
    cout << "|" << endl;

    for (int i = 8; i <= 34; i++) {
        gotoxy(i, 13);
        cout << "-" << endl;
    }


    for (int i = 8; i <= 34; i++) {
        gotoxy(i, 12);
        Sleep(250);
        cout << char(178);
    }


    return 0;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
