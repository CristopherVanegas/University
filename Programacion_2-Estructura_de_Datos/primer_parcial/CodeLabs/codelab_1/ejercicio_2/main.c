// Est. Cristopher Vanegas
// Crear un programa que pida un nombre en una lista de caracteres y de la bienvenida.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bienvenida(char nomb[]);
char nombre[30];

int main()
{
    printf("Cual es su nombre? ");
    scanf("%s", &nombre);

    bienvenida(nombre);
    return 0;
}

void bienvenida(char nomb[]) {
    printf("\n Hola %s Bienvenido(a) al lenguaje C \n", nomb);
    getch();
}
