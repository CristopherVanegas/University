#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

void scroll();
void barraDeCarga();
void marco();
void gotoxy(int x,int y);

string name = "Cristopher Vanegas";
string voidName = "                  ";

int main()
{
    marco();
    scroll();
    barraDeCarga();
    gotoxy(0, 25);
    cout << endl;
    return 0;
}

void scroll()
{
    int y = 5, delay = 1;
    for (int i = 1; i < 29; i++)
    {
        gotoxy(i, 5);
        cout << name;
        Sleep(delay);
        gotoxy(i, 5);
        cout << voidName;
        Sleep(delay);
    }
    gotoxy(30, 5);
    cout << name;
}

void barraDeCarga()
{
    int y = 7, delay = 15;
    for(int i = name.length() + 1; i < name.length() + 42; i++)
    {
        gotoxy(i, 7);
        cout << char(219);
        Sleep(delay);
    }
}

void marco() {
    int delay = 2;
    char c = 219;
    for (int i = 0; i < 80; i++) {
        // top border
        gotoxy(i, 0); cout << c;
        Sleep(delay);
    }
    for (int j = 0; j < 14; j++) {
        // left border
        gotoxy(0, j); cout << c;
        Sleep(delay);
    }
    for (int i = 0; i < 80; i++) {
        // bottom border
        gotoxy(i, 13); cout << c;
        Sleep(delay);
    }
    for (int j = 13; j >= 0; j--) {
        // right border
        gotoxy(79, j); cout << c;
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
