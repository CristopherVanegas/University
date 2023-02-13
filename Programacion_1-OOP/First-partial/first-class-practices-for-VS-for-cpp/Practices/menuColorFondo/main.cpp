#include <iostream>
#include <windows.h>
#include <conio.h>

#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80

using namespace std;

int i=4;

void SetColor(int ForgC)
{
    WORD wColor;

    //This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //csbi is used for wAttributes word

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
      //To mask out all but the background attribute, and to add the color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0xF0);
      SetConsoleTextAttribute(hStdOut, wColor);
    }
 return;
}

void gotoxy(int x, int y)  // funcion que posiciona el cursos en la         coordenada (x,y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void seleccionarOpcion(char tecla){

gotoxy(4, i); cout<<" ";

if( tecla == ABAJO && i < 7 ){
    gotoxy(8, 9);
    cout<<"                          ";
    i++;
}
if( tecla == ARRIBA && i > 4){
    gotoxy(8, 9);
    cout<<"                          ";
    i--;
}

if( tecla == 13 ){
    gotoxy(8, 9);
    if( i == 4 ) cout<<"Eligio la primera opcion";
    if( i == 5 ) cout<<"Eligio la segunda opcion";
    if( i == 6 ) cout<<"Eligio la tercera opcion";
    if( i == 7 ) cout<<"Eligio la cuarta opcion";
}


   gotoxy(4, i); cout<<">";
}

void menu(char tecla){
seleccionarOpcion(tecla);

gotoxy(5, 4); cout<<" primera";
gotoxy(5, 5); cout<<" segunda";
gotoxy(5, 6); cout<<" tercera";
gotoxy(5, 7); cout<<" cuarta";
}


int main()
{
    char tecla;
    while(true){

    if( kbhit() )
        tecla = getch();
    else
        tecla = ' ';

    menu(tecla);

    Sleep(40);
}


system("pause>null");

return 0;
}
