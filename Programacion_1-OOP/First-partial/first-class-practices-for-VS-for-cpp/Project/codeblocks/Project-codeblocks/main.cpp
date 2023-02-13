#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
//#include <cstdlib>

using namespace std;

void marco(int startXY, int endX, int endY);
void gotoxy(int x, int y);
void game();
void mov(char key);
void bombs();
bool isExploted();
void gameTerminated();
bool playAgain();


int posX = 47, posY = 12;
int bombPosX, bombPosY;
int startXY_glob = 1, endX_glob = 95, endY_glob = 25;


int main()
{
    srand(time(NULL));  // start up the seed rand for "randomly" get numbers

    do {
        system("cls");
        marco(startXY_glob, endX_glob, endY_glob);
        game();
    } while (playAgain());
        system("cls");
        gotoxy(3, 3); cout << "";
}


void game() {
    // Point point;                 // using classes
    // int posX = 47, posY = 12;

    gotoxy(posX, posY); cout << char(254);  // set the cursor in the center of the screen
    char key;

    // spawns bombs randomly
    bombs();

    // reads for key buttons
    do {
        key = getch();
        mov(key);

        if (isExploted())
            break;
        else
            continue;
    } while (key != 'n');

    gotoxy(startXY_glob, endY_glob + 1); cout << "";
}


void bombs() {
    bombPosX = (startXY_glob + 1) + rand() % ((endX_glob - 1)+1-(startXY_glob + 1));
    bombPosY = (startXY_glob + 1) + rand() % ((endY_glob - 1)+1-(startXY_glob + 1));

    gotoxy(bombPosX, bombPosY); cout << char(157);
}


bool isExploted() {
    if (posX == bombPosX && posY == bombPosY) {
        gameTerminated();
        return true;
    } else {
        return false;
    }
}


void gameTerminated() {
    gotoxy(35, 23); cout << "You exploted, Game Over!";
}


bool playAgain() {
    char answer;
    do {
        gotoxy(3, 3); cout << "Do you want to play again? (y / n) ";
        answer = getch();

        if (answer == 'y')
            return true;
        else if (answer == 'n')
            return false;
    }
    while(answer != 'y' || answer != 'n');
}


void mov(char key) {
    // if (posX-1 > startXY_glob && posX+1 < endX_glob && posY-1 > startXY_glob && posY+1 < endY_glob) {

    if (posY-1 > startXY_glob && key == 'w') {
        gotoxy(posX, posY); cout << " ";
        posY = posY - 1;
        gotoxy(posX, posY); cout << char(254);
    }

    else if (posX-1 > startXY_glob && key == 'a') {
        gotoxy(posX, posY); cout << " ";
        posX = posX - 1;
        gotoxy(posX, posY); cout << char(254);
    }

    else if (posY+1 < endY_glob && key == 's') {
        gotoxy(posX, posY); cout << " ";
        posY = posY + 1;
        gotoxy(posX, posY); cout << char(254);
    }

    else if (posX+1 < endX_glob && key == 'd') {
        gotoxy(posX, posY); cout << " ";
        posX = posX + 1;
        gotoxy(posX, posY); cout << char(254);
    }
}


void marco(int startXY, int endX, int endY) {
    // start XY = 1; endX = 100; endY = 90;

    gotoxy(startXY, startXY); cout << char(201);
    gotoxy(startXY, endY); cout << char(200);
    gotoxy(endX, startXY); cout << char(187);
    gotoxy(endX, endY); cout << char(188);


    for (                                       //  top line
        int x = startXY + 1;
            x < endX;
            x++
        )
    {
        gotoxy(x, startXY); cout << char(205);
    }

    for (                                       // left line
        int y = startXY + 1;
            y < endY;
            y++
        )
    {
        gotoxy(startXY, y); cout << char(186);
    }

    for (                                       // right line
        int y = startXY + 1;
        y < endY;
        y++
        )
    {
        gotoxy(endX, y); cout << char(186);
    }

    for (                                       //  bottom line
        int x = startXY + 1;
        x < endX;
        x++
        )
    {
        gotoxy(x, endY); cout << char(205);
    }
}


void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

