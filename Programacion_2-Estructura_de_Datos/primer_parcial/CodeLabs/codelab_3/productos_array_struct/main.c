#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Product
{
    int codigo; // = 1000 + rand() % (9999 - 1000);
    char descripcion[30];
    int precio;
};

int main()
{
    srand(time(NULL));
    struct Product product1, product2, lista_productos[2] = {product1, product2};

    for (int i = 0; i < 2; i++)
    {
        printf("\n Ingrese un precio para el producto %d $: ", i + 1);
        scanf("%d", &lista_productos[i].precio);

        // lista_productos[i].codigo = 1000 + rand() % (9999 - 1000);

        printf(" Ingrese un codigo para el producto %d: ", i + 1);
        scanf("%d", &lista_productos[i].codigo);

        printf(" Ingrese una descripcion para el producto %d: ", i + 1);
        scanf("%s", &lista_productos[i].descripcion);
    }


    int inxMayor = 0;

    for (int i = 0; i < 2; i++)
    {
        if (lista_productos[i].precio > lista_productos[inxMayor].precio)
            inxMayor = i;
    }

    printf("\n\nEl producto %s con codigo %d es mayor. \n\n", lista_productos[inxMayor].descripcion, lista_productos[inxMayor].codigo);

    return 0;
}







