#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

using namespace std;

int posX[10];
int posY[10];

void gotoxy(int x, int y);
void addBattleShips(int posX[], int posY[]);
void marco(int minXY, int endX, int endY, int ms);
void showBattleShips(int posX[], int posY[]);
bool verificarSiGano(int score);
void askForCoor(int posX[], int posY[]);
void showBattleShipCoors(int posX[], int posY[]);

int main()
{
    srand(time(NULL));
    addBattleShips(posX, posY);
    askForCoor(posX, posY);
    return 0;
}

bool verificarSiGano(int score) {
    if (score == 10)
        return true;
    else
        return false;
}

void askForCoor(int posX[], int posY[]) {
    int x, y;
    int score = 0;
    int attmp_count = 1;
    showBattleShips(posX, posY);
    showBattleShipCoors(posX, posY);

    do {
        // system("cls");

        gotoxy(25, 3); cout << "                                          ";
        gotoxy(25, 4); cout << "                                          ";

        gotoxy(25, 3); cout << "Ingrese una coordenada en X maximo 20: "; cin >> x;
        gotoxy(25, 4); cout << "Ingrese una coordenada en Y maximo 20: "; cin >> y;

        for (int i = 0; i < 10; i++) {
            if ((x == posX[i]) && (y == posY[i])) {
                gotoxy(25, 7); cout << "                            ";
                gotoxy(25, 7); cout << "Has eliminado un battleship!";
                gotoxy(x, y); cout << " ";
                score = score + 1;
                break;

            } else {
                gotoxy(25, 8); cout << "                      ";
                gotoxy(25, 8); cout << "No has eliminado nada!";
                break;
            }
        }

        gotoxy(25, 10); cout << "Score: " << score;
        attmp_count = attmp_count + 1;

        Sleep(300);
        gotoxy(25, 7); cout << "                            ";
        gotoxy(25, 8); cout << "                      ";
    } while (verificarSiGano(score) == false);
}

void showBattleShips(int posX[], int posY[]) {
    for ( int i = 0; i < 10; i++ ) {
            if (posX[i] == NULL) {
                cout << "----------------------------";
            } else {
                gotoxy(posX[i], posY[i]); cout << char(254);
            }
    }
}

void showBattleShipCoors(int posX[], int posY[]) {
    int ln_count_y = 22;

    for (int i = 0; i < 10; i ++) {
        gotoxy(0, ln_count_y); cout << "Battleship " << i + 1 << " coor (" << posX[i] << ", " << posY[i] << ")";
        ln_count_y = ln_count_y + 1;
    }
}

void addBattleShips(int posX[], int posY[]) {
    int ln_count_y = 22;

    for (int i = 0; i < 10; i ++) {
        posX[i] = 1 + rand() % 20;
        posY[i] = 1 + rand() % 20;
    }
}

void marco(int minXY, int endX, int endY, int ms) {
    // variables delimitadoras para X y Y

    // paredes arriba/abajo
    for (int i = minXY; i <= endX; i++) {
            gotoxy(i, minXY); cout << char(205);    // horizontal arriba
            gotoxy(i, endY); cout << char(205);    // horizontal abajo
            Sleep(ms);
    }

    // paredes laterales
    for (int j = minXY; j <= endY; j++) {
            gotoxy(minXY, j); cout << char(178);        // vertical izquierda
            gotoxy(endX, j); cout << char(178);       // vertical derecha
            Sleep(ms);
    }

    // re-escribe las esquinas
    gotoxy(minXY, minXY); cout << char(220);
                Sleep(ms);

    gotoxy(minXY, endY); cout << char(223);
                Sleep(ms);

    gotoxy(endX, endY); cout << char(223);
                Sleep(ms);

    gotoxy(endX, minXY); cout << char(220);
                Sleep(ms);


    gotoxy(0, endY + 2);
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
