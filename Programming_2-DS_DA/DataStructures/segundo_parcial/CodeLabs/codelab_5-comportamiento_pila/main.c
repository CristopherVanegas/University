
//     Este codigo es para simular el comportamiento de pila     //

#include <stdio.h>   // printf
#include <stdlib.h>  // malloc y free
#include <stdbool.h> // Booleanos
#include <conio.h>  // getch()

// Un nodo tiene un dato, el cual es el n�mero. Y otro nodo al que apunta
struct nodo
{
    int numero;
    struct nodo *siguiente;
};

// Prototipos de funciones
void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimir(void);
int tamanio(void); // El tama�o de la pila
bool vacia(void);  // Indica si la pila est� vac�a
int ultimo(void);  // El �ltimo elemento. Devuelve 0 si no hay elementos
void continuar();

// Todo comienza con el nodo superior
struct nodo *superior = NULL;

int main()
{
    int eleccion;
    int numero;
    while (eleccion != -1)
    {
        system("cls");
        printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir "
               "pila\n4.- Imprimir tama�o\n5.- Comprobar si est� vac�a\n6.- "
               "Mostrar �ltimo elemento\n7.- Salir\n\n\tElige: ");
        scanf("%d", &eleccion);
        switch (eleccion)
        {
        case 1:
            printf("\nIngresa el n�mero que agregaremos: ");
            scanf("%d", &numero);
            agregar(numero);
            break;
        case 2:
            eliminarUltimo();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nLa pila mide %d\n", tamanio());
            break;
        case 5:
            if (vacia())
            {
                printf("\nLa pila est� vac�a\n");
            }
            else
            {
                printf("\nLa pila NO est� vac�a\n");
            }
            break;
        case 6:
            printf("\nEl �ltimo elemento es: %d\n", ultimo());
            break;
        case 7:
            exit(1);
            break;
        }
        continuar();
    }
}

void continuar()
{
    printf("\n\nPresione cualquier tecla para continuar...");
    getch();
}

int tamanio(void)
{
    int contador = 0;
    if (superior == NULL)
        return contador;
    struct nodo *temporal = superior;
    while (temporal != NULL)
    {
        contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}

bool vacia(void)
{
    return superior == NULL;
}

int ultimo()
{
    if (superior == NULL)
        return NULL;
    return superior->numero;
}

// Operaci�n push
void agregar(int numero)
{
    printf("Agregando %d\n", numero);
    // El que se agregar�; reservamos memoria
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
    // Le ponemos el dato
    nuevoNodo->numero = numero;
    // Y ahora el nuevo nodo es el superior, y su siguiente
    // es el que antes era superior
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}

void imprimir(void)
{
    if (superior == NULL) printf("\n\nLa pila esta vacia!");
    else
    {
        printf("\n\nImprimiendo...\n");
        struct nodo *temporal = superior;
        while (temporal != NULL)
        {
            printf("%d\n", temporal->numero);
            temporal = temporal->siguiente;
        }
    }
}

// Operaci�n pop, eliminar el de hasta arriba
void eliminarUltimo(void)
{
    printf("Eliminando el �ltimo\n");
    if (superior != NULL)
    {
        // Para liberar la memoria m�s tarde debemos
        // tener la referencia al que vamos a eliminar
        struct nodo *temporal = superior;
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->siguiente;

        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
    }
}
