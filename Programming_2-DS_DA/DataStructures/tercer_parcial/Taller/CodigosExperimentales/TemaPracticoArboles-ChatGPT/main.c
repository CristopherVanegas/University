#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char descripcion[100];
    char codigo[4];
    float precio;
    int cantidad;

    struct nodo* izquierda;
    struct nodo* derecha;
} Nodo;

Nodo* nuevo_nodo(char* descripcion, char* codigo, float precio, int cantidad) {
    /* reserva memoria */
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));

    /* define las variables */;
    strcpy(nodo->descripcion, descripcion);
    strcpy(nodo->codigo, codigo);
    nodo->precio = precio;
    nodo->cantidad = cantidad;

    /* inicializa las hojas como null*/
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

Nodo* insertar_nodo(Nodo* raiz, char* descripcion, char* codigo, float precio, int cantidad) {
    if (raiz == NULL) {
        return nuevo_nodo(descripcion, codigo, precio, cantidad);
    }
    // descripcion del nuevo nodo es menor a raiz, entonces va a la izquierda.
    if (strcmp(descripcion, raiz->descripcion) < 0) {
        raiz->izquierda = insertar_nodo(raiz->izquierda, descripcion, codigo, precio, cantidad);
    }
    // es mayor, va a la derecha.
    else {
        raiz->derecha = insertar_nodo(raiz->derecha, descripcion, codigo, precio, cantidad);
    }
    return raiz;
}

void imprimir_inorden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    imprimir_inorden(nodo->izquierda);
    printf("%s, %s, %.2f, %d\n", nodo->descripcion, nodo->codigo, nodo->precio, nodo->cantidad);
    imprimir_inorden(nodo->derecha);
}

int main() {
    Nodo* raiz = NULL;
    raiz = insertar_nodo(raiz, "Producto 1", "P001", 10.50, 20);
    raiz = insertar_nodo(raiz, "Producto 2", "P002", 15.75, 10);
    raiz = insertar_nodo(raiz, "Producto 3", "P003", 7.25, 5);
    raiz = insertar_nodo(raiz, "Producto 4", "P004", 12.00, 15);
    imprimir_inorden(raiz);
    return 0;
}
