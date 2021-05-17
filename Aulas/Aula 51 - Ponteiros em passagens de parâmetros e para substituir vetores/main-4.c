#include <stdio.h>

void somarVetores(int *res, int *v1, int *v2, unsigned tam) {
    for(int i = 0; i < tam; i++) {
        res[i] = v1[i] + v2[i];
    }
}

void somarVetores2(int *res, int *v1, int *v2, unsigned tam) {
    int *fim = &res[tam];

    while(res < fim) {
        *res = *v1 + *v2;
        res++; v1++; v2++;
    }
}

int mostrarVetor(int vet[], unsigned tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d\n", vet[i]);
    }
}

int main() {
    int v1[3] = {1,2,3}, v2[3] = {4,5,6}, res[3];

    somarVetores2(res, v1, v2, 3);

    mostrarVetor(res, 3);

    return 0;
}