#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int mid = low + (high - low) / 2;
    
    swap(&arr[mid], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++)
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void qSort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr, low, high);

        qSort(arr, low, p - 1);
        qSort(arr, p + 1, high);
    }
}

int* quickSort(int v[], int n){
    int* aux = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        aux[i] = v[i];

    qSort(aux, 0, n - 1);

    return aux;
}

void print(int v[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n\n");
}

int main(){
    int v[] = {56, 23, 78, 12, 45, 67, 89, 34, 11, 90, 43, 65, 99, 2, 5, 77, 38, 54, 33, 41, 18, 27, 61, 83, 92, 6, 44, 71, 13, 39, 48, 19, 74, 88, 91, 25, 31, 84, 100, 59, 29, 81, 16, 52, 22, 93, 60, 8, 10, 36};
    int n = sizeof(v) / sizeof(v[0]);

    print(v, n);
    int* sorted_v = quickSort(v, n);
    print(sorted_v, n);

    free(sorted_v);
    return 0;
}
