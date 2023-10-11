#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Pais
{
    char nombre[30];
    int pob;
};


struct Pais paises[3];


bool distintaPob(int pob)
{
    bool distinto = true;

    for (int i = 0; i < 3; i++)
    {
        if (pob != paises[i].pob)
            distinto = true;
        else
            return false;
    }

    return distinto;
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        printf("\n Ingrese el nombre del pais %d: ", i + 1);
        scanf("%s", &paises[i].nombre);

        int pob;
        do
        {
            printf(" Ingrese la poblacion para el pais %d en millones: ", i + 1);
            scanf("%d", &pob);
        } while (distintaPob(pob) == false);
        paises[i].pob = pob;
    }


    int inxMayor = 0;

    for (int i = 0; i < 3; i++)
    {
        if (paises[i].pob > paises[inxMayor].pob)
            inxMayor = i;
    }

    printf("\n\n %s es el pais con mayor poblacion, posee %d millones de habitantes. \n\n", paises[inxMayor].nombre, paises[inxMayor].pob);

    return 0;
}









