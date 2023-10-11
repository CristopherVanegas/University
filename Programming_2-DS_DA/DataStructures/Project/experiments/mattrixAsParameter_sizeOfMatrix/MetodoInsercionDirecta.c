#include <stdio.h>
void insercionDirecta(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = { 15, 67, 8, 16, 44, 27, 12, 35 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insercionDirecta(arr, n);
    printf("El arreglo ordenado es: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

