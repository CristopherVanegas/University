// Est. Cristopher Vanegas
// Calcular la media de las estaturas
// Obtener cuantos son mayores a la media
// Obtener cuantos son menores a la media

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float prom(int estaturas[]);
int mayoresDelProm(int estaturas[]);
int menoresDelProm(int estaturas[]);
void mostrarDatos(int arr[]);
float convertirAMetros(int estatura);

int d = 13;
int estaturas[13] = {172, 171, 174, 170, 164, 177, 164, 150, 163, 165, 170, 177, 177};
float average = 0;

int main()
{
    average = prom(estaturas);
    mostrarDatos(estaturas);
    printf("\n");
    printf("\n El promedio de las estaturas es de %.2f metros", average/100);
    printf("\n -|  %i son mayores al promedio!", mayoresDelProm(estaturas));
    printf("\n -|  %i son menores al promedio!", menoresDelProm(estaturas));
    printf("\n");
    return 0;
}

float convertirAMetros(int estatura) {
    return estatura/100;
}

void mostrarDatos(int arr[]) {
    for (int i = 0; i < d; i++) {
        // float altura = estaturas[i]/100;
        printf("\n La primera altura es de %i cm", estaturas[i]);
    }
}

int menoresDelProm(int estaturas[]) {
    int c = 0;
    for (int i = 0; i < d; i++) {
        if (estaturas[i] < average)
            c++;
    }

    return c;
}

int mayoresDelProm(int estaturas[]) {
    int c = 0;
    for (int i = 0; i < d; i++) {
        if (estaturas[i] > average)
            c++;
    }

    return c;
}

float prom(int estaturas[]) {
    int a = 0;
    for (int i = 0; i < d; i++) {
        a = a + estaturas[i];
    }

    return a/d;
}
