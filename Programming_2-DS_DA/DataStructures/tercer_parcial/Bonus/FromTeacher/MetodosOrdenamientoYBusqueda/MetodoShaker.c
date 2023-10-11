#include <stdio.h>
void shakerSort(int arr[], int n) {
    int i, j, k, temp;
    for(i = 0; i < n - 1; ) {
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                k = j;
            }
        }
        n = k;
        for(j = n - 1; j > i; j--) {
            if(arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                k = j;
            }
        }
        i = k;
    }
}

int main() {
    int arr[] = { 15, 67, 8, 16, 44, 27, 12, 35 };
    int n = sizeof(arr) / sizeof(arr[0]);
    shakerSort(arr, n);
    printf("El arreglo ordenado es: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

