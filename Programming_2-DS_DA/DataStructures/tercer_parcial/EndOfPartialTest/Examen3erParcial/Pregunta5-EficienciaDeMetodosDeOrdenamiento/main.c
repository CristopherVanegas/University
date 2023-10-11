//    Est. Cristopher Vanegas                       //
//     [] Ejercicio 5 - Eficiencia de Algoritmos     //
//    METODOS DE ORDENAMIENTO                       //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int dataSet[25000];
int d = 25000;

void cargarDatos() {
    for (int i = 0; i < (sizeof(dataSet)/sizeof(dataSet[0])); i++) {
        dataSet[i] = 1 + rand() % 2124;
    }
}

// BUBBLE //
void OrdenamientoBurnuja(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// QUICK SORT //
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// SHELL SORT //
void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    // Empieza con el intervalo más grande
    for (gap = n/2; gap > 0; gap /= 2) {
        // Realiza la comparación y ordenamiento para cada intervalo
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void escribirData(int dataSet[], char m) {
    FILE *f;

    switch (m) {
        case 'n': { // new
            f = fopen("dataSetRandom.txt", "w");
        } break;

        case 'o': { // ordered
            f = fopen("dataSetOrdered.txt", "w");
        } break;
    }

    if (f != NULL) {
        for (int i = 0; i < d; i++) {
            // fwrite(&dataSet[i], sizeof(int), 1, f);
            fprintf(f, " %d ", dataSet[i]);
            // printf(" | %d |", dataSet[i]);
        }
    }

    fclose(f);
}

void menu()
{
    cargarDatos();
    escribirData(dataSet, 'n');

    for (;;)
    {
        int o;
        do
        {
            system("cls");
            printf("\nSISTEMA DE PRUEBAS DE EFICIENCIA");
            printf("\n\t1) Metodo Bubble");
            printf("\n\t2) Metodo QuickSort");
            printf("\n\t3) Metodo ShellSort");
            printf("\n\t4) Salir");
            printf("\nElige una opcion del menu: ");
            scanf("%d", &o);
        } while (o < 1 && o > 4);

        clock_t start_time, end_time;
        double total_time;

        start_time = clock();

        switch(o) {
            case 1: {
                OrdenamientoBurnuja(dataSet, d);
            } break;

            case 2: {
                quicksort(dataSet, 0, d-1);
            } break;

            case 3: {
                shellSort(dataSet, d);
            } break;

            case 4: {
                exit(1);
            } break;
        }

        end_time = clock();
        total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Tiempo de ejecucion: %f segundos\n", total_time);


        escribirData(dataSet, 'o');

        printf("\nPress any key to continue...");
        getch();

    }


}

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
