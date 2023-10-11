#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int arr[10], suma = 0;
    float prom = 0;

    //. INICIALIZA EL ARRAY
    for (int i = 0; i < 10; i++) {
        printf("\n .Ingrese un valor en la posicion %i: ", i);
        scanf("%i", &arr[i]);
    }


    //. MOSTRAR EL CONTENIDO
    for (int i = 0; i < 10; i++) {
        printf("\n .El valor de la posicion %i es %i", i, arr[i]);
    }


    //. SUMA LOS VALORES Y LOS MUESTRA
    for (int i = 0; i < 10; i++) {
        suma = suma + arr[i];
    }
    printf("\n .La suma de los valores es de %i", suma);


    //. PROMEDIA Y LOS MUESTRA
    prom = suma/10;
    printf("\n .El promedio de los valores es de %.2f", prom);



    getch();
    return 0;
}
