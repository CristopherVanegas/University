//   Est. Cristopher Vanegas   //
//    Lista Enlazada Simple    //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct informacion
{
    int item1;
    char *item2;
    float item3;
};

struct nodo
{
    struct informacion info;
    struct nodo *sig;
};

typedef struct nodo *TipoLista;
void lee_nodo(struct informacion *inf);
void lee_nodof(struct informacion *inf, FILE *fp);
void muestra (TipoLista lista);
TipoLista inserta (TipoLista lista);
void consulta_item2 (TipoLista lista);
void modifica_item2 (TipoLista lista);
TipoLista borra_item2 (TipoLista lista);
void guarda (TipoLista lista);
TipoLista recupera (TipoLista lista);

TipoLista lista_vacia (void)
{
    return NULL;
}

void lee_nodo (struct informacion *inf)
{
    int i;
    char w[20], *pw;
    float x;
    printf("Ingresa ebtero: ");
    scanf(" %d", &i);
    printf("Ingresa palabra: ");
    // scanf(" %s", &w);     cadena simple
    scanf(" %[^\n]", &w); // cadena compuesta
    printf("Ingresa flotante: ");
    scanf(" %f", &x);
    inf->item1=i;
    pw = malloc(strlen(w)+1);
    strcpy(pw, w);
    inf->item2= pw;
    inf->item3 = x;
}

TipoLista inserta (TipoLista lista)
{
    struct informacion *inf = malloc (sizeof (struct informacion));
    lee_nodo(inf);
    struct nodo *nuevo = malloc (sizeof(struct nodo));
    nuevo-> info = *inf;
    nuevo->sig= lista;
    lista = nuevo;
    return lista;
}

void muestra(TipoLista lista)
{
    struct nodo *aux;
    printf("->");
    for (aux=lista; aux!=NULL; aux=aux->sig){
        printf("[%s]-> ", aux->info.item2);
        //printf("[%d, %s, %f]-> \n", aux->info.item1, aux->info.item2, aux->info.item3);
    }
    printf("\n");
}

TipoLista borra_item2 (TipoLista lista)
{
    char w[20];
    struct nodo *aux, *atras;
    printf("item 2 a borrar: ");
    scanf(" %[^\n]", w); // cadena compuesta
    for (atras=NULL, aux=lista; aux!=NULL; atras=aux, aux=aux->sig)
    if (strcmp(aux->info.item2, w)==0){
        if(atras==NULL)
            lista = aux-> sig;
        else
            atras->sig= aux-> sig;
    free(aux);
    printf("nodo eliminado\n");
    return lista;
    }
    return lista;
}

void consulta_item2 (TipoLista lista)
{
    char w[20];
    struct nodo *aux;
    printf("item 2 a consultar: ");
    scanf(" %[^\n]", w); //cadena compuesta
    for (aux=lista; aux!=NULL; aux=aux->sig)
        if (strcmp(aux->info.item2, w)==0){
            printf("Item 1: %d\n",aux->info.item1);
            printf("Item 3: %.2f\n", aux->info.item3);
        }
}

void modifica_item2 (TipoLista lista)
{
    char w[20];
    struct nodo *aux;
    printf("item 2 a modificar: ");
    scanf(" %[^\n]", w); //cadena compuesta
    for (aux=lista; aux!=NULL; aux=aux->sig)
    if(strcmp(aux->info.item2, w)==0){
        lee_nodo(&aux->info);
    }
}

void guarda(TipoLista lista)
{
    struct nodo *aux;
    FILE *fp;
    char c;
    printf("Guardar en fichero binario (b)?: ");
    scanf(" %c",&c);
    if(c=='b')
        fp = fopen ("itemsb.dat", "wb"); //fichero binario
    else
        fp = fopen("itemsb.txt", "w"); //fichero texto
    if (fp == NULL){
        printf("Error en escritura de ficehero");
        exit(-1);
    }
    for (aux=lista; aux!=NULL; aux=aux->sig){
        if(c=='b'){
            printf("%d \n", aux->info.item1);
            fwrite(&aux->info, sizeof(struct informacion), 1, fp); //corregir error de grabacion de campos char
        }
        else{
            fprintf(fp, "%d\n", aux->info.item1);
            fprintf(fp, "%s\n", aux->info.item2);
            fprintf(fp, "%.2f\n", aux->info.item3);
        }
    }
    fclose(fp);
    printf("fichero creado\n");

}

void lee_nodof(struct informacion *inf, FILE *fp)
{
    int i;
    char w[20], *pw;
    float x;
    fscanf(fp, " %d",&i);
    fscanf(fp, " %[^\n]", w); // cadena compuesta
    fscanf(fp, " %f", &x);
    inf->item1 = i;
    pw = malloc(strlen(w)+1);
    strcpy(pw, w);
    inf->item2= pw;
    inf->item3= x;
}

TipoLista recupera(TipoLista lista)
{
    FILE *fp;
    // struct nodo *n;
    char c;
    printf("Fichero bnario (b)?: ");
    scanf(" %c", &c);
    if (c=='b')
        fp=fopen("itemsb.dat", "rb");
    else
        fp=fopen("itemsb..txt", "r");
    if (fp==NULL){
        printf("Error en ectura de fichero");
        exit(-1);
    }
    while (!feof(fp))
    {
        struct informacion *inf = malloc(sizeof (struct informacion));
        if (c=='b')
            fread(inf, sizeof(struct informacion), 1, fp);
        else
            lee_nodof(inf, fp);
        struct nodo *nuevo = malloc (sizeof(struct nodo));
        nuevo->info= *inf;
        nuevo->sig=lista;
        lista=nuevo;
    }
    fclose(fp);
    printf("lista creada\n");
    return lista ->sig;
}



int main()
{
    TipoLista l; int opcion=0, salir=0; char continuar[2];
    l=lista_vacia(); //Inicializar lista
    do{
        printf("\n MENU DE LA APLICACION: \n");
        printf("\t1) Mostrar\n"); printf("\t2) Insertar\n");
        printf("t3) Consultar\n"); printf("\t4) Modificar\n");
        printf("\t5) Borrar\n"); printf("\t6) Guardar\n");
        printf("\t7) Recuperar\n"); printf("\t8) Salir\n");
        printf("Elige una opcion del menu: ");scanf(" %d",&opcion);
        switch (opcion)
        {
        case 1:
            muestra(l); break; //mostrar
        case 2: //insertar
            do{
                l=inserta(l); printf("Desea continuar? (si/no): "); scanf(" %s",continuar);
            } while (strcmp(continuar, "no")!=0); break;
        case 3: consulta_item2(l); break; //consultar
        case 4: modifica_item2(l); break; //modificar
        case 5: borra_item2(l); break; //borrar
        case 6: guarda(l); break; //guardar
        case 7: l=recupera(l); break; //recuperar
        case 8: salir=1; break;
        default:
            printf("\nOpcion incorrecta\n");
        }
    } while (salir!=1);
    printf("\nPrograma terminado\n");
    return 0;
}
