/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Nodo {
    struct Nodo *der;
    struct Nodo *izq;
    int val;
};

struct Nodo *raiz = NULL;


struct Nodo * crearNodo(int val) {
    struct Nodo *nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->val = val;
    return nuevoNodo;
}


void agregarNodo() {
    printf("AGREGAR NODO\n");
    
    printf("\n Ingrese un valor para el nodo: ");
    int n;
    fflush(stdin);
    scanf("%d", &n);
    
    struct Nodo *nuevoNodo = crearNodo(n);
	    
    if (raiz == NULL) {
        raiz = nuevoNodo;
    }
    else {
        struct Nodo *actual = raiz;
        struct Nodo *objetivo = raiz;
        
        while (actual != NULL) {
            if (nuevoNodo->val > actual->val) {
                objetivo = actual->der;
            }
            else if (nuevoNodo->val < actual->val) {
                objetivo = actual->izq;
            }
            
            if (objetivo != NULL)  {
            	actual = objetivo;
            } else {
            	objetivo = nuevoNodo;
            }
        }
        
        /*
        while(actual->izq != NULL || actual->der != NULL) {
            if (nuevoNodo->val > actual->val) {
                actual = actual->der;
            } else if (nuevoNodo->val < actual->val) {
                actual = actual->izq;
            }
        }
        
        if (nuevoNodo->val > actual->val) {
            actual->der = nuevoNodo;
        } else if (nuevoNodo->val < actual->val) {
            actual->izq = nuevoNodo;
        }
        
        */
    }
}




void mostrarDatos(struct Nodo *nodo) {
	if (nodo == raiz){
		printf("Nodo raiz: %d\n", nodo->val);
	}
	/*
	else if (nodo->der != NULL) {
		printf(" > valor por derecha\n");
		mostrarDatos(nodo->der);
	}
	
	else if (nodo->izq != NULL) {
		printf(" > valor por izquierda\n");
		mostrarDatos(nodo->izq);
	}
	
	else {
		printf("Valor del nodo: %d\n", nodo->val);
	}
	*/
	
	printf(" > valor por derecha %d\n", nodo->der->val);
	printf(" > valor por izquierda %d\n", nodo->izq->val);
}



int main()
{
    printf("Arbol Binario Default");
    int flag = 1;
    char a;
    
    do {
    	do {
	        printf("\n Desea agregar un nodo? (y / n) ");
	        fflush(stdin);
	        a = getche();
	        // scanf("%c", &a);
	        printf("\n\n");
    	} while (a != 'n' && a != 'y');
    
	    if (a == 'y') {
	    	agregarNodo();
		} else {
			flag = 0;
		}
	} while (flag != 0);
	
	
	system("cls");
	
	mostrarDatos(raiz);
	
    return 0;
}


