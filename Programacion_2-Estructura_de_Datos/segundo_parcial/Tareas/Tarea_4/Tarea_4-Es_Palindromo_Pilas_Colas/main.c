#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char frase[100];
char fraseSinEspacios[100];

char pila[100];
char cola[100];

void generaFraseSinEspacios();
void aMinusculas();
void llenarPila();
void llenarCola();
int compruebaSiEsPalindromoV2();

int main()
{
    printf("\n");
    printf("\t\t\t\t\t\t | PALINDROMO |\n");

    printf("Ingrese una frase: ");
    fflush(stdin);
    fgets(frase, 100, stdin);

    generaFraseSinEspacios();
    aMinusculas();

    llenarPila();
    llenarCola();
    int flag = compruebaSiEsPalindromoV2();


    // comprueba flags //
    if (flag == 1) printf("\n\nEl valor de Flag es %d entonces la frase SI es palindroma!", flag);
    else if (flag == 0) printf("\n\nEl valor de Flag es %d entonces la frase NO es palindroma!", flag);

    printf("\n\n");
    printf(" > Frase original      : %s", frase);
    printf(" > Frase sin espacios  : %s", fraseSinEspacios);
    printf(" > Longitud de la frase original contando el fin de linea o \'0\': %d", strlen(frase));
    printf("\n\n");

    return 0;
}

void generaFraseSinEspacios()
{
    // llena la frase sin espacios //
    int j = 0;
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] != ' ')
        {
            fraseSinEspacios[j] = frase[i];
            j++;
        }
    }
}

int compruebaSiEsPalindromoV2()
{
    // comprueba si es palindromo //
    int d = strlen(fraseSinEspacios);   // dimension de la frase sin espacios
    int flag = 1; // 1: true; 0: false;


    /*   Resto d-1 y d-i-2 para no contar los fin de linea o '\0'   */
    for (int i = 0; i < d-1; i++)                                       // recorre el array como cola
    {
        // El condicional verifica si la pila y la cola en las posiciones correspondientes son desiguales.
        // En tan caso de que sean desiguales entonces la bandera sera negativa y detiene el bucle.
        if (cola[i] != pila[d - i - 2])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

void aMinusculas()
{
    for (int i = 0; i < strlen(fraseSinEspacios); i++)
    {
        fraseSinEspacios[i] = tolower(fraseSinEspacios[i]);
    }
}

void llenarPila()
{
    strcpy(pila, fraseSinEspacios);
}

void llenarCola()
{
    strcpy(cola, fraseSinEspacios);
}

