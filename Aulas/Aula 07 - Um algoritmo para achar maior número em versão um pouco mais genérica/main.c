#include <stdio.h>

int main() {
    int n, maior;

    printf("Entre com o valor de n: ");
    scanf("%d%*c", &n);
    maior = n;

    printf("Entre com o valor de n: ");
    scanf("%d%*c", &n);
    if(n > maior) {
        maior = n;
    }

    printf("Entre com o valor de n: ");
    scanf("%d%*c", &n);
    if(n > maior) {
        maior = n;
    }

    printf("Entre com o valor de n: ");
    scanf("%d%*c", &n);
    if(n > maior) {
        maior = n;
    }

    printf("O maior numero digitado foi %d\n", maior);

    return 0;
}