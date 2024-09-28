#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;    

    while(i < n1 && j < n2){
        if(L[i] <= R[j]) 
            arr[k] = L[i], i++;
        else
            arr[k] = R[j], j++;
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++, k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++, k++;
    }

    free(L);
    free(R);
}

void mSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mSort(arr, left, mid);
        mSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int* mergeSort(int v[], int n){
    int* aux = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        aux[i] = v[i];

    mSort(aux, 0, n - 1);

    return aux;
}

void print(int v[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n\n");
}

int main(){
    int v[] = {56, 23, 78, 12, 45, 67, 89, 34, 11, 90, 43, 65, 99, 2, 5, 77, 38, 54, 33, 41, 18, 27, 61, 83, 92, 6, 44, 71, 13, 39, 48, 19, 74, 88, 91, 25, 31, 84, 100, 59, 29, 81, 16, 52, 22, 93, 60, 8, 10, 36};
    int n = sizeof(v) / sizeof(v[0]);

    print(v, n);
    int* sorted_v = mergeSort(v, n);
    print(sorted_v, n); 

    free(sorted_v);
    return 0;
}
