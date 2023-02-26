#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y);
void llenar();
void mostrar();

char cube[3][3][3];

int main()
{
    srand(time(NULL));
    llenar();
    return 0;
}

void llenar()
{
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                switch (rand() % 2) {
                case 0:
                    if (cube[k][i][j] != 'X')
                        cube[k][i][j] = 'O';
                    break;
                case 1:
                    if (cube[k][i][j] != 'O')
                        cube[k][i][j] = 'X';
                    break;
                }

                mostrar();
                Sleep(100);
            }
        }
    }
}

void mostrar() {
    int space = 0;

    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                gotoxy(j, i + space); cout << cube[k][i][j];
            }
        }

        space = space + 4;
    }

    cout << endl;
    cout << endl;
    cout << endl;
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
