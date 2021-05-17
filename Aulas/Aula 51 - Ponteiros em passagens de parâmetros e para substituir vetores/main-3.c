#include <stdio.h>

int mostrarVetor(int vet[], unsigned tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d\n", vet[i]);
    }
}

int main() {
    int v[3] = {10, 17, 24};
    int *pointer;

    pointer = v;
    mostrarVetor(v, 3);

    *pointer = 5;
    mostrarVetor(v, 3);

    pointer++;
    *pointer = 12;
    mostrarVetor(v, 3);

    pointer++;
    *pointer = 19;
    mostrarVetor(v, 3);

    return 0;
}