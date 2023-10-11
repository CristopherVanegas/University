//* Est. Cristopher Vanegas *//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void escribir();
void leer(int opt);
void continuar();
void specificData();

typedef struct
{
    char cod[10];
    char descript[100];
    int price;

} Product;

int main()
{
    menu();
    return 0;
}

void continuar()
{
    printf("\nPress any key to continue!");
    getch();
}

void menu()
{
    int opt;

    do
    {
        do
        {
            system("cls");
            printf("                    WELCOME USER\n\n");
            printf(" [1] Read all data\n");
            printf(" [2] Add more data\n");
            printf(" [3] Show specific data\n");
            printf(" [4] Exit\n");

            printf("\n Please select one option: ");

            // get the selected option
            fflush(stdin);
            scanf("%i", &opt);
            fflush(stdin);

        }
        while ( opt > 3 && opt < 0);

        // exit the program if 4 was selected
        if (opt == 4)
            break;

        // enters the program
        else
        {
            switch(opt)
            {
            case 1:
            {
                leer(0);
            }
            break;
            case 2:
            {
                escribir();
            }
            break;
            case 3:
            {
                specificData();
            }
            break;
            }
        }

    }
    while( opt != 4 );
}


void escribir()
{
    Product p;
    FILE *f;
    f = fopen("archivo.dat", "ab");

    if (f == NULL)
        printf("Error al abrir archivo!");

    else
    {
        int opt;
        do
        {
            system("cls");
            printf ("\nquiere ingresar otro registro? (1> si / 2> no) ");
            fflush(stdin);
            scanf("%i", &opt);
        }
        while (opt != 1 && opt != 2);


        system("cls");
        printf("\nIngrese un valor para el codigo de producto: ");
        fflush(stdin);
        // scanf("%s", &p.cod);
        gets(&p.cod);
        printf("\nIngrese un valor para la descripcion de producto: ");
        fflush(stdin);
        // fgets(&p.descript, 100, stdin);  // Adds a "\n" caracter
        gets(&p.descript);
        // scanf("%s", &p.descript);
        printf("\nIngrese un valor para el precio de producto: ");
        fflush(stdin);
        scanf("%i", &p.price);

        fwrite(&p, sizeof(Product), 1, f);

        fclose(f);
    }
    continuar();
}

void leer(int opt)
{
    switch (opt)
    {
    case 0:
    {
        system("cls");
        Product p;
        FILE *f;
        f = fopen("archivo.dat", "rb");

        if (f == NULL)
            printf("El archivo no existe o no tiene permisos para abrirlo!");

        else
        {
            fread(&p, sizeof(Product), 1, f);
            do
            {
                printf("codigo %s / descripcion %s / precio %d\n", p.cod, p.descript, p.price);
                fread(&p, sizeof(Product), 1, f);
            }
            while (!feof(f));

            fclose(f);
        }
    }
    break;

    case 1:
    {
        system("cls");
        Product p;
        FILE *f;
        f = fopen("archivo.dat", "rb");

        if (f == NULL)
            printf("El archivo no existe o no tiene permisos para abrirlo!");

        else
        {
            char cod[10];
            printf("\nQue codigo de producto busca?? ");
            fflush(stdin);
            gets(&cod);
            // scanf("%s", &cod);

            fread(&p, sizeof(Product), 1, f);
            do
            {
                // Compara dos cadenas
                // (codigo que se busca y el codigo de los productos que se agregaron).
                // Si es igual entonces muestra el producto en pantalla.
                if (strcmp(cod, p.cod) == 0) printf("codigo %s / descripcion %s / precio %d\n", p.cod, p.descript, p.price);
                fread(&p, sizeof(Product), 1, f);
            }
            while (!feof(f));

            fclose(f);
        }
    }
    break;

    case 2:
    {
        system("cls");
        Product p;
        FILE *f;
        f = fopen("archivo.dat", "rb");

        if (f == NULL)
            printf("El archivo no existe o no tiene permisos para abrirlo!");

        else
        {
            printf("\nQue descripcion de producto busca?? ");
            char desc[100];
            fflush(stdin);
            gets(&desc);

            fread(&p, sizeof(Product), 1, f);
            do
            {
                if (strcmp(desc, p.descript) == 0) printf("codigo %s / descripcion %s / precio %d\n", p.cod, p.descript, p.price);
                fread(&p, sizeof(Product), 1, f);
            }
            while (!feof(f));

            fclose(f);
        }
    }
    break;

    case 3:
    {
        system("cls");
        Product p;
        FILE *f;
        f = fopen("archivo.dat", "rb");

        if (f == NULL)
            printf("El archivo no existe o no tiene permisos para abrirlo!");

        else
        {
            printf("\nQue precio de producto busca?? ");
            int price;
            fflush(stdin);
            scanf("%i", &price);

            fread(&p, sizeof(Product), 1, f);
            do
            {
                if (price == p.price) printf("codigo %s / descripcion %s / precio %d\n", p.cod, p.descript, p.price);
                fread(&p, sizeof(Product), 1, f);
            }
            while (!feof(f));

            fclose(f);
        }
    }
    break;
    }
    continuar();
}


void specificData()
{
    int opt;

    do
    {
        system("cls");
        printf("\n Que propiedad de producto buscas?? ");
        printf("\n [1] Codigo ");
        printf("\n [2] Descripcion ");
        printf("\n [3] Precio ");
        printf("\n\n [4] Volver al menu principal");
        printf("\n Selection >>> ");

        fflush(stdin);
        scanf("%i", &opt);
    }
    while (opt < 1 && opt > 4);

    if (opt == 4)
        exit(1);

    switch (opt)
    {
    case 1:
    {
        // codigo
        leer(1);

    }
    break;

    case 2:
    {
        // descripcion
        leer(2);
    }
    break;

    case 3:
    {
        // precio
        leer(3);
    }
    break;
    }
}

