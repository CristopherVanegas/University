#include <stdio.h>
int busquedaBinaria(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Si el elemento se encuentra en la mitad del array
        if (arr[mid] == x)
            return mid;
        // Si el elemento es mayor, descartamos la mitad izquierda
        if (arr[mid] < x)
            left = mid + 1;
        // Si el elemento es menor, descartamos la mitad derecha
        else
            right = mid - 1;
    }
    // Si no se encontró el elemento, se retorna -1
    return -1;
}
int main() {
    int arr[] = {15, 67, 8, 16, 44, 27, 12, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 27;
    int result = busquedaBinaria(arr, 0, n-1, x);
    if (result == -1)
        printf("El elemento no se encuentra en el array.");
    else
        printf("El elemento se encuentra en el indice %d.", result);
    return 0;
}

