// Est, Cristopher Vanegas.

#include <stdio.h>
#include <stdlib.h>

void pedirDatos();

typedef struct
{
    char cedula_identidad[10];
    char nombre_completo[50];
    int edad;
} Persona;


int main()
{
    printf("                                Archivos de Texto!\n");
    pedirDatos();
    return 0;
}

void pedirDatos()
{
    int n;
    Persona p;

    printf(" Cuantas personas desea ingresar?? ");
    fflush(stdin);
    scanf("%d", &n);


    // inicia el bucle
    for (int i = 0; i < n; i++)
    {
        printf(" Ingrese la cedula: ");
        fflush(stdin);
        fgets(&p.cedula_identidad, 10, stdin);


        printf(" Ingrese el nombre completo: ");
        fflush(stdin);
        fgets(&p.nombre_completo, 50, stdin);


        printf(" Ingrese la edad: ");
        fflush(stdin);
        scanf("%d", &p.edad);

        printf("\n %s %s %d\n", p.cedula_identidad, p.nombre_completo, p.edad);


        /* ESCRIBIR DATOS EN .TXT */
        FILE *f;
        f = fopen("arch.txt", "a+t");

        if (f == NULL) printf("\t Problema al abrir el archivo!");
        else
        {
            fprintf(f, "%s\n", p.cedula_identidad);
            // fputs(p.cedula_identidad, f);

            // rewind(f);
            // system("cls");
            // fscanf(f, "%s", &p.cedula_identidad);
            // fgets(p.cedula_identidad, f);
        }

        fclose(f);
    }
}
