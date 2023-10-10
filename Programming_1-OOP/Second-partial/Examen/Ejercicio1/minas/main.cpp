// Est. Cristopher Vanegas
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

struct Asteroide {
    int posX = rand() % 80;
    int posY = rand() % 20;
};

struct Puntero {
    int posX = rand() % 80;
    int posY = rand() % 20;
};

Asteroide a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
Puntero cursor;

Asteroide asteroides[10] = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10};

int r = 20, c = 80;
char matrix[20][80];

Asteroide capturados[10];
int score = 0;

void gotoxy(int x,int y);
void llenar();
void show();

int main()
{
    llenar();

    for (int i = 0; i < r; i++) {
        gotoxy(0, 23); cout << "Score: " << score;

        for (int j = 0; j < c; j++) {
            if (matrix[i][j + 1] == '*') {
                score = score + 1;
            }

            matrix[cursor.posY][cursor.posX] = ' ';
            cursor.posY = i;
            cursor.posX = j;
            matrix[cursor.posY][cursor.posX] = '>';
            show();
            Sleep(1);
        }
    }

    return 0;
}

void llenar() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = ' ';
        }
    }

    for (int i = 0; i < 10; i++) {
        matrix[asteroides[i].posY][asteroides[i].posX] = '*';
    }
}

void show() {
    // show meteors
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            gotoxy(j + 3, i + 3); cout << matrix[i][j];
        }
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
