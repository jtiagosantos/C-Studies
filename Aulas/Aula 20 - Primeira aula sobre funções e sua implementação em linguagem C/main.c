#include <stdio.h>

//tipoqueseráretornadopelafunção + nomedafunção

//Função que calcula o fatorial de um número

unsigned long fatorial(unsigned numero) {
    unsigned long fat = 1;
    unsigned cont;

    for(cont=2; cont<=numero; cont++) {
        fat *= cont;
    }

    return fat;
}


//Função que calcula a soma de 1 até n
/*
unsigned somaNaturais(unsigned numero) {
    unsigned soma = 0;
    unsigned cont;

    for(cont = 1; cont <= numero; cont++) {
        soma += cont;
    }

    return soma;
}
*/

unsigned somaNaturais(unsigned numero) {
    return (numero * (numero + 1)) / 2;
}


int main() {
    unsigned n;

    printf("Deseja saber o fatorial de qual numero? ");
    scanf("%d%*c", &n);
    printf("%d! = %lu\n", n, fatorial(n));
    printf("Soma de 1 ate %d: %u\n", n, somaNaturais(n));

    return 0;
}