#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void menu();
void continuar();
void suma();
void resta();
void mult();
void di();

int main()
{
    printf("CALCULADORA\n");
    menu();
    return 0;
}


void suma()
{
    system("cls");
    printf("SUMA\n\n");

    int sum = 0, aux = 0;
    char auxs[] = "0";
    do
    {
        system("cls");

        printf("\n > Ingrese un numero para sumar a %d: ", sum);
        scanf("%s", &auxs);
        aux = atoi(auxs);

        sum = sum + aux;
        printf("presione n para salir ");
    }
    while (getch() != 'n');
}

void resta()
{

}

void mult()
{

}

void di()
{

}


void menu()
{
    int opt;

    do
    {
        system("cls");
        printf(" 1 >> SUMA\n");
        printf(" 2 >> RESTA\n");
        printf(" 3 >> MULTIPLICACION\n");
        printf(" 4 >> DIVISION\n");
        printf(" 5 >> Exit\n");
        printf("\n > Elija una opt para continuar con una operacion: ");
    }
    while (opt < 1 && opt > 5);

    scanf("%i", &opt);

    switch (opt)
    {
    case 1:
    {
        suma();
    }
    break;

    case 2:
    {
        resta();
    }
    break;

    case 3:
    {
        mult();
    }
    break;

    case 4:
    {
        di();
    }
    break;

    case 5:
    {
        exit(1);
    }
    break;
    }
}


void continuar()
{
    printf("\n\n > Presione una tecla para continuar...");
    getch();
}
