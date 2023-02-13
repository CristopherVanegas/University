#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

string tablero[8][8];
int posCabX;
int posCabY;
int contador = 0;
int movs = 0;

void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void llenar()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablero[i][j] = " _ ";
        }
    }
}

void mostrarTablero()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << tablero[i][j] << "   ";
        }

        cout << endl;
    }
}

bool noFuePosicionada() {
    if (tablero[posCabY][posCabX] == "   ") {
        return true;
    }
    else
        return false;
}

void situarCaballo()
{
    tablero[posCabY][posCabX] = " x ";
}

int posiblesMovs()
{
    char a;
    contador = 0;
    do
    {
        system("cls");
        mostrarTablero();
        situarCaballo();

        int mov = 1 + rand() % 8;

        switch (mov)
        {
        case 1:
            if (((posCabX + 1) < 8) && ((posCabY + 3) < 8)) {
                posCabX = posCabX + 1;
                posCabY = posCabY + 3;

                if (noFuePosicionada())
                    contador++;
            }
            movs++;
            break;

        case 2:
            if (((posCabX - 1) >= 0) && ((posCabY + 3) < 8)) {
                posCabX = posCabX - 1;
                posCabY = posCabY + 3;

                if (noFuePosicionada())
                    contador++;
            }
            movs++;
            break;
        case 3:
            if (((posCabX + 1) < 8) && ((posCabY - 3) >= 0)) {
                posCabX = posCabX + 1;
                posCabY = posCabY - 3;

                if (noFuePosicionada())
                    contador++;
            }

            break;
        case 4:
            if (((posCabX - 1) >= 0) && ((posCabY - 3) >= 0)) {
                posCabX = posCabX - 1;
                posCabY = posCabY - 3;

                if (noFuePosicionada())
                    contador++;
            }

            movs++;
            break;

        case 5:
            if (((posCabX + 3) < 8) && ((posCabY + 2 < 8))) {
                posCabX = posCabX + 3;
                posCabY = posCabY + 2;

                if (noFuePosicionada())
                    contador++;
            }
            movs++;
            break;

        case 6:
            if (((posCabX - 3) >= 0) && ((posCabY + 2) < 8)) {
                posCabX = posCabX - 1;
                posCabY = posCabY + 3;

                if (noFuePosicionada())
                    contador++;
            }
            movs++;
            break;
        case 7:
            if (((posCabX + 3) < 8) && ((posCabY - 2) >= 0)) {
                posCabX = posCabX + 3;
                posCabY = posCabY - 2;

                if (noFuePosicionada())
                    contador++;
            }

            break;
        case 8:
            if (((posCabX - 3) >= 0) && ((posCabY - 2) >= 0)) {
                posCabX = posCabX - 3;
                posCabY = posCabY - 2;

                if (noFuePosicionada())
                    contador++;
            }

            movs++;
            break;
        }

        // a = getch();
        // Sleep(1);
    } while (contador <= 63);

    return movs;
}

int main()
{
    srand(time(NULL));
    posCabX = rand() % 8;
    posCabY = rand() % 8;
    llenar();
    gotoxy(0, 15); cout << posiblesMovs();

    return 0;
}
