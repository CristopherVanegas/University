#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

int row = 10;
int col = 30;

struct t1
{
    int posX = rand() % col;
    int posY = rand() % row;
};

struct t2
{
    int posX = rand() % col;
    int posY = rand() % row;
};

t1 T1;
t2 T2;

string mapa[10][30];
int coef = 0;

void gotoxy(int x, int y);
void game();
void movT1();
void llenarMapa();
void mostrarMapa();

int main()
{
    srand(time(NULL));
    game();
    return 0;
}

void game()
{
    llenarMapa();
    mostrarMapa();
    for (int i = 0; i < 15; i++)
    {
        movT1();

        Sleep(500);
    }
}

void movT1()
{

    // second square
    if ((T2.posX > T1.posX) && (T2.posY > T1.posY))
    {
        coef = 1 + rand() % 3;

        mapa[T1.posY, T1.posX] = " ";
        switch(coef)
        {
        case 1:
            T1.posY++;
            break;
        case 2:
            T1.posX++;
            break;
        case 3:
            T1.posY++;
            T1.posX++;
            break;
        }
    }

    mapa[T1.posY, T1.posX] = "O->";
}

void llenarMapa() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mapa[i][j] = " ";
        }
    }
}

void mostrarMapa() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << " | " << mapa[i][j];
        }

        cout << endl;
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
