#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);  // declaracion de gotoxy, funcion para obtener coordenada en la consola.
int y(int x);   // declaracion de funcionLineal();

int main()
{
    for (int x = 0; x <= 3; x ++) {
          gotoxy(x, 24-y(x)); cout << "*" << endl;
    }

    gotoxy(0, 25);
    return 0;
}

int y(int x) {
    return (3*x) + 1;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
