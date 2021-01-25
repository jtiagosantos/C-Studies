#include <stdio.h>

int main() {
    int n, qte, maior, menor;

    printf("Quantos numeros voce quer digitar: ");
    scanf("%d%*c", &qte);
    
    printf("Entre com o valor de n: ");
    scanf("%d%*c", &n);
    maior = n;
    menor = n;

    while(qte > 1) {
        printf("Entre com o valor de n: ");
        scanf("%d%*c", &n);
        if(n > maior) {
            maior = n;
        }else if(n < menor) {
            menor = n;
        }
        qte--;
    }

    printf("O maior valor lido foi %d\n", maior);
    printf("O menor valor lido foi %d\n", menor);

    return 0;
}