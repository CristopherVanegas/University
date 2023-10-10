#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main () {
    // printf("Hola mundo");
    int horasTrabajadas;
    float costoHora;
    float sueldo;
    printf("Ingrese las horas trabajadas por el empleado:");
    scanf("%d", &horasTrabajadas);

    printf("Ingrese el pago por hora:");
    scanf("%f", &costoHora);

    sueldo=horasTrabajadas*costoHora;
    printf("El sueldo total del operario es ");
    printf("%f",sueldo);
    // getchar();

    getch();

    return 0;
}
