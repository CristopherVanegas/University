#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

using namespace std;

enum animales
{
    conejo,
    tortuga
};

int posX_conejo = 2;
int posY_conejo = 5;

int posX_tortuga = 2;
int posY_tortuga = 10;

void gotoxy(int x, int y);
void spawn(animales especie, int posX, int posY);
void mov(animales especie, int posX, int posY);


int main()
{
    srand(time(NULL));  // initializing the random seed

    spawn(conejo, posX_conejo, posY_conejo);
    spawn(tortuga, posX_tortuga, posY_tortuga);

    do {
        mov(conejo, posX_conejo, posY_conejo);
        mov(tortuga, posX_tortuga, posY_tortuga);
    } while (posX_conejo < 50 || posX_tortuga < 50);
    return 0;
}


void spawn(animales especie, int posX, int posY)
{
    if (especie == tortuga)
    {
        gotoxy(posX, posY);
        cout << "T";

    }
    else if (especie == conejo)
    {
        gotoxy(posX, posY);
        cout << "C";
    }
}


void mov(animales especie, int posX, int posY)
{
    switch (especie)
    {
    case conejo:
        for (int step = 2; step <= 52; step++)
        {
            step = 1 + rand() % 3;

            switch (step)
            {
            case 1:
                gotoxy(posX, posY);
                cout << " ";
                posX = posX + step;
                gotoxy(posX, posY);
                cout << "C";
                break;

            case 2:
                gotoxy(posX, posY);
                cout << " ";
                posX = posX + step;
                gotoxy(posX, posY);
                cout << "C";
                break;
            case 3:
                gotoxy(posX, posY);
                cout << " ";
                posX = posX + step;
                gotoxy(posX, posY);
                cout << "C";
                break;

            Sleep(100);
            }
        }
        break;


    case tortuga:
        for (int step = 2; step <= 52; step++)
        {
            step = 1 + rand() % 3;

            switch (step)
            {
            case 1:
                gotoxy(posX, posY);
                cout << " ";
                posX = posX + step - 1;
                gotoxy(posX, posY);
                cout << "C";
                break;

            case 2:
                gotoxy(posX, posY);
                cout << " ";
                posX = posX + step - 1;
                gotoxy(posX, posY);
                cout << "C";
                break;
            case 3:
                gotoxy(posX, posY);
                cout << " ";
                posX = posX + step - 1;
                gotoxy(posX, posY);
                cout << "C";
                break;
            }

            Sleep(100);
        }
        break;
    }
}


void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

