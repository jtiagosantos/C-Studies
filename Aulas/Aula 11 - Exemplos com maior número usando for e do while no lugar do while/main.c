#include <stdio.h>

int main() {
    //Tamanho das variáveis
    /*
    char x;
    short y;
    int w;
    long long z;

    unsigned char ux;
    unsigned short uy;
    unsigned int uw;
    unsigned long long uz;

    //lu - long unsigned
    printf("Tamanho de bytes da varivel x: %lu\n", sizeof(x));
    printf("Tamanho de bytes da varivel y: %lu\n", sizeof(y));
    printf("Tamanho de bytes da varivel w: %lu\n", sizeof(w));
    printf("Tamanho de bytes da varivel z: %lu\n", sizeof(z));

    printf("\nTamanho de bytes da varivel ux: %lu\n", sizeof(ux));
    printf("Tamanho de bytes da varivel uy: %lu\n", sizeof(uy));
    printf("Tamanho de bytes da varivel uw: %lu\n", sizeof(uw));
    printf("Tamanho de bytes da varivel uz: %lu\n", sizeof(uz));
    */

    //Máscaras
    char x = -3;
    short y = 7;
    int w = 9;
    long long z = 11;

    unsigned char ux = 10;
    unsigned short uy = 1000;
    unsigned int uw = 2;
    unsigned long long uz = 345;

    printf("Valor de x: %hhd\n", x); //para printar numero do tipo char
    printf("Valor de y: %hd\n", y);
    printf("Valor de w: %d\n", w);
    printf("Valor de z: %ld\n", z);

    printf("\nValor de ux: %hhu\n", ux);
    printf("Valor de uy: %hu\n", uy);
    printf("Valor de uw: %u\n", uw);
    printf("Valor de uz: %lu\n", uz);
    

    return 0;
}