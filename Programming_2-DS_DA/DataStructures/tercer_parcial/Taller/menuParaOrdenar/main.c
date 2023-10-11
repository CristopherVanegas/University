#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[50];
    char apellido[100];
    float estatura;
} Estudiante;

Estudiante estudiantes[16];

void ingresarDatos()
{
    int d = sizeof(estudiantes)/sizeof(estudiantes[0]);
    for (int i = 0; i < d; i++)
    {
        system("cls");
        printf("\n\t[]  INSERCION DE DATOS\n");
        printf("\n [] Ingrese nombre del estudiante %d: ", i + 1);
        fflush(stdin);
        fgets(&estudiantes[i].nombre, 50, stdin);

        printf("\n [] Ingrese apellido del estudiante %d: ", i + 1);
        fflush(stdin);
        fgets(&estudiantes[i].apellido, 100, stdin);

        printf("\n [] Ingrese estatura del estudiante %d: ", i + 1);
        fflush(stdin);
        scanf("%f", &estudiantes[i].estatura);
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    int left, right, mid;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        left = 0;
        right = i - 1;
        // Encontrar el punto de inserción mediante búsqueda binaria
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (key < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // Desplazar los elementos del arreglo para hacer espacio para la inserción
        for (j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
        }
        // Insertar el elemento en su posición correcta
        arr[left] = key;
    }
}

void OrdenamientoBurnuja(Estudiante arr[], int n)
{
    int i, j;
    Estudiante temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j].estatura > arr[j + 1].estatura)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int busquedaBinaria(Estudiante arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // Si el elemento se encuentra en la mitad del array
        if (arr[mid].estatura == x)
            return mid;
        // Si el elemento es mayor, descartamos la mitad izquierda
        if (arr[mid].estatura < x)
            left = mid + 1;
        // Si el elemento es menor, descartamos la mitad derecha
        else
            right = mid - 1;
    }
    // Si no se encontró el elemento, se retorna -1
    return -1;
}

void shellSort(Estudiante arr[], int n)
{
    int gap, i, j, temp;
    // Empieza con el intervalo más grande
    for (gap = n/2; gap > 0; gap /= 2)
    {
        // Realiza la comparación y ordenamiento para cada intervalo
        for (i = gap; i < n; i++)
        {
            temp = arr[i].estatura;
            for (j = i; j >= gap && arr[j - gap].estatura > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j].estatura = temp;
        }
    }
}

void shakerSort(Estudiante arr[], int n)
{
    int i, j, k;
    Estudiante temp;
    for(i = 0; i < n - 1; )
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[j].estatura < arr[j - 1].estatura)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                k = j;
            }
        }
        n = k;
        for(j = n - 1; j > i; j--)
        {
            if(arr[j].estatura < arr[j - 1].estatura)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                k = j;
            }
        }
        i = k;
    }
}

void seleccionDirecta(Estudiante arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j].estatura < arr[min_idx].estatura)
            {
                min_idx = j;
            }
        }
        Estudiante temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// QUICK SORT  //
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(Estudiante arr[], int low, int high)
{
    int pivot = arr[high].estatura;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].estatura <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(Estudiante arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
//////////////////////////////

void insercionDirecta(Estudiante arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i].estatura;
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void menu()
{
    for(;;)
    {
        int o;
        system("cls");
        printf("\n\t[]  MENU METODOS:\n");
        printf("\t 1) Burbuja\n");
        printf("\t 2) Shaker\n");
        printf("\t 3) Seleccion Directa\n");
        printf("\t 4) Inserccion: Directa\n");
        printf("\t 5) Inserccion: Binario\n");
        printf("\t 6) Shell Sort\n");
        printf("\t 7) Quick Sort\n");
        printf("\t 8) Salir\n");
        printf("\n  >  Elige una opcion del menu: ");
        fflush(stdin);
        scanf("%d", &o);

        while(o > 0 && o <= 8)
        {
            switch(o)
            {
            case 1:
            {
                OrdenamientoBurnuja(estudiantes, sizeof(estudiantes)/sizeof(estudiantes[0]));
            }
            break;

            case 2:
            {
                shakerSort(estudiantes, sizeof(estudiantes)/sizeof(estudiantes[0]));
            }
            break;

            case 3:
            {
                seleccionDirecta(estudiantes, sizeof(estudiantes)/sizeof(estudiantes[0]));
            }
            break;

            case 4:
            {
                insercionDirecta(estudiantes, sizeof(estudiantes)/sizeof(estudiantes[0]));
            }
            break;

            case 5:
            {
                insertionSort(estudiantes, sizeof(estudiantes)/sizeof(estudiantes[0]));
            }
            break;

            case 6:
            {
                shellSort(estudiantes, sizeof(estudiantes)/sizeof(estudiantes[0]));
            }
            break;

            case 7:
            {
                quicksort(estudiantes, 0, (sizeof(estudiantes)/sizeof(estudiantes[0])) - 1);
            }
            break;

            case 8:
            {
                printf("Finalizado el programa");
                exit(1);
                break;
            }
            break;
            }
        }
    }
}

int main()
{
    ingresarDatos();
    menu();

    return 0;
}
