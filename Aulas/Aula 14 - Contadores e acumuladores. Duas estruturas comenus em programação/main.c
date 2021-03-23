#include <stdio.h>

int main() {
    //Contadores
    int n;
    unsigned int cont;

    scanf("%d%*c", &n);
    //imprimir os pares de 0 até n
    for(cont=0; cont<=n; cont++) {
        if(cont % 2 == 0) {
            printf("%d\n", cont);
        }
    }

    //Acumuladores
    int soma=0, m;
    unsigned int count;

    scanf("%d%*c", &m);

    //Mostrar a soma de todos os números de 1 a m
    for(count=1; count<=m; count++) {
        soma += count;
    }

    printf("Soma de 1 ate %d: %d\n", m, soma);

    return 0;
}