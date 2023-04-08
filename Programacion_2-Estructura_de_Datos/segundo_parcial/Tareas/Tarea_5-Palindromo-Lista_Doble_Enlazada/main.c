//  Est. Cristopher Vanegas  //
//   [] Deber - Palindromo   //
//   Lista Doble Enlazada    //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

struct Nodo
{
    char letra;
    struct Nodo *sig, *ant;
};

struct Nodo *inicio = NULL, *fin = NULL;
struct Nodo *inicio_sin_esp = NULL, *fin_sin_esp = NULL;

char frase[] = " ";
char sinEsp[] = " ";


struct Nodo *crearNodo(char c)
{
    struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;
    nuevoNodo->letra = c;

    return nuevoNodo;
};

void mostrar()
{
    // system("cls");
    struct Nodo *actual = inicio;
    while (actual->sig != NULL)
    {
        printf("%c", actual->letra);
        actual = actual->sig;
    }
    printf("\n");
}

void preguntarPorPalabra()
{
    char c;
    system("cls");
    printf("\t[console] Escriba la frase: ");
    fflush(stdin);
    gets(frase);
    for (int i = 0; i <= strlen(frase); i++)
    {
        if (frase[i] != ' ' && frase[i] != '\0')
        {
            struct Nodo *nuevoNodo = crearNodo(tolower(frase[i]));
            nuevoNodo->ant = NULL;
            nuevoNodo->sig = NULL;

            if (inicio == NULL) inicio = nuevoNodo;

            else
            {
                struct Nodo *actual = inicio;
                while (actual->sig != NULL)
                {
                    actual = actual->sig;
                }

                actual->sig = nuevoNodo;
                nuevoNodo->ant = actual;
                nuevoNodo->sig = NULL;
                fin = nuevoNodo;
            }
        }
    }

    printf("\n[debugger] Primer caracter: %c", inicio->letra);
    printf("\n[debugger] Ultimo caracter: %c\n", fin->letra);
    getch();

    // mostrar();
}

int esPalindromo()
{
    struct Nodo *cola = inicio, *pila = fin;
    int flag = 1; // 1 para true y 0 para false!

    printf("\t[] ES PALINDROMO?\n");

    if (cola->sig == NULL && pila->ant == NULL)
    {
        printf("\t[console] Existe solo un nodo! \n\t[console] Por lo tanto si es palindromo!");
    }
    else
    {

        while (cola->sig != NULL && pila->ant != NULL)
        {
            if (cola->letra != pila->letra) return flag = 0;
            else
            {
                cola = cola->sig;
                pila = pila->ant;
            }
        }
    }

    return flag;
}


int main()
{
    preguntarPorPalabra();

    if (esPalindromo() == 1)
    {
        printf("\n\n\t[console] SI es palindromo la frase!\n");
    }
    else
    {
        printf("\n\t[console] NO es palindromo la frase!\n");
    }

    printf("\t[console] Frase original: %s\n", frase);
    printf("\t[console] Frase sin espacios y en minusculas: ");
    mostrar();

    return 0;
}
