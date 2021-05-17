#include <stdio.h>

//Ponteiros para passagem de parâmetros por referência

void somarDois(int *pt) {
    *pt += 2;
}

int main() {
    int x = 95, y = 56, z = 77;
    int *pointer;

    pointer = &x;
    somarDois(pointer);
    printf("valor de x: %d\n", x);

    somarDois(&y);
    printf("valor de y: %d\n", y);

    somarDois(&z);
    printf("valor de z: %d\n", z);

    return 0;
}