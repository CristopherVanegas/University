#include <iostream>
#include <time.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int arr[10];
int d = 10, range = 30;

void llenar();
int pedirRango();
int cuantosHay(int n, int arr[]);
void mostrarData();
void program();
void gotoxy(int x,int y);
void graphH();

int main()
{
    srand(time(NULL));
    program();

    return 0;
}

void program()
{
    range = pedirRango();
    llenar();
    mostrarData();
    graphH();

}

bool noEsIgual(int n, int pos, int arr[]) {
    int c = 0;
    for (int i = pos; i >= 0; i--) {
        if (n == arr[i]) c++;
        if (c == 2) return false;
    }
    return true;
}

//void graph()
//{
//    int i = 0;  //    Eje X - aumenta dinamicamente
//    for (int j = range + 10; j >= 10; j--) {
//        if (arr[i_arr] != ) {
//
//        }
//    }
//}

void graphH()
{
    // itera los elementos y con eso el dominio
    int posYGotoxy = 0;
    int c_blanks = 0;
    for (int y = 0; y < d; y++)
    {
        posYGotoxy = y - c_blanks;
        if (noEsIgual(arr[y], y, arr)) {
            int q = cuantosHay(arr[y], arr);

            gotoxy(0, 5 + posYGotoxy);
            cout << arr[y] << ": ";

            // itera en x o sea el rango
            for (int x = 0; x < q; x++)
            {
                gotoxy(x + 7, 5 + posYGotoxy);
                cout << "*";
            }

            Sleep(30);
        } else {
            c_blanks = c_blanks + 1;
        }
        cout << endl;
    }
}

void mostrarData()
{
    for (int i = 0; i < d; i++)
    {
        cout << " > " << arr[i];
    }
    cout << endl;
}

int pedirRango()
{
    system("cls");
    cout << "Rango: ";
    cin >> range;

    return range;
}

int cuantosHay(int n, int arr[])
{
    int c = 0;
    for (int i = 0; i < d; i++)
    {
        if (n == arr[i]) c++;
    }
    return c;
}

void llenar()
{
    for (int i = 0; i < d; i++) arr[i] = 1 + rand() % range;
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
