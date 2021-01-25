#include <stdio.h>

int main() {
    int n, maior;
    unsigned int quantidade; //Para ler do tipo unsigned, usa-se %u

    printf("Quantos numeros voce quer digitar? ");
    scanf("%u%*c", &quantidade);

    printf("Entre com o valor de n: ");
    scanf("%d%*c", &n);
    maior = n;

    while(quantidade > 1) {
        printf("Entre com o valor de n: ");
        scanf("%d%*c", &n);
        if(n > maior) {
            maior = n;
        }
        quantidade--;
    }

    printf("O maior numero digitado foi %d\n", maior);

    return 0;
}