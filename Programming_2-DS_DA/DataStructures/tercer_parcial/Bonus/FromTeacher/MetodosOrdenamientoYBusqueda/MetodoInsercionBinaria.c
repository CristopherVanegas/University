#include <stdio.h>
void insertionSort(int arr[], int n) {
   int i, j, key;
   int left, right, mid;
   for (i = 1; i < n; i++) {
      key = arr[i];
      left = 0;
      right = i - 1;
      // Encontrar el punto de inserción mediante búsqueda binaria
      while (left <= right) {
         mid = (left + right) / 2;
         if (key < arr[mid]) {
            right = mid - 1;
         } else {
            left = mid + 1;
         }
      }
      // Desplazar los elementos del arreglo para hacer espacio para la inserción
      for (j = i - 1; j >= left; j--) {
         arr[j + 1] = arr[j];
      }
      // Insertar el elemento en su posición correcta
      arr[left] = key;
   }
}

int main() {
   int arr[] = { 15, 67, 8, 16, 44, 27, 12, 35 };
   int n = sizeof(arr) / sizeof(arr[0]);
   int i;

   printf("Arreglo original:\n");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   insertionSort(arr, n);

   printf("\nArreglo ordenado:\n");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}

