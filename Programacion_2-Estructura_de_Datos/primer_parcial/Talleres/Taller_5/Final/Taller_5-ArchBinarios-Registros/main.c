// Est. Cristopher Vanegas.

#include <stdio.h>
#include <stdlib.h>

void menu();
void addRegistros();
void leerRegistro();
void specificData();

int main()
{
    menu();

    return 0;
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
                leerRegistro();
            }
            break;
            case 2:
            {
                addRegistros();
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

struct Producto
{
    char codigo_inventario[10];
    char descripcion[50];
    float precio;
};

struct Producto P1;

void addRegistros()
{
    system("cls");
    printf("                    CREAR ARCHIVOS BINARIOS Y REGISTROS\n");

    char a;

    do
    {

        // do while para comprobar que recibio lo esperado (y / n).
        do
        {
            printf("\n Do you want to add a register? (y / n) ");
            fflush(stdin);
            scanf("%s", &a);
        }
        while (a != 'n' && a != 'y');

        // si se presiona 'n' sale del bucle.
        if (a == 'n')
            break;

        printf("\n Please enter the product code: ");
        fflush(stdin);
        fgets(P1.codigo_inventario, 10, stdin);

        printf(" Please enter the product description: ");
        fflush(stdin);
        fgets(P1.descripcion, 50, stdin);

        printf(" Please enter the product price: ");
        fflush(stdin);
        scanf("%f", &P1.precio);


        /*          ESCRIBE EN EL ARCHIVO BINARIO       */

        printf("\n\n Escribiendo los datos en el archivo binario...");

        FILE *f;
        f = fopen("archivo.dat", "ab");
        fwrite(&P1, sizeof(P1), 1, f);
        fclose(f);


        /*          LEE EL REGISTRO         */
        printf("\n\n do you want to see the data storage?? (y / n) ");
        char answer;
        fflush(stdin);
        fgets(answer, 1, stdin);

        leerRegistro();
    }
    while (a == 'y');
}

void leerRegistro()
{
    system("cls");
    printf("                    LEER ARCHIVOS BINARIOS Y REGISTROS\n");

    FILE *f;

    if (f = fopen("archivo.dat", "rb") == NULL)
        printf("\n    Error, this file cannot be read or it does not exist!");

    else
    {
        // while (!feof(f))
        // {
            fread(&P1, sizeof(P1), 1, f);
            printf("%s : %s : %f\n", &P1.codigo_inventario, &P1.descripcion, &P1.precio);
            printf("\n Successfully read!");
        // }
    }

    char opt;
    printf("\n\n Press any key to continue ");
    fflush(stdin);
    scanf("%c", opt);
}

void specificData()
{
    /*
        code...
    */
}
