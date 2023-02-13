#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

int mazo[21]; // 21 como maximo de cartas que posee
int mazoSize = 1;

void game();
void entregarCarta();
bool terminoElJuego();
void gotoxy(int x,int y);
void showAddition();

int main()
{
    srand(time(NULL));
    game();

    return 0;
}

void game() {
    do {
        entregarCarta();
        cout << endl;

    } while (terminoElJuego() == true);
}

void entregarCarta() {
    cout << "Desea una carta? (y / n) "; char otraCarta = getche(); cout << endl;

    if (otraCarta == 'y') {
        mazo[mazoSize] = 1 + rand() % 11;
        mazoSize++;
    }
}


bool terminoElJuego() {
    int acum = 0;
    showAddition();

    for (int i = 0; i < mazoSize ; i++) {
        acum = acum + mazo[i];
    }

    if (acum > 21) {
        cout << "Perdiste!" << endl;
        Sleep(1000);
        return false;

    } else if (acum == 21) {
        cout << "Tienes 21!" << endl;
        Sleep(1000);
        return true;

    }

    cout << "Quieres seguir jugando? (y / any key ) "; char ans = getche(); cout << endl;
    if (acum > 21 && ans == 'y') {
        return true;
    } else {
        cout << "Hasta la proxima!" << endl;
        Sleep(1000);
        return false;
    }
}

void showAddition() {
    int a = 0;
    for (int i = 0; i < mazoSize; i++) {
        a = a + mazo[i];
    }

    gotoxy(20, 1); cout << "La sumatoria es: " << a << endl;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
