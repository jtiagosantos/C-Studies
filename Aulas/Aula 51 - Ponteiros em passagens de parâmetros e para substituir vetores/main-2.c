#include <stdio.h>

int mostrarVetor(int vet[], unsigned tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d\n", vet[i]);
    }
}

int main() {
    int v1[2] = {3, 7};
    int v2[2] = {10, 20};

    int *p;

    p = v1; // p = &v1[0]

    mostrarVetor(p, 2);

    p = v2;

    mostrarVetor(p, 2);

    return 0;
}