#include <stdio.h> 

int main() {
    float nota1, nota2, nota3, media;

    nota1 = 2.5;
    nota2 = 3.5;
    nota3 = 5.2;
    media = (nota1 + nota2 + nota3)/3.0;

    printf("A media entre as notas %.2f, %.2f e %.2f: %.2f\n", nota1, nota2, nota3, media);

    if(media >= 5) {
        printf("Aprovado!\n");
    }else {
        printf("Reprovado!\n");
    }

    return 0;
}