#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int Datos[2][12];   // sueldos[0] y descuentos[1]

string nombres[12]=
{
    "Pablo",
    "Cristopher",
    "Natt",
    "Emilio",
    "Alondra",
    "Damian",
    "Melva",
    "Francisco",
    "Stephany",
    "Andy",
    "Mabe",
    "Luis"
};

string meses[12]=
{
    "Ene -> ",
    "Feb -> ",
    "Mar -> ",
    "Abr -> ",
    "May -> ",
    "Jun -> ",
    "Jul -> ",
    "Ago -> ",
    "Sep -> ",
    "Oct -> ",
    "Nov -> ",
    "Dic -> "
};

void LlenarDatos()
{
    for (int i = 0; i < 12; i++) {
        Datos[0, i] = 980 + rand() % 2800;
    }


    for (int i = 0; i < 12; i++) {
        Datos[1, i] = 50 + rand() % 100;
    }

    /*
    for(int i=0; i<12; i++)
    {
        nombres[12]=nombres[i];
        for(int j=0; j<12; j++)
        {
            Datos[0][j]=200+rand()%500;
            for (int k=0; k<12; k++)
            {
                Datos[1][k]=rand()%100;
            }
        }
    }
    */
}

void MostrarDatos()
{

    for (int i = 0; i < 12; i++) {
        gotoxy(1, i + 3); cout << meses[i];
    }


    gotoxy(10, 1);
    cout << "Cliente";

    for (int i = 0; i < 12; i++) {
        gotoxy(10, i + 3); cout << nombres[i];
    }

    gotoxy(17, 1);
    cout << "Sueldos";

    for (int i = 0; i < 12; i++) {
        gotoxy(17, i + 3); cout << Datos[0, i];
    }

    gotoxy(24, 1);
    cout << "Decuentos";

    for (int i = 0; i < 12; i++) {
        gotoxy(24, i + 3); cout << Datos[1, i];
    }

    /*
    gotoxy(1,3);`
    cout<<"Cliente";
    gotoxy(1,5);
    cout<<"Sueldo";
    gotoxy(1,7);
    cout<<"Descuento";

    for (int k = 0; k < 12; k++)
    {
        gotoxy(3, k + 4);
        cout<<nombres[12][k];
        gotoxy(7, k + 4);
        cout<< Datos[0][k];
        gotoxy(9, k + 4);
        cout<< Datos[1][k];
    }
    */
}

int main()
{
    srand(time(NULL));
    LlenarDatos();
    MostrarDatos();

    return 0;
}
