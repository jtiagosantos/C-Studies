#include <stdio.h> 

int main() {
    float nota1, nota2, nota3;
    float media;
    int valor1, valor2, media_valores;

    valor1 = 10;
    valor2 = 5;
    media_valores = (valor1 + valor2 + 2)/3;
    printf("Media dos tres valores: %d\n", media_valores);
    printf("O resto da divisao eh %d\n", (valor1 + valor2 + 2)%3);

    nota1 = 7.5;
    nota2 = 6.7;
    nota3 = 8.2;
    media = (nota1 + nota2 + nota3)/3.0;

    printf("Media entre as notas %.2f, %.2f e %.2f: %.2f\n", nota1, nota2,nota3, media);

    return 0;
}