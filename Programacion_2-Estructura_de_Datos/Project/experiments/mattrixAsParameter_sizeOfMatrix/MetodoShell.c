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
 int main()
 {
    int arr[] = {15,67,8,16,44,27,12,35,56,21,13,28,60,36,07,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    shellSort(arr, n);
     printf("\nArreglo ordenado:\n");
     for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
   }
   return 0;
 }
