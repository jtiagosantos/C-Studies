#include <stdio.h>

int main() {
    int vet[10];
    unsigned int cont;

    for(cont=0; cont<10; cont++) {
        printf("Entre com o valor da posicao %d: ", cont);
        scanf("%d%*c", &vet[cont]);
    }

    printf("\nMostrando os valores do vetor:\n");
    for(cont=0; cont<10; cont++) {
        printf("Posicao %d: %d\n", cont, vet[cont]);
    }

    return 0;
}
