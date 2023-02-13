#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y);
void ruletaF();
void showRuleta();
void animation(int index);
// int menu();

int ruleta[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main()
{
    srand(time(NULL));
    ruletaF();
    return 0;
}

void showRuleta() {
    gotoxy(10, 0);
    for (int i = 0; i < 9; i++) {
        cout << ruleta[i] << "  ";
    }

    cout << endl;
}

void animation(int index) {
    for (int i = 0; i < 9; i++) {
        gotoxy(10 + i * 3,0);
        Sleep(200);

        if (i == index) {
            break;
        }
    }
}

void ruletaF()
{
    char opt;
    int a = 0;
    do
    {
        showRuleta();
        gotoxy(0, 2);
        cout << " [1]>> par" << endl;
        cout << " [2]>> impar" << endl;
        cout << " [3]>> numero" << endl;
        cout << " [4]>> exit" << endl;
        cout << endl;

        cout << "send an option: " << endl;
        cin >> opt;
        cout << endl;

        int guess = rand() % 9;

        animation(guess); cout << endl;
        cout << "Numero de la ruleta: " << ruleta[guess] << endl;

        gotoxy(0, 10);
        // opt = menu();
        switch(opt)
        {
        case '1':
            if (ruleta[guess] % 2 == 0)
            {
                cout << "You won $5!" << endl;
                a = a + 5;
            }
            else
            {
                cout << "You lost" << endl;
            }
            break;
        case '2':
            if (ruleta[guess] % 2 != 0)
            {
                cout << "You won $5!" << endl;
                a = a + 5;
            }
            else
            {
                cout << "You lost" << endl;
            }
            break;
        case '3':
            cout << "Enter the number (1 - 9): ";
            int n;
            cin >> n;
            if (ruleta[guess] == n)
            {
                cout << "You won $1080!" << endl;
                a = a + 1080;
            }
            else
            {
                cout << "You lost" << endl;
            }
            break;
        }

        cout << "You won $" << a << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        Sleep(3000);
        system("cls");

    } while (opt != '4');
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
