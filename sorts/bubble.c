#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int v[], int n){
    int* aux = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        aux[i] = v[i];

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++)
            if(aux[j] > aux[j + 1]){
                int temp = aux[j];
                aux[j] = aux[j + 1];
                aux[j + 1] = temp;
            }
    }

    return aux;
}

void print(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n\n");
}

int main(){
    int v[] = {56, 23, 78, 12, 45, 67, 89, 34, 11, 90, 43, 65, 99, 2, 5, 77, 38, 54, 33, 41, 18, 27, 61, 83, 92, 6, 44, 71, 13, 39, 48, 19, 74, 88, 91, 25, 31, 84, 100, 59, 29, 81, 16, 52, 22, 93, 60, 8, 10, 36};
    int n = sizeof(v) / sizeof(v[0]);

    print(v, n);
    int* sorted_v = bubbleSort(v, n);
    print(sorted_v, n);

    free(sorted_v);
    return 0;
}
