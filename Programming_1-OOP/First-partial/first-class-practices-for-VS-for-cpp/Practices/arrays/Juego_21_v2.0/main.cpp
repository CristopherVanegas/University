#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y);
void game();
int setPlayers();
void ask(int d, string players[]);
bool ganador();

string players[10];
int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int cancelado = 0; // max 3 to exit the game.

int main()
{
    srand(time(NULL));
    game();
    return 0;
}

void game() {
    int d = setPlayers();
    // ask(d, players);


    do {
        ask(d, players);

    } while((ganador() == false) && (cancelado < 3));


}

bool ganador() {
    return false;
}

void ask(int d, string players[]) {
    system("cls");
    cancelado = 0;

    for (int i = 0; i < d; i++) {
        cout << "Attempt for " << players[i] << endl;
        cout << ">>> Do you want to take a card? (y / n): "; char ans; cin >> ans;
        if (ans == 'y') {
            // nRand = 1 + rand() % 11;
            a[i] = a[i] + (1 + rand() % 11);
        }

        else {
            cancelado = cancelado + 1;
        }
    }
}

int setPlayers() {
    cout << "How many players are going to participate?: "; int cPlayers; cin >> cPlayers;
    // string players[cPlayers];

    for (int i = 0; i < cPlayers; i++) {
        cout << ">>> Enter the player n" << i + 1 << " name: "; cin >> players[i];
    }

    cout << endl;
    return cPlayers;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
