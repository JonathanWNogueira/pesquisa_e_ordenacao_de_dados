#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void hSort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

int* heapSort(int v[], int n){
    int* aux = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        aux[i] = v[i];

    hSort(aux, n);

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
    int* sorted_v = heapSort(v, n);
    print(sorted_v, n);

    free(sorted_v);
    return 0;
}
