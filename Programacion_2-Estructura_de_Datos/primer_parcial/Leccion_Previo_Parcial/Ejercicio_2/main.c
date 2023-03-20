// Est, Cristopher Vanegas.

#include <stdio.h>
#include <stdlib.h>

void pedirDatos();

typedef struct
{
    char cedula_identidad[10];
    char nombre_completo[50];
    int edad;
} persona;


int main()
{
    printf("                                Archivos de Texto!\n");
    pedirDatos();
    return 0;
}

void pedirDatos()
{
    int n;
    printf(" Cuantas personas desea ingresar?? ");
    fflush(stdin);
    scanf("%d", &n);

    FILE *f;
    f = fopen("archivo.txt", "rb+");
    if (f == NULL)
        printf("Error al abrir!");
    else
    {
        persona p;

        for (int i = 0; i < n; i++)
        {
            system("cls");
            printf(">>> Datos persona %i\n", i + 1);
            printf("  > Escriba la cedula de identidad: ");
            fflush(stdin);
            // gets(&p.cedula_identidad);
            fgets(p.cedula_identidad, 10, stdin);
            // fputs(p.cedula_identidad, f);


            printf("  > Escriba el nombre completo: ");
            fflush(stdin);
            // gets(&p.nombre_completo);
            fgets(p.nombre_completo, 50, stdin);
            // fputs(p.nombre_completo, f);


            printf("  > Escriba la edad: ");
            fflush(stdin);
            scanf("%d", &p.edad);
            // fputs(p.edad, f);

            // fwrite(p.cedula_identidad, sizeof(p.cedula_identidad), 1, f);
            // fwrite(p.nombre_completo, sizeof(p.nombre_completo), 1, f);
            // fwrite(p.edad, sizeof(p.edad), 1, f);

            // fprintf(f, "%s %s %d \n", p.cedula_identidad, p.nombre_completo, p.edad);
            // fscanf (f, "%s %s %d ", &p.cedula_identidad, &p.nombre_completo, &p.edad);

            //fputs(p.cedula_identidad, f);
            //fputs(p.nombre_completo, f);
            //fputs(p.edad, f);


            fwrite(&p, sizeof(persona), 1, f);
        }


        // mostrar

        persona l;
        rewind(f);
        for (int i = 0; i < n; i++)
        {
            fread(&l, sizeof(persona), 1, f);
            while (!feof(f)) {
                if (l.cedula_identidad != "")
                    printf("%s %s %d\n", l.cedula_identidad, l.nombre_completo, l.edad);
            }
        }
    }

    fclose(f);
}
