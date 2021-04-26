#include <stdio.h>

void insertionSort(int vetor[], int tamanhoVetor) {
    int i = 1;

    while(i < tamanhoVetor) {
        int pivot = vetor[i]; //pivot sempre do mesmo tipo dos elementos do vetor
        int j = i - 1;

        while(j >= 0 && vetor[j] > pivot) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = pivot;
        i++;
    }

    for(i=0; i < tamanhoVetor; i++) {
        printf("[%d] = %d\n", i, vetor[i]);
    }
}


int main() {
    int vetor[5] = {23, 45, 1, 9, 12};

    insertionSort(vetor, 5);

    return 0;
}