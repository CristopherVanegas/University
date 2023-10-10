#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

int row = 12, col = 8;
char table[12][8];

int a = 0;

struct BattleShip
{
    int posX = 0;
    int posY = 0;
};

int cantBattleShips = 5;

BattleShip BattleShips[5];
BattleShip doneBattleShips[5];

void game();
void gotoxy(int x,int y);
void spawnBattleShips();
void showBattleShips();
void shoot();
void showCoors();

int main()
{
    srand(time(NULL));
    game();
    return 0;
}

void game()
{
    spawnBattleShips();
    showBattleShips();
    showCoors();

    do
    {
        shoot();
    }
    while(a < cantBattleShips);
}

void shoot()
{
    int posX, posY;
    gotoxy(col + 5, 1);
    cout << " [] Enter a position for pos X (max " << col << "): ";
    cin >> posX;
    gotoxy(col + 5, 1);
    cout << " [] Enter a position for pos Y (max " << row << "): ";
    cin >> posY;
    gotoxy(col + 5, 1);
    cout << "                                                    ";


    if (posX != doneBattleShips)

    for (int i = 0; i < cantBattleShips; i++)
    {
        if ((posX == BattleShips[i].posX) && (posY == BattleShips[i].posY))
        {
            gotoxy(col + 5, 1);
            cout << " [] You shot a BattleShip in X:" << posX << " and Y: " << posY;

            doneBattleShips[i].posX = posX;
            doneBattleShips[i].posY = posY;

            gotoxy(posX, posY);
            cout << " ";

            a = a + 1;
        } else {
            gotoxy(col + 5, 1);
            cout << "[] You did not shoot a BattleShip in X:" << posX << " and Y: " << posY;
        }

        Sleep(1000);

        gotoxy(col + 5, 1);
        cout << "                                                     " << posY;
    }
}

void spawnBattleShips()
{
    for (int i = 0; i < cantBattleShips; i++)
    {
        BattleShips[i].posX = rand() % row;
        BattleShips[i].posY = rand() % col;
    }
}

void showBattleShips()
{
    for (int i = 0; i < cantBattleShips; i++)
    {
        gotoxy(BattleShips[i].posX, BattleShips[i].posY);
        cout << "*";
    }
}

void showCoors()
{
    for (int i = 0; i < cantBattleShips; i++)
    {
        gotoxy(0, row + i + 3);
        cout << "X: " << BattleShips[i].posX << " - Y: " << BattleShips[i].posY;
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
