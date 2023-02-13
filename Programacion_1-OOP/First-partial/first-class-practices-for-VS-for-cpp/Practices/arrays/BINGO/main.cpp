#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
using namespace std;
int d=5;
int B[5]= {0,0,0,0,0};
int I[5]= {0,0,0,0,0};
int N[5]= {0,0,0,0,0};
int G[5]= {0,0,0,0,0};
int O[5]= {0,0,0,0,0};
void LlenarTabla();
void MostrarTabla();
bool esIgual(int arr[], int Nrandom);


void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int main()
{
    srand(time(NULL));
    LlenarTabla();
    MostrarTabla();

    return 0;
}

bool esIgual(int arr[], int Nrandom) {
    for(int i = 0; i < d; i++) {
        if (arr[i] == Nrandom) {
            return true;
        }
    }
    return false;
}

void LlenarTabla()
{
    for (int i=0; i<5; i++)//RECORRE CADA LETRA PARA LLENAR LAS COLUMNAS
    {
        switch(i)
        {
        case 0://COLUMNA B
            for (int j=0; j<d; j++)
            {
                if (j == 1) {
                        B[j]=1+rand()%15;
                } else {
                    int Nrandom;
                    do {
                        Nrandom=1+rand()%15;
                    } while (esIgual(B, Nrandom) == true);

                    B[j]=Nrandom;
                }
            }

        break;
    case 1://COLUMNA I
        break;
    case 2://COLUMNA N
        break;
    case 3://COLUMNA G
        break;
    case 4://COLUMNA O
        break;
    }
}
}
void MostrarTabla()
{
    gotoxy(1,1);
    cout<<"B";
    for (int i=0; i<d; i++)
    {
        gotoxy(1,1+i+1);
        cout<<B[i];
    }

}
