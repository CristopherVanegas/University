#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la lista
struct Nodo {
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};
struct Nodo *cabeza = NULL;

struct Nodo *crear_nodo(int valor) {
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = NULL;
    return nuevo_nodo;
}

void agregar_nodo_posicion_especifica(int valor, int posicion) {
    struct Nodo *nuevo_nodo = crear_nodo(valor);
    if (cabeza == NULL) {
         cabeza = nuevo_nodo;
    } else {
        // Si la posición es 0, el nuevo nodo es la nueva cabeza
        if (posicion == 0) {
            struct Nodo *primer_nodo = cabeza;
            nuevo_nodo->siguiente = primer_nodo;
            nuevo_nodo->anterior = NULL;
            primer_nodo->anterior = nuevo_nodo;
            cabeza = nuevo_nodo;
        }else{
            // Encontrar el nodo anterior a la posición de inserción
            struct Nodo *nodo_anterior = cabeza;
            for (int i = 0; i < posicion - 1; i++) {
                if (nodo_anterior->siguiente == NULL) {
                    printf("LA LISTA NO TIENE LA POSICION ESPECIFICA!!\n");
                    return;
                }
                nodo_anterior = nodo_anterior->siguiente;
            }
            // Insertar el nuevo nodo después del nodo anterior
            nuevo_nodo->siguiente = nodo_anterior->siguiente;
            nuevo_nodo->anterior = nodo_anterior;
            if (nodo_anterior->siguiente != NULL) {
                nodo_anterior->siguiente->anterior = nuevo_nodo;
                //printf("Este no es el ultimo");
                }
            nodo_anterior->siguiente = nuevo_nodo;
        }
    }

}

void agregar_nodo_al_inicio_lista(int valor) {
    struct Nodo *nuevo_nodo = crear_nodo(valor);
    if (cabeza == NULL) {
         cabeza = nuevo_nodo;
    } else {
            struct Nodo *primer_nodo = cabeza;
            nuevo_nodo->siguiente = primer_nodo;
            nuevo_nodo->anterior = NULL;
            primer_nodo->anterior = nuevo_nodo;
            cabeza = nuevo_nodo;
        }
}

void agregar_nodo_al_final_lista(int valor) {
    struct Nodo *nuevo_nodo = crear_nodo(valor);
    if (cabeza == NULL) {
         cabeza = nuevo_nodo;
    } else {
            struct Nodo *ultimo_nodo = cabeza;
            while (ultimo_nodo->siguiente != NULL) {
                    ultimo_nodo = ultimo_nodo->siguiente;
                    }
            ultimo_nodo->siguiente = nuevo_nodo;
            nuevo_nodo->anterior = ultimo_nodo;
            }
}

void eliminar_nodo_al_inicio_lista() {
    if (cabeza == NULL) {
         printf("LA LISTA ESTA VACIA");
    } else {
            struct Nodo *primer_nodo = cabeza;
            cabeza = cabeza->siguiente;
            cabeza->anterior = NULL;
            free(primer_nodo);
            }
}

void eliminar_nodo_al_final_lista() {
    if (cabeza == NULL) {
         printf("LA LISTA ESTA VACIA");
    } else {
            struct Nodo *ultimo_nodo = cabeza;
            while (ultimo_nodo->siguiente != NULL) {
                    ultimo_nodo = ultimo_nodo->siguiente;
                    }
            //puntero del nodo anterior al último nodo (penultimo nodo)
            ultimo_nodo->anterior->siguiente = NULL;
            free(ultimo_nodo);
            }
}

void eliminar_nodo_posicion_especifica(int posicion) {
    if (cabeza == NULL) {
         printf("LA LISTA ESTA VACIA ");
         return;
    }
    if (posicion == 0){
         printf("ESTE VALOR DE POSICION NO ES VALIDA!!");
         return;
    }
    if (posicion == 1){
        eliminar_nodo_al_inicio_lista();
    }else {
            int contador = 1;
            struct Nodo *nodo_actual = cabeza;
            while (nodo_actual != NULL && contador < posicion) {
                nodo_actual = nodo_actual->siguiente;
                contador++;
            }
            if (nodo_actual == NULL) {
                // La posición es mayor que la cantidad de nodos en la lista
                printf("LA POSICION ESPECIFICA ES MAYOR QUE LA CANTIDAD DE NODOS EN LA LISTA!!\n");
                return;
                }
            struct Nodo *nodo_anterior = nodo_actual->anterior;
            struct Nodo *nodo_siguiente = nodo_actual->siguiente;
            nodo_anterior->siguiente = nodo_siguiente;
            if (nodo_siguiente != NULL) {
                    nodo_siguiente->anterior = nodo_anterior;
             }else{printf("ESTE ES EL ULTIMO NODO");}
            free(nodo_actual);
            }
}
  // Imprimir la lista
void imprimir_lista() {
    if (cabeza == NULL) {
        printf("LA LISTA ESTA VACIA....\n");
    } else {
        printf("DATOS DE LISTA: ");
            struct Nodo* nodo_actual = cabeza;
            while (nodo_actual != NULL) {
                printf("%d ", nodo_actual->dato);
                nodo_actual = nodo_actual->siguiente;
        }
        printf("\n");
    }
}


int main() {

        int opc, valor, posicion;

      do
      {
        printf("\n ---------------------MENU-----------------: \n");
        printf("\t1) INSERTAR EN POSICION INICIAL\n");//2
        printf("\t2) INSERTAR EN POSICION FINAL\n");//3
        printf("\t3) INSERTAR EN POSICION ESPECIFICA\n");//1
        printf("\t4) MOSTRAR DATOS\n");//7
        printf("\t5  ELIMINAR EL INICIO DE LISTA\n");//4
        printf("\t6) ELIMINAR EL FINAL DE LISTA\n");//5
        printf("\t7) ELIMINAR POSICION ESPECIFICA\n");//6
        printf("\t8) SALIR.....\n\n");//8
        printf("SELECCIONE UNA OPCION DEL MENU: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("INGRESE EL VALOR DEL NODO INICIAL: ");
                scanf("\n%d", &valor);
                agregar_nodo_al_inicio_lista(valor);
                break;
            case 2:
                printf("INGRESE EL VALOR DEL NODO FINAL: ");
                scanf("\n%d", &valor);
                agregar_nodo_al_final_lista(valor);
                break;
            case 3:
                printf("INGRESE EL VALOR DEL NODO ESPECIFICO: ");
                scanf("%d", &valor);
                printf("INGRESE LA POSICION: ");
                scanf("\n%d", &posicion);
                agregar_nodo_posicion_especifica(valor, posicion);
                break;
            case 4:
                imprimir_lista();
                break;

            case 5:
                eliminar_nodo_al_inicio_lista();
                break;
            case 6:
                eliminar_nodo_al_final_lista();
                break;

            case 7:
                printf("INGRESE LA POSICION DEL NODO ESPECIFICO A ELIMINAR: ");
                scanf("%d", &posicion);
                eliminar_nodo_posicion_especifica(posicion);
                break;
            case 8:
                printf("\nHASTA LA PROXIMA.....\n");
                break;
            default:
                printf("OPCION SELECCIONADA ES INCORRECTA\n");
        }
    }
     while(opc != 8);
}
