#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

using namespace std;

void scroll();
void barraDeCarga();
void marco();
void game();
void sum();
void gotoxy(int x,int y);

#define WIDTH 80
#define HEIGHT 16
#define pWIDTH 14
#define pHEIGHT 3

string name = "Cristopher Vanegas";
string voidName = "                  ";

int playerCards[15];
int pcCards[15];
int playerCardsCounter = 0;
int pcCardsCounter = 0;
int playerAcum = 0;
int pcAcum = 0;

void pressToContinue()
{
    gotoxy((80-28)/2 + pWIDTH, 9 + pHEIGHT);
    cout << "Press any key to continue...";
    getch();
}

int main()
{
    srand(time(NULL));
    marco();
    scroll();
    barraDeCarga();
    pressToContinue();

    game();

    gotoxy(0, 25);
    cout << endl;
    return 0;
}

int realNum(int num) {
    if (num > 13 && num < 27) return num - 13;
    if (num > 26 && num < 40) return num - (13*2);
    if (num > 39 && num <= 52) return num - (13*3);
}

void showCards() {
    system("cls");
    marco();

    sum();

    gotoxy(pWIDTH + 2, pHEIGHT + 3);
    printf(" > Player Cards\n");
    gotoxy(pWIDTH + 2, pHEIGHT + 4);
    for (int i = 0; i <= playerCardsCounter; i++) {
        printf(" > %d", realNum(playerCards[i]));
    }
    gotoxy(pWIDTH + 2, pHEIGHT + 5);
    printf(" [ console ] Player acum: %d", playerAcum);

    gotoxy(30, pHEIGHT + 8);
    printf("> PC Cards");
    gotoxy(30, (pHEIGHT + 9));
    for (int i = 0; i <= pcCardsCounter; i++) {
        printf(" > %d", realNum(pcCards[i]));
    }
    gotoxy(pWIDTH + 2, pHEIGHT + 10);
    printf(" [ console ] PC acum: %d", pcAcum);

    string ganador = "";

    if (playerAcum > 21 && pcAcum > 21) {
        cout << endl << endl << " [ console ] Ambos perdieron!" << endl;
    }
    else if ((playerAcum && pcAcum) == 21) printf("Quedaron empate!");
    else if (playerAcum == 21) ganador = "Player";
    else if (pcAcum == 21) ganador = "PC";
    else if (playerAcum < 21 && playerAcum > pcAcum) ganador = "Player";
    else if (pcAcum < 21 && pcAcum > playerAcum) ganador = "PC";

    gotoxy(pWIDTH + 2, pHEIGHT + 11);
    cout << endl << endl << " [ console ] El ganador es " << ganador << endl;
}

bool esLaMisma(int arr[], int num) {
    int longitud = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < longitud; i++) if (arr[i] == num) return true;

    return false;
}

void sum() {
    int c = 0;

    for (int i = 0; i < 15; i++) c = c + realNum(playerCards[i]);
    playerAcum = c;

    c = 0;

    for (int i = 0; i < 15; i++) c = c + realNum(pcCards[i]);
    pcAcum = c;
}

void game()
{
    system("cls");
    marco();
    do
    {
        gotoxy(pWIDTH + 2, pHEIGHT + 2);
        cout << "[console] Jugador desea tomar una carta? (y / n): ";

        // carta para el player
        if (getche() == 'y') {
            int n = 1 + rand() % 52;

            while (esLaMisma(playerCards, n)) {
                n = 1 + rand() % 52;
            }

            playerCards[playerCardsCounter] = n;
            ++playerCardsCounter;
        }

        gotoxy(pWIDTH + 2, pHEIGHT + 2);
        cout << "                                                   ";
        gotoxy(pWIDTH + 2, pHEIGHT + 2);
        cout << "[console] PC desea tomar una carta? (1 / 0): ";
        Sleep(500);

        int pcAns = rand() % 2;

        // carta para el PC
        if (pcAns == 1) {
            int n = 1 + rand() % 52;

            while (esLaMisma(pcCards, n)) {
                n = 1 + rand() % 52;
            }

            pcCards[pcCardsCounter] = n;
            ++pcCardsCounter;
        }
        gotoxy(pWIDTH + 2, pHEIGHT + 2);
        cout << "[console] PC desea tomar una carta? (1 / 0): " << pcAns;

        Sleep(1500);
        gotoxy(pWIDTH + 2, pHEIGHT + 2);
        cout << "                                              ";

        gotoxy(pWIDTH + 2, pHEIGHT + 2);
        cout << "[console] Desea seguir jugando? (any / n): ";
    } while(getch() != 'n');

    showCards();
}

void scroll()
{
    int y = 5, delay = 1;
    for (int i = 1; i < 29; i++)
    {
        gotoxy(i + pWIDTH, 5 + pHEIGHT);
        cout << name;
        Sleep(delay);
        gotoxy(i + pWIDTH, 5 + pHEIGHT);
        cout << voidName;
        Sleep(delay);
    }
    gotoxy(30 + pWIDTH, 5 + pHEIGHT);
    cout << name;
}

void barraDeCarga()
{
    int y = 7, delay = 15;
    for(int i = name.length() + 1; i < name.length() + 42; i++)
    {
        gotoxy(i + pWIDTH, 7 + pHEIGHT);
        cout << char(219);
        Sleep(delay);
    }
}

void marco()
{
    int delay = 0;
    char c = 219;
    for (int i = 0; i < WIDTH; i++)
    {
        // top border
        gotoxy(i + pWIDTH, 0 + pHEIGHT);
        cout << c;
        Sleep(delay);
    }
    for (int j = 0; j < HEIGHT; j++)
    {
        // left border
        gotoxy(0 + pWIDTH, j + pHEIGHT);
        cout << c;
        Sleep(delay);
    }
    for (int i = 0; i < WIDTH; i++)
    {
        // bottom border
        gotoxy(i + pWIDTH, HEIGHT + pHEIGHT);
        cout << c;
        Sleep(delay);
    }
    for (int j = HEIGHT; j >= 0; j--)
    {
        // right border
        gotoxy(WIDTH + pWIDTH, j + pHEIGHT);
        cout << c;
        Sleep(delay);
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
