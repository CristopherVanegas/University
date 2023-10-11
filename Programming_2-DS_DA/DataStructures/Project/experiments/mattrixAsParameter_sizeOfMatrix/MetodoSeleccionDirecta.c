#include <stdio.h>
void seleccionDirecta(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
int main() {
    int arr[] = {15, 67, 8, 16, 44, 27, 12, 35};
    int n = sizeof(arr)/sizeof(arr[0]);
    seleccionDirecta(arr, n);
    printf("El arreglo ordenado es: \n");
    for (int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

