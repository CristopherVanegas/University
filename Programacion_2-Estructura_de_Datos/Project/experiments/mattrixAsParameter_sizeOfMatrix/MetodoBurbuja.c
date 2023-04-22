#include <stdio.h>
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
int main() {
    int arr[] = { 15, 67, 8, 16, 44, 27, 12, 35 };
    int n = sizeof(arr) / sizeof(arr[0]);
    OrdenamientoBurnuja(arr, n);
    printf("El arreglo ordenado es: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

