#include <stdio.h>

void selectionSort(int vetor[], unsigned tamanhoVetor)  {
    unsigned penultimo = tamanhoVetor - 1;
    int aux;
    unsigned i, cont, posMenor;

    for(i=0; i < penultimo; i++) {
        posMenor = i;
        for(cont=i+1; cont < tamanhoVetor; cont++) {
            if(vetor[cont] < vetor[posMenor]) {
                posMenor = cont;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[posMenor];
        vetor[posMenor] = aux;
    }

    for(i=0; i < tamanhoVetor; i++) {
        printf("[%d] = %d\n", i, vetor[i]);
    }
}

int main() {
    int vetor[5] = {23, 45, 1, 9, 12};

    selectionSort(vetor, 5);

    return 0;
}