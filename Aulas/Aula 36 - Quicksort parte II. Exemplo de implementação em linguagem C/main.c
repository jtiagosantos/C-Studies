#include <stdio.h>

void quickSort(int vetor[], int inicio, int fim) {
    int i, j, pivot, aux;

    if(inicio < fim) {
        //particiona o vetor
        pivot = vetor[(inicio+fim)/2];
        i = inicio;
        j = fim;

        while(i <= j) {
            while(vetor[i] < pivot) i++; //avanca enquanto está do lado certo
            while(vetor[j] > pivot) j--; //recua enquanto está do lado certo
            if(i <= j) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
            }
        } 
        quickSort(vetor, inicio, j);
        quickSort(vetor, i, fim);
    }
}

void mostrarVetor(int vetor[], int TamanhoVetor) {
    int i;
    
    printf("[");
    for(i = 0; i < TamanhoVetor; i++) {
        printf("%d, ", vetor[i]);
    }
    printf("%d]", vetor[TamanhoVetor]);
}

int main() {
    int vetor[26] = {117,90,88,83,81,77,74,69,64,63,51,50,49,42,41,34,32,29,28,22,16,8,6,5,3,1};

    quickSort(vetor, 0, 26);
    mostrarVetor(vetor, 26);

    return 0;
}