#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next; // Falto un ;
};

struct Node *head = NULL; // puntero al primer elemento de la lista // el * va antes del identificador, no el nombre del struct o tipo de dato.

void insert(int value) {
    struct Node newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = head;
    head = &newNode;    // guardo la direccion del siguiente nodo
}

void printList() {
    struct Node *current = head;
    while (current != NULL)
        printf("%d ", current->value);
        current = current->next;

    printf("\n");
}

int main() {
    insert(1);  // los valores a recibir son enteros, no strings.
    insert(1);  // los valores a recibir son enteros, no strings.
    printList();
    return 0;
}
