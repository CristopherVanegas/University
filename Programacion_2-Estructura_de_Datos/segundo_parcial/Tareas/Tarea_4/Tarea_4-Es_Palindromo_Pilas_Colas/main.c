#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char frase[100];
char fraseSinEspacios[100];

char pila[100];
char cola[100];

int main()
{
    printf("\n");
    printf("\t\t\t\t\t\t | PALINDROMO |\n");

    printf("Ingrese una frase: ");
    fflush(stdin);
    fgets(frase, 100, stdin);

    // llena la frase sin espacios //
    int j = 0;
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' ') {
                fraseSinEspacios[j] = frase[i];
                j++;
        }
    }

    // comprueba si es palindromo //
    int d = strlen(fraseSinEspacios);   // dimension de la frase sin espacios
    int flag = 1; // 1: true; 0: false;


    /*   Resto d-1 y d-i-2 para no contar los fin de linea o '\0'   */
    for (int i = 0; i < d-1; i++) {                                     // recorre el array como cola
        if (fraseSinEspacios[i] != fraseSinEspacios[d - i - 2]) {       // recorre el array como pila
                flag = 0;
                break;
        }
    }


    // comprueba flags //
    if (flag == 1) printf("\n\nEl valor de Flag es %d entonces la frase SI es palindroma!", flag);
    else if (flag == 0) printf("\n\nEl valor de Flag es %d entonces la frase NO es palindroma!", flag);

    printf("\n\n");
    printf(" > Frase original      : %s", frase);
    printf(" > Frase sin espacios  : %s", fraseSinEspacios);
    printf(" > Longitud de la frase contando el fin de linea o \'0\': %d", d);
    printf("\n\n");

    return 0;
}

