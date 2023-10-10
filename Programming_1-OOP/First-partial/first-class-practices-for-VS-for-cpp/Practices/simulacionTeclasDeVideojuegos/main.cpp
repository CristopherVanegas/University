#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);  // declaracion de gotoxy, funcion para obtener coordenada en la consola.

int main()
{
    char x;
    int posX = 50;
    int posY = 12;
    gotoxy(posX, posY);
    cout << "*";

    for (;;) {
        x = getch();
        // cin >> x;
        // cout << x;

        if (x == 'w'){
            gotoxy(posX, posY); cout << " ";
            posY = posY - 1;
            gotoxy(posX, posY); cout << "*";
        }
        else if (x == 'a') {
            gotoxy(posX, posY); cout << " ";
            posX = posX - 1;
            gotoxy(posX, posY); cout << "*";
        } else if (x == 'd') {
            gotoxy(posX, posY); cout << " ";
            posX = posX + 1;
            gotoxy(posX, posY); cout << "*";
        } else if (x == 's') {
            gotoxy(posX, posY); cout << " ";
            posY = posY + 1;
            gotoxy(posX, posY); cout << "*";
        }
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
