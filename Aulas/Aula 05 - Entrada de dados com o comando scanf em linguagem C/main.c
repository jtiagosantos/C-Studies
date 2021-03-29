#include <stdio.h> 
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    float nota1, nota2, nota3, media;

    printf("Entre com a nota1: ");
    scanf("%f%*c", &nota1);
    printf("Entre com a nota2: ");
    scanf("%f%*c", &nota2);
    printf("Entre com a nota3: ");
    scanf("%f%*c", &nota3);
    media = (nota1 + nota2 + nota3)/3,0;

    printf("A media entre as notas %.2f, %.2f e %.2f: %.2f\n", nota1, nota2, nota3, media);

    if(media >= 5) {
        printf("Aprovado!\n");
    }else {
        printf("Reprovado!\n");
    }

    return 0;
}