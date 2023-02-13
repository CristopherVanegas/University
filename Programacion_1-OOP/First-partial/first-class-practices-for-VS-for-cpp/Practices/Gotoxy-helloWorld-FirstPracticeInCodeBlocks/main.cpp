#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);  // declaracion de gotoxy, funcion para obtener coordenada en la consola.

int main()
{
    cout << "Hello world!" << endl;

    int a, b, c;
    gotoxy(20, 10); cout << "Ingrese primer numero" << endl;
    cin >> a;
    cout << "Ingrese segundo numero" << endl;
    cin >> b;

    c = a + b;
    cout << "El resultado es: " << c << endl;
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
