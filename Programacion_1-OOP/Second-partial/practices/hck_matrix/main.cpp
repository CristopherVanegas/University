#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int r = 5;
int c = 5;
int matrix1[5][5];
int matrix2[5][5];
int matrixR[5][5];

void gotoxy(int x, int y);
void llenar1();
void llenar2();
void mostrar();
void mostrar2();
void multiplicar();
void mostrar3();

int main()
{
    // This program is about bi-dimentional arrays
    srand(time(NULL));
    llenar1();
    mostrar();

    llenar2();
    mostrar2();

    multiplicar();
    mostrar3();
    Beep(600.31, 300);

    return 0;
}

void multiplicar() {
    for (int i = 0; i < c; i++) {
        // int a = 0;
        for (int j = 0; j < c; j++) {

            matrixR[i][j] = 0;
            for (int k = 0; k < c; k++) {
                matrixR[i][j] = matrixR[i][j] + (matrix1[k][j] * matrix2[i][k]);
            }
        }
    }
}

void llenar1() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix1[i][j] = 1 + rand() %10;
        }
    }
}

void llenar2() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix2[i][j] = 1 + rand() %10;
        }
    }
}

void mostrar() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            gotoxy(i*4, j); cout << matrix1[i][j] << "    ";

            //if (matrix[i][j] > 9)
                //cout << matrix[i][j] << "  ";
        }

        cout << endl;
    }
}

void mostrar2() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            gotoxy(i*4 + 30, j); cout << matrix2[i][j] << "    ";

            //if (matrix[i][j] > 9)
                //cout << matrix[i][j] << "  ";
        }

        cout << endl;
    }
}

void mostrar3() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            gotoxy(i*10 + 60, j); cout << matrixR[i][j] << "     ";
            //if (matrix[i][j] > 9)
                //cout << matrix[i][j] << "  ";
        }

        cout << endl;
    }
}

void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}
