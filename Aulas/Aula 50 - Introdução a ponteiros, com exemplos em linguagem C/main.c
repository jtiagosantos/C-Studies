#include <stdio.h>

int main() {
    char a = 25;
    int x = 95;

    printf("Endereco de memoria de a: %p\n", &a); //%p imprime o endereço de memória
    printf("Endereco de memoria de z: %p\n", &x);

    char *ptA; 
    // O * indica que a variável é ponteiro
    // Um ponteiro sempre aponta para um tipo. Nesse caso, para o tipo char
    // Um ponteiro aponta para o endereço de memória de outra variável
    // Um ponteiro também é uma variável e, por isso, também possui endereço de memória

    int *ptX;

    //Endereço de memória dos ponteiros    
    printf("\nEndereco memoria de ptA: %p\n", &ptA);
    printf("Endereco memoria de ptX: %p\n", &ptX);

    ptA = &a; //o endereço de memória de a ficará armazenado no ponteiro ptA
    ptX = &x;

    printf("\nValor de ptA: %p\n", ptA);
    printf("Valor de ptX: %p\n", ptX);

    printf("\nValor de a: %d\n", a);

    *ptA = 40; //É como se o ponteiro ptA fosse a própria variável a

    printf("Novo valor de a: %d\n",  a);
    
    return 0;
}