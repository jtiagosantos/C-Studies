#include <stdio.h>

void preencherVetorAleatoriamente(float vetor[], int tamanhoVetor) {
    int cont;
    srand(100);
    for(cont = 0; cont < tamanhoVetor; cont++) {
        vetor[cont] = rand();
    }
}

void copiarVetor(float vetor1[], float vetor2[], int tamanhoVetor) {
    int i;

    for(i = 0; i < tamanhoVetor; i++) {
        vetor1[i] = vetor2[i];
    }

}

int estaOrdenado(float vetor[], int tamanhoVetor) {
    int i;

    for(i = 0; i < tamanhoVetor-1; i++) {
        if(vetor[i] > vetor[i+1]) {
            return 0;
        }
    }
    return 1;
}

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
}

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

int main() { 
    static float vetorGrande1[500000];
    static float vetorGrande2[500000];

    preencherVetorAleatoriamente(vetorGrande1, 500000);
    copiarVetor(vetorGrande2, vetorGrande1, 500000);
    
    printf("Inicio da ordenacao\n");
    quickSort(vetorGrande1, 0, 500000);
    //insertionSort(vetorGrande1, 500000);
    printf("Fim da ordenacao\n");

    if(estaOrdenado(vetorGrande1, 500000)) {
        printf("A ordenacao funcionou!\n");
    }else {
        printf("Algo deu errado\n");
    }

    return 0;
}