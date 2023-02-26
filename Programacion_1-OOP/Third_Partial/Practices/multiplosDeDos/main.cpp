#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

int matrix[10][20];
int r = 10, c = 20;

struct Cursor {
    int posX = rand() % 20;
    int posY = rand() % 10;
};

Cursor cursor;

void gotoxy(int x,int y);
void show();
void llenar();
void mover();
void mov(char key);

int main()
{
    gotoxy(15, 0); cout << "AWSD To move!  -- PRESS 'e' TO EXIT THE GAME" << endl;
    srand(time(NULL));
    llenar();

    show();
    mover();
    return 0;
}

void llenar() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            // generates number
            int n = 2 + rand() % 99;

            if (n % 2 == 0) {
                matrix[i][j] = n;
            }
        }
    }
}

void mover() {
    char key;

    do {
        key = getch();
        mov(key);


        gotoxy(cursor.posX + 4, cursor.posY + 4); cout << "*";  // mov

    } while (key != 'e');
}

void mov(char key) {
    if (key == 'w')
        cursor.posY = cursor.posY - 2;
    if (key == 's')
        cursor.posY  = cursor.posY + 2;
    if (key == 'a')
        cursor.posX = cursor.posX - 5;
    if (key == 'd')
        cursor.posX = cursor.posX + 5;
}

void show() {
    int y = 0, y2 = 0;
    for (int i = 0; i < r; i++) {
        int x = 0;

        gotoxy(x + 4, y + 4); cout << " -";
        gotoxy(x + 4, y2 + 5); cout << "| ";

        for (int j = 0; j < c; j++) {
            gotoxy(x + 4, y + 4); cout << "-----";

            if (matrix[i][j] == 0) {
                gotoxy(x + 6, y2 + 5); cout << "  ";
            }
            else if (matrix[i][j] < 10) {
                gotoxy(x + 6, y2 + 5); cout << matrix[i][j] << " ";
            }
            else {
                gotoxy(x + 6, y2 + 5); cout << matrix[i][j];
            }

            gotoxy(x + 8, y2 + 5); cout << " |";

            x = x + 5;
        }

        y = y + 2;
        y2 = y2 + 2;
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
