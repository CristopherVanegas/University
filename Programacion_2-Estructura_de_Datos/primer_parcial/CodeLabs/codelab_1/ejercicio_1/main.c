// Est. Cristopher Vanegas

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int fNac, edad;
    const anio = 2023;

    printf("Escriba el anio en que nacio: ");
    scanf("d", &fNac);

    edad = anio - fNac;
    printf("Su edad es de %d", edad);
    getch();
    return 0;
}
