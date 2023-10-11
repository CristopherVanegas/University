//   Est. Cristopher Vanegas                              //
//   [] Ejercicio 4 - Sistema de Calificaciones ECOTEC    //
//   Arboles Binarios                                     //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Nodo
{
    char cedula_identidad[10];
    char nombre_completo[100];
    int nota_primer_parcial;
    int nota_segundo_parcial;
    int nota_tercer_parcial;

    struct Nodo *izq;
    struct Nodo *der;
};

void continuar()
{
    printf("\n > Press any key to continue...");
    getch();
}


struct Nodo *nuevoNodo(char cedula_identidad[10], char nombre_completo[100], int primer_parcial, int segundo_parcial, int tercer_parcial)
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);

    // Asignar el datos e iniciar hojas
    strcpy(nodo->cedula_identidad, cedula_identidad);
    strcpy(nodo->nombre_completo, nombre_completo);

    nodo->nota_primer_parcial = primer_parcial;
    nodo->nota_segundo_parcial = segundo_parcial;
    nodo->nota_tercer_parcial = tercer_parcial;

    nodo->izq = NULL;
    nodo->der = NULL;

    return nodo;
}

void insertar(struct Nodo **nodo, char cedula_identidad[10], char nombre_completo[100], int primer_parcial, int segundo_parcial, int tercer_parcial)
{
    if (*nodo == NULL)
    {
        *nodo = nuevoNodo(cedula_identidad, nombre_completo, primer_parcial, segundo_parcial, tercer_parcial);
    }
    else if (strcmp((*nodo)->cedula_identidad, cedula_identidad) > 0)
    {
        if ((*nodo)->der == NULL)
        {
            (*nodo)->der = nuevoNodo(cedula_identidad, nombre_completo, primer_parcial, segundo_parcial, tercer_parcial);
        }
        else
        {
            insertar(&((*nodo)->der), cedula_identidad, nombre_completo, primer_parcial, segundo_parcial, tercer_parcial);
        }
    }
    else
    {
        if ((*nodo)->izq == NULL)
        {
            (*nodo)->izq = nuevoNodo(cedula_identidad, nombre_completo, primer_parcial, segundo_parcial, tercer_parcial);
        }
        else
        {
            insertar(&((*nodo)->izq), cedula_identidad, nombre_completo, primer_parcial, segundo_parcial, tercer_parcial);
        }
    }
}

void inorden(struct Nodo **raiz)
{
    if (*raiz != NULL)
    {
        inorden(&((*raiz)->izq)); // pasar la dirección de memoria del puntero de la izquierda
        printf("\n > %s, %s, %d, %d\n", (*raiz)->cedula_identidad, (*raiz)->nombre_completo, (*raiz)->nota_primer_parcial, (*raiz)->nota_segundo_parcial, (*raiz)->nota_tercer_parcial);
        inorden(&((*raiz)->der)); // pasar la dirección de memoria del puntero de la derecha
    }
}

void buscarEspecifico(struct Nodo **raiz, char *cedula)
{
    if (*raiz != NULL)
    {
        buscarEspecifico(&((*raiz)->izq), cedula); // buscar en la rama izquierda
        if (strcmp((*raiz)->cedula_identidad, cedula) == 0) printf(" > %s, %s, %d, %d\n", (*raiz)->cedula_identidad, (*raiz)->nombre_completo, (*raiz)->nota_primer_parcial, (*raiz)->nota_segundo_parcial, (*raiz)->nota_tercer_parcial); // imprimir si se encuentra la cédula
        buscarEspecifico(&((*raiz)->der), cedula); // buscar en la rama derecha
    }
}

void menu()
{
    struct Nodo **raiz = NULL;

    char cedula_identidad[10];
    char nombre_completo[100];
    int nota_primer_parcial;
    int nota_segundo_parcial;
    int nota_tercer_parcial;

    for (;;)
    {
        int o;

        do
        {
            system("cls");
            // printf("%s\n", raiz->cedula_identidad);
            printf("\nMENU SISTEMA DE CALIFICACIONES ECOTEC:");
            printf("\n\t1) Ingreso de notas por estudiante");
            printf("\n\t2) Consulta Especifica de estudiante");
            printf("\n\t3) Consulta general de estudiantes");
            printf("\n\t4) Salir");
            printf("\nElige una opcion del menu: ");
            scanf("%d", &o);
        }
        while (o < 0 && o > 4);

        switch (o)
        {
        case 1:
        {
            // Asignar el datos e iniciar hojas
            printf("Ingresar cedula de identidad: ");
            fflush(stdin);
            fgets(cedula_identidad, 10, stdin);

            printf("Ingresar nombre completo: ");
            fflush(stdin);
            fgets(nombre_completo, 100, stdin);

            printf("Ingresar nota de primer parcial: ");
            fflush(stdin);
            scanf("%d", &nota_primer_parcial);
            printf("Ingresar nota de segundo parcial: ");
            fflush(stdin);
            scanf("%d", &nota_segundo_parcial);
            printf("Ingresar nota de tercer parcial: ");
            fflush(stdin);
            scanf("%d", &nota_tercer_parcial);

            insertar(&raiz, cedula_identidad, nombre_completo, nota_primer_parcial, nota_segundo_parcial, nota_tercer_parcial);

        } break;

        case 2:
        {
            printf("\n Ingrese la cedula del estudiante cuyos datos desea consultar: ");
            char cedula[10];
            fflush(stdin);
            fgets(cedula, 10, stdin);

            buscarEspecifico(&raiz, cedula);
        } break;

        case 3:
        {
            inorden(&raiz);
        } break;

        case 4:
        {
            exit(1);
        } break;
        }

        continuar();
    }
}

int main()
{
    menu();
    return 0;
}
