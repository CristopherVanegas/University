//     PROYECTO - ESTRUCTURA DE DATOS     //
//  Integrantes:                          //
//          > Jose Munioz                 //
//          > Kevin Santana               //
//          > Sergio Balarezo             //
//          > Yelena Urinia               //
//          > Cristopher Vanegas          //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILAS 18
#define COLUMNAS 25

int move = 1;

char fondo[FILAS][COLUMNAS];

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

char shape[7][4][4] =
{
    {{' ',219,' ',' '},{' ',219,' ',' '},{' ',219,' ',' '},{' ',219,' ',' '}},
    {{' ',' ',' ',' '},{' ',219,219,' '},{' ',219,219,' '},{' ',' ',' ',' '}},
    {{' ',' ',' ',' '},{' ',219,' ',' '},{219,219,219,' '},{' ',' ',' ',' '}},
    {{' ',' ',219,' '},{' ',219,219,' '},{' ',219,' ',' '},{' ',' ',' ',' '}},
    {{' ',219,' ',' '},{' ',219,219,' '},{' ',' ',219,' '},{' ',' ',' ',' '}},
    {{' ',' ',' ',' '},{' ',219,' ',' '},{' ',219,219,219},{' ',' ',' ',' '}},
    {{' ',' ',' ',' '},{' ',219,219,219},{' ',219,' ',' '},{' ',' ',' ',' '}}
};

void imprimirFicha(int ficha)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j+2, i+2);
            printf("%c", shape[ficha][i][j]);
        }
    }
}

void mostrarFichas()
{
    printf("\n\tMostrando Fichas\n");
    for (int i = 0; i < 7; i++)
    {
        imprimirFicha(i);
        Sleep(221);
    }
}

void tablero()
{
    system("cls");
    char supIzq = 218;
    char supDer = 191;
    char infDer = 217;
    char infIzq = 192;

    /*     Esquinas     */
    gotoxy(0, 0);
    printf("%c", supIzq);

    gotoxy(COLUMNAS, 0);
    printf("%c", supDer);

    gotoxy(0, FILAS);
    printf("%c", infIzq);


    gotoxy(COLUMNAS, FILAS);
    printf("%c", infDer);

    // creo el marco de arriba y abajo
    for (int i = 1; i < COLUMNAS; i++)
    {
        gotoxy(i, 0);
        printf("-");
        gotoxy(i, FILAS);
        printf("-");
        Sleep(21);
    }

    // creo el marco de los lados
    for (int j = 1; j < FILAS; j++)
    {
        gotoxy(0, j);
        printf("|");
        gotoxy(COLUMNAS, j);
        printf("|");
        Sleep(21);
    }
}

void ponerUnaFicha()
{
    /*     ASIGNA LA PIEZA EN EL TABLERO     */
    int pos = round((COLUMNAS/2)-4);
    int fichaAleatoria = rand() % 7;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fondo[1+i][pos+j] = shape[fichaAleatoria][i][j];
        }
    }
}

void mostrarTablero()
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            gotoxy(j, i);
            printf("%c", fondo[i][j]);

            // gotoxy(COLUMNAS-1, FILAS-1);
            // printf("a");
        }
    }
}

void animacion()
{

    // variable que contiene al caracter de cubo
    char c = 219;

    /*
    // animacion de izquierda o derecha
    if (getch() == 'a') {   // izquierda

    }

    if (getch() == 'd') {   // derecha`

    }

    /*
    if (getch() == 's') {

    }
    */

    // animacion de caida

    for (int i = 1; i < FILAS; i++)
    {
        for (int j = 1; j < COLUMNAS; j++)
        {
            if (fondo[i][j] == c && fondo[i+1][j] != c && i+1 < FILAS)
            {
                fondo[i][j] = ' ';
                fondo[i+1][j] = c;
                Sleep(50);
            } else {
                move = 0;
            }

        }
    }
}

int main()
{
    srand(time(NULL));
    // mostrarFichas();
    tablero();

    for (;;)
    {
        if (move == 1) {
            mostrarTablero();
            ponerUnaFicha();
            animacion();
        }

        else {
            move = 1;
        }
    }


    printf("\n\n");
    return 0;
}
