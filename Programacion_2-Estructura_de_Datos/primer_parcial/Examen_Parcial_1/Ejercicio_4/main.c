// Est. Cristopher Vanegas //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


int matrix[6][6];

struct Resultados
{
    int total_alumnos_periodo[6];
    int total_alumnos_facultad[6];
    char facultad_mas_estudiantes[50];
    char facultad_menos_estudiantes[50];

};

struct Resultados res2022;

void continuar();
void facultadConMenosEstudiantes();
void facultadConMasEstudiantes();
void sumarEstudiantesPorFacultad();
void sumarEstudiantesPorPeriodo();
void llenarDatos();
void inicializarMatriz();
void menu();

int main()
{
    srand(time(NULL));
    inicializarMatriz();

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
            printf("MENU DE LA APLICACION\n");
            printf("1) U. Ecotec  -  Ingreso estudiantes\n");
            printf("2) U. Ecotec  -  Presentar Resultados desde archivo\n");
            printf("3) Salir\n");
            printf("Elige una opcion del menu: ");
            fflush(stdin);
            scanf("%d", &opt);
            printf("\n");
        }
        while(opt != 1 && opt != 2 && opt != 3);


        switch(opt)
        {
        // obtiene adatos //
        case 1:
        {
            llenarDatos();

            printf("\nInsertar datos, Ok!\n");

            sumarEstudiantesPorPeriodo();
            sumarEstudiantesPorFacultad();
            facultadConMasEstudiantes();
            facultadConMenosEstudiantes();

            escribirEnBin();
        }
        break;

        // lee los datos //
        case 2:
        {
            system("cls");
            leerEnBin();
        }
        break;

        // Exit //
        case 3:
        {
            system("cls");
            printf("End of program!");
            exit(1);
        }
        break;
        }

        continuar();
    }
    while (opt != 3);
}


void inicializarMatriz()
{
    for (int i = 0; i < 6; i++)     // fila
    {
        for (int j = 0; j < 6; j++)     // columna
        {
            matrix[i][j] = 0;
        }
        res2022.total_alumnos_facultad[i] = 0;
        res2022.total_alumnos_periodo[i] = 0;
    }
}


void llenarDatos()
{
    for (int i = 0; i < 6; i++)     // fila
    {
        for (int j = 0; j < 6; j++)     // columna
        {
            // printf("\nIngrese numero de estudiantes: ");
            // fflush(stdin);
            // scanf("%d", &matrix[i][j]);
            matrix[i][j] = 1 + rand() % 50;
        }
    }
}


void sumarEstudiantesPorPeriodo()
{
    for (int j = 0; j < 6; j++)     // alumnos_por_periodo / periodo (columna)
    {
        for (int i = 0; i < 6; i++)     // facultad (fila)
        {
            res2022.total_alumnos_periodo[j] = res2022.total_alumnos_periodo[j] + matrix[i][j];
        }
    }
}


void sumarEstudiantesPorFacultad()
{
    for (int i = 0; i < 6; i++)     // alumnos_por_periodo / facultad (fila)
    {
        for (int j = 0; j < 6; j++)     // periodo (columna)
        {
            res2022.total_alumnos_facultad[i] = res2022.total_alumnos_facultad[i] + matrix[i][j];
        }
    }
}


void facultadConMasEstudiantes()
{
    int max = 0;

    for (int i = 1; i < 6; i++)
    {
        if (res2022.total_alumnos_facultad[i] > res2022.total_alumnos_facultad[max]) max = i;
    }

    switch (max)
    {
    case 0:
        strcpy(res2022.facultad_mas_estudiantes, "CIENCIAS DE LA VIDA Y DESARROLLO HUMANO");
        break;
    case 1:
        strcpy(res2022.facultad_mas_estudiantes, "CIENCIAS ECONOMICAS Y EMPRESARIALES");
        break;
    case 2:
        strcpy(res2022.facultad_mas_estudiantes, "DERECHO Y GOBERNABILIDAD");
        break;
    case 3:
        strcpy(res2022.facultad_mas_estudiantes, "NGENIERIAS");
        break;
    case 4:
        strcpy(res2022.facultad_mas_estudiantes, "MARKETING Y COMUNICACION");
        break;
    case 5:
        strcpy(res2022.facultad_mas_estudiantes, "ESTUDIOS GLOBALES Y HOSPITALIDAD");
        break;
    }
}


void facultadConMenosEstudiantes()
{
    int min = 0;

    for (int i = 1; i < 6; i++)
    {
        if (res2022.total_alumnos_facultad[i] < res2022.total_alumnos_facultad[min]) min = i;
    }

    switch (min)
    {
    case 0:
        strcpy(res2022.facultad_menos_estudiantes, "CIENCIAS DE LA VIDA Y DESARROLLO HUMANO");
        break;
    case 1:
        strcpy(res2022.facultad_menos_estudiantes, "CIENCIAS ECONOMICAS Y EMPRESARIALES");
        break;
    case 2:
        strcpy(res2022.facultad_menos_estudiantes, "DERECHO Y GOBERNABILIDAD");
        break;
    case 3:
        strcpy(res2022.facultad_menos_estudiantes, "NGENIERIAS");
        break;
    case 4:
        strcpy(res2022.facultad_menos_estudiantes, "MARKETING Y COMUNICACION");
        break;
    case 5:
        strcpy(res2022.facultad_menos_estudiantes, "ESTUDIOS GLOBALES Y HOSPITALIDAD");
        break;
    }
}


void escribirEnBin()
{
    FILE *f;
    f = fopen("archivo.dat", "wb");

    if (f == NULL) printf("Error al abrir el archivo!");
    else
    {
        fwrite(&res2022, sizeof(struct Resultados), 1, f);
    }

    fclose(f);
}

void leerEnBin()
{
    FILE *f;
    f = fopen("archivo.dat", "rb");

    if (f == NULL) printf("Error al abrir el archivo!");
    else
    {
        printf("\nDatos: ");

        struct Resultados r;
        fread(&r, sizeof(struct Resultados), 1, f);

        printf("\nTotal por Periodo");
        for (int i = 0; i < 6; i++)
        {
            printf("\nPeriodo %i: %d", i + 1, r.total_alumnos_periodo[i]);
        }
        printf("\n");

        printf("\nTotal por Facultad");
        for (int i = 0; i < 6; i++)
        {
            printf("\nPeriodo %i: %d", i + 1, r.total_alumnos_facultad[i]);
        }
        printf("\n");

        printf("\nMayor Facultad: %s", r.facultad_mas_estudiantes);
        printf("\nMenor Facultad: %s", r.facultad_menos_estudiantes);
        printf("\n");
    }

    fclose(f);
}


void continuar()
{
    printf("\n\nPresione una tecla para continuar...");
    getch();
}
