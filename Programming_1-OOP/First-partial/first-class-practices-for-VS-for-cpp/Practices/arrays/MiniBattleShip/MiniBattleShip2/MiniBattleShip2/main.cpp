#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y);
void spawnBattleShips();
void showBattleShips();
void askForCoors();
void game();

void showBattleShipCoors();


int posX[10], posY[10];
int score = 0;


int main()
{
    srand(time(NULL));
    game();
    return 0;
}


void game() {
    spawnBattleShips();
    showBattleShips();
    showBattleShipCoors();

    do {
        askForCoors();

    } while(score < 10);
}

void askForCoors() {
    gotoxy(25, 4); cout << "                             ";
    gotoxy(25, 4); cout << "Press enter to send the coor!";
    gotoxy(25, 1); cout << "                            ";
    gotoxy(25, 2); cout << "                            ";
    gotoxy(25, 1); cout << "Send a position for X: "; int x; cin >> x;
    gotoxy(25, 2); cout << "Send a position for Y: "; int y; cin >> y;

    for (int i = 0; i < 10; i++) {
        if ((x == posX[i]) && (y == posY[i])) {
            gotoxy(25, 5); cout << "Great! You shot a battleship!";
            gotoxy(x, y); cout << " ";
            Sleep(1000);
            gotoxy(25, 5); cout << "                             ";
            score ++;
            break;

        } else if (i == 9 && ((x != posX[i]) && (y != posY[i]))) {
            gotoxy(25, 6); cout << "Sorry, you'd try again!"; Sleep(1000);
            gotoxy(25, 6); cout << "                       ";
            break;
        }
    }
}

void showBattleShips() {
    for (int i = 0; i < 10; i++) {
        gotoxy(posX[i], posY[i]); cout << char(15);
    }
}

void spawnBattleShips() {
    for (int i = 0; i < 10; i++) {
        posX[i] = 1 + rand() % 20;
        posY[i] = 1 + rand() % 20;
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

//////////////////////////////////////////////////////////////
/////////////////////////// EXTRA ///////////////////////////

void showBattleShipCoors() {
    for (int i = 0; i < 10; i++) {
        gotoxy(0, 22 + i); cout << "battleship n" << i + 1 << ": (" << posX[i] << ", " << posY[i] << ")";
    }
}

//////////////////////////////////////////////////////////////
