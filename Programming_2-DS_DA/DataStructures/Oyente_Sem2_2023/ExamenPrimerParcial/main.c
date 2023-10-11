#include <stdio.h>
#include <stdlib.h>

struct Resultados
{
    int promedio_alumnos;
    int promedio_materia;
    char estudiante_promedio_mas_alto[50];
    char estudiante_promedio_mas_bajo[50];
};

struct Resultados R;

int main()
{
    int cant[5][10];
    int sum=0;
    int a=1;
    int opcion;
    do
    {
        printf("menu de la aplicacion:\n1. U. Ecotec-ingreso estudiante\n2. U. Eecotec-presentar resultado desde archivo\n3. salir\n ");
        printf("Elige una opcion de menu:");
        scanf("%d",&opcion);

        FILE *archivo;
        system("cls");
        switch(opcion)
        {
        case 1: //ingresa valor
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<10; j++)
                {
                    printf("ingrese numero estudiante %i  y materia %d \n",j+1,i+1);
                    scanf(" %d",&cant[i][j]);
                }
            }


            // promedio estudiantes //
            for (int i = 0; i < 6; i++)     // materias
            {
                for (jnt j = 0; j < 10; j++)     // estudiantes
                {
                    R.promedio_alumnos[j] = res2022.total_alumnos_periodo[j] + matrix[i][j];
                }
            }
            break;

        case 2:
            archivo = fopen("archivo.txt","w");
            for (int i = 0; i < 5; i++)
            {
                printf("Suma por materia %d\n",i+1);
                sum=0;
                for (int j = 0; j < 10; j++)
                {
                    sum = sum  + cant[i][j];

                }
                printf("materia %d: %i\n", i + 1, sum);
            }

            for (int j = 0; j < 10; j++)
            {
                printf("Suma por estudiante %i\n",j+1);
                sum=0;
                for (int i = 0; i < 5; i++)
                {
                    sum = sum +cant[i][j];

                }
                printf("estudiante %d: %i\n", j + 1, sum);
            }

            printf("\n");



            for (int i = 0; i < 5; i++)
            {
                sum = 0;
                for (int j = 0; j < 10; j++)
                {
                    sum = sum +cant[i][j];
                }
                fprintf(archivo, "Suma por materia %d: %d\n", i + 1, sum);
            }


            for (int j = 0; j < 10; j++)
            {
                sum = 0;
                for (int i = 0; i < 5; i++)
                {
                    sum = sum +cant[i][j];
                }
                fprintf(archivo, "Suma por materia %d: %d\n", j + 1, sum);
            }


            printf("su archivo de respuesta se creo ");
            printf("\n");

            fclose(archivo);

            break;

        case 3:
            printf("salir\n");

            if (remove("archivo.txt") == 0)
            {
                printf("El archivo " "%s" " se ha eliminado correctamente.\n", "archivo.txt");
            }
            else
            {
                printf("Error al eliminar el archivo");
            }
            a=3;
            break;

        }
    }
    while(a==1);

    return 0;
}
