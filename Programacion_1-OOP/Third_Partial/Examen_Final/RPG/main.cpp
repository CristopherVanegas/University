// Est. Cristopher Vanegas

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <windows.h>
#include <time.h>

using namespace std;

struct Personaje
{
    string tipo = "";
    int fuerza;
    int vida;
    int defensa;
    int nivel = 1;

    int posX;
    int posY;
};

string Tipos[3] = {"C", "M", "A"};

Personaje personajes_pc[3];
Personaje personajes_player[3];


// tablero
string tablero[20][20];


void gotoxy(int x,int y);
void inicializarTablero();
void show();
void generar_personaje(int opt);
void fusionar();
void atacar();

int main()
{
    srand(time(NULL));
    inicializarTablero();
    generar_personaje(1);
    show();

    for (;;)
    {
        fusionar();
        atacar();
        show();
    }
    return 0;
}

void atacar()
{
    for (int i = 0; i < 3; i++)
    {
        int random_character = rand() % 3;

        // SHORTCUTS
        int pc_posY = personajes_pc[random_character].posY;
        int pc_posX = personajes_pc[random_character].posX;
        int player_posY = personajes_pc[random_character].posY;
        int player_posX = personajes_pc[random_character].posX;

        // CLEAN UP THE OLD POSITION BEFORE THE FUSION
        tablero[personajes_player[random_character].posX][personajes_player[random_character].posY] = " ";

        // CONDITIONAL TO ATACK
        if ((abs(pc_posY - player_posY) == 3) && (abs(pc_posX - player_posX) == 3))
        {
            personajes_pc[random_character].vida--;
        }
        else
        {
            switch (rand() % 8)
            {
            case 0: // MOVE TO LEFT
            {
                if (pc_posX < player_posX)
                {
                    personajes_player[random_character].posX--;
                }
            }
            break;

            case 1: // MOVE TO RIGHT
            {
                if (pc_posX > player_posX)
                {
                    personajes_player[random_character].posX++;
                }
            }
            break;

            case 2: // MOVE BOTTOM
            {
                if (pc_posY > player_posY)
                {
                    personajes_player[random_character].posY++;
                }
            }
            break;

            case 3: // MOVE TOP
            {
                if (pc_posY < player_posY)
                {
                    personajes_player[random_character].posY--;
                }
            }
            break;

            case 4: // MOVE RIGHT TOP DIAGONAL
            {
                if ((pc_posY < player_posY) && (pc_posX > player_posX))
                {
                    personajes_player[random_character].posY--;
                    personajes_player[random_character].posX++;
                }
            }
            break;

            case 5: // MOVE LEFT TOP DIAGONAL
            {
                if ((pc_posY < player_posY) && (pc_posX < player_posX))
                {
                    personajes_player[random_character].posY--;
                    personajes_player[random_character].posX--;
                }
            }
            break;

            case 6: // MOVE LEFT BOTTOM DIAGONAL
            {
                if ((pc_posY > player_posY) && (pc_posX < player_posX))
                {
                    personajes_player[random_character].posY++;
                    personajes_player[random_character].posX--;
                }
            }
            break;

            case 7: // MOVE RIGHT BOTTOM DIAGONAL
            {
                if ((pc_posY > player_posY) && (pc_posX > player_posX))
                {
                    personajes_player[random_character].posY++;
                    personajes_player[random_character].posX++;
                }
            }
            break;
            }
        }

        // KEEPS THE TYPE OF PLAYER CARACTER IN THE MATRIX
        tablero[personajes_player[random_character].posX][personajes_player[random_character].posY] = personajes_player[random_character].tipo;
        Sleep(250);
    }
}

bool sePuedenFusionar()
{
    string caracter = personajes_player[0].tipo;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((personajes_player[i].tipo == personajes_player[j].tipo) && (i != j))
                return true;
        }
    }


    return false;
}

void fusionar()
{
    while(sePuedenFusionar())
    {
        int gotoxY = 2;
        gotoxy(45, gotoxY);
        cout << "SELECT WHICH CHARACTER DO YOU WANT TO MOVE";
        gotoxY++;

        show();

        for (int i = 0; i < 3; i++)
        {
            gotoxy(45, gotoxY++);
            cout << "[ "<< i + 1 << " ] Character " << " " << personajes_player[i].tipo;
        }
        gotoxY++;
        gotoxy(45, gotoxY++);
        cout << "[] ";
        int selection;
        cin >> selection;
        cin.get();


        gotoxy(45, gotoxY++);
        cout << " [] Please send the coor for X: ";
        int x;
        cin >> x;
        cin.get();

        gotoxy(45, gotoxY++);
        cout << " [] Please send the coor for Y: ";
        int y;
        cin >> y;
        cin.get();

        // CLEAN UP THE OLD POSITION BEFORE THE FUSION
        tablero[personajes_player[selection - 1].posX][personajes_player[selection - 1].posY] = " ";

        // UPDATE THE PLAYER CHARACTER POSITIONS
        personajes_player[selection - 1].posX = x;
        personajes_player[selection - 1].posY = y;

        // KEEPS THE TYPE OF PLAYER CARACTER IN THE MATRIX
        tablero[personajes_player[selection - 1].posX][personajes_player[selection - 1].posY] = personajes_player[selection - 1].tipo;

        for (int i = 0; i < 3; i++)
        {
            if ((selection - 1) == i)
                continue;
            else if ((personajes_player[selection - 1].tipo == personajes_player[i].tipo) && (personajes_player[selection - 1].posY == personajes_player[i].posY) && (personajes_player[selection - 1].posX == personajes_player[i].posX))
            {
                // DELETES THE ACTUAL PLAYER TO FUSIONATE WITH THE SAME COOR
                personajes_player[selection - 1].vida = 0;
                generar_personaje(2);

                // UPDATE THE SAME COOR CHARACTER TO INCREASE THE STATISTICS
                personajes_player[i].defensa = personajes_pc[i].defensa + 5;
                personajes_player[i].fuerza = personajes_pc[i].fuerza + 5;
                personajes_player[i].nivel++;
                personajes_player[i].vida = personajes_pc[i].vida + 5;

                // PRINTS A MESSAGE
                system("cls");
                gotoxy(15, 10);
                cout << "NEW LEVEL " << personajes_player[i].nivel << " FOR CHARACTER " << personajes_player[i].tipo << "!!";
                Sleep(1200);
                //Sleep(1200);
                //system("cls");
            }
        }
        system("cls");
    }
}

void generar_personaje(int opt)
{
    switch (opt)
    {
    // CASE 1 - GENERATES CHARACTER FOR FIRST TIME - BEGINNING OF THE GAME.
    case 1:
    {
        for (int i = 0; i < 3; i++)
        {
            // generates types
            personajes_pc[i].tipo = Tipos[rand() % 3];
            personajes_player[i].tipo = Tipos[rand() % 3];


            // generates vitals
            personajes_pc[i].defensa = 1 + rand() % 10;
            personajes_pc[i].fuerza = 1 + rand() % 10;
            personajes_pc[i].vida = 1 + rand() % 10;

            personajes_player[i].defensa = 1 + rand() % 10;
            personajes_player[i].fuerza = 1 + rand() % 10;
            personajes_player[i].vida = 1 + rand() % 10;


            // generates X and Y positions
            personajes_pc[i].posX = rand() % 20;
            personajes_pc[i].posY = rand() % 10;

            personajes_player[i].posX = rand() % 20;
            personajes_player[i].posY = 10 + rand() % (20 - 11);
        }
    }
    break;

    // CASE 2 - GENERATES CHARACTER FOR SECOND TIME - AFTER DEATH.
    case 2:
    {
        /* code. */
        for (int i = 0; i < 3; i++)
        {
            if (personajes_player[i].vida == 0)
            {
                // generates types
                personajes_player[i].tipo = Tipos[rand() % 3];


                // generates vitals
                personajes_player[i].defensa = 1 + rand() % 10;
                personajes_player[i].fuerza = 1 + rand() % 10;
                personajes_player[i].vida = 1 + rand() % 10;

                // generates X and Y positions
                personajes_player[i].posX = rand() % 20;
                personajes_player[i].posY = 10 + rand() % (20 - 11);
            }
        }
    }
    break;
    }

    for (int i = 0; i < 3; i++)
    {
        tablero[personajes_pc[i].posX][personajes_pc[i].posY] = personajes_pc[i].tipo;
        tablero[personajes_player[i].posX][personajes_player[i].posY] = personajes_player[i].tipo;
    }
}

void inicializarTablero()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            tablero[i][j] = " ";
        }
    }
}

void show()
{
    int x = 0;

    for (int i = 0; i < 21; i++)
    {
        for (int j = 2; j < 22; j++)
        {
            // TO AVOID IT GOES BEYOND THE FRAME
            if (i < 20)
            {
                // SHOW THE CONTENT OF THE TABLE
                gotoxy(i + x + 1, j);
                cout << tablero[i][j - 2];

                // SHOW THE Y VALUES
                gotoxy(42, i + 2);
                cout << i;
            }

            gotoxy(i * 2, j);
            cout << "|";
        }

        x++;
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
