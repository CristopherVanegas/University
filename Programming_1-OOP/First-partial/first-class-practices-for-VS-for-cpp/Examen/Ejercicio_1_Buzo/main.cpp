#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y);
void game();

int G = 10;
int N = 0;
int T = 0;

int main()
{
    srand(time(NULL));
    gotoxy(5, 1); cout << "__ D E S E S P E R A C I O N __" << endl;
    gotoxy(7, 2); cout << "Metros recorrido: " <<  5 - T - (N * 0.3) -  (G * 0.2);
    game();

    return 0;
}

void game() {
    int especimenes;
    int m;

    for (int i = 0; i <= G; i++) {
        T = -1 - rand() % -3;
        especimenes = 1 + rand() % 2;

        if (especimenes == 1) {
            N = N + 1;
            m = 5 - T - (N * 0.3) - (G * 0.2);
            gotoxy(10, 3); cout << "Gano por recoger un especimen bueno!";
            break;

        } else if (m == 20) {
            N = 0;
            m = 5 - T - (N * 0.3) - (G * 0.2);
            gotoxy(10, 3); cout << "Gano por llegar a los 20 metros con suficiente oxigeno!";
        }

        else if (especimenes != 1) {
            N = N + 1;
            m = 5 - T - (N * 0.3) - (G * 0.2);
            gotoxy(7, 3); cout << "Perdio por recoger un especimen malo!";
            break;
        }
        G--;
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
