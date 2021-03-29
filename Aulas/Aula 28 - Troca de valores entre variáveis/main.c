#include <stdio.h>
#include <string.h>

typedef struct tipoAluno {
    char nome[50];
    int matricula;
    char curso[30];
} tipoAluno;

int main() {
    int x = 10, y = 20, aux;
    tipoAluno aluno1, aluno2, auxAluno;

    strcpy(aluno1.nome, "Jose");
    strcpy(aluno1.curso, "Ciencia da Computacao");
    aluno1.matricula = 2011001;

    strcpy(aluno2.nome, "Maria");
    strcpy(aluno2.curso, "Engenharia de Software");
    aluno2.matricula = 9999001;

    printf("********** ANTES DA TROCA **********\n");

    printf("Valor de x antes da troca: %d\n", x);
    printf("Valor de y antes da troca: %d\n", y);
    printf("Aluno1:\n")    ;
    printf("Nome: %s\nCurso: %s\nMatricula: %d\n", aluno1.nome, aluno1.curso, aluno1.matricula);
    printf("\nAluno2:\n");
    printf("Nome: %s\nCurso: %s\nMatricula: %d\n", aluno2.nome, aluno2.curso, aluno2.matricula);

    //Aqui vamos trocar o valor de x com o de y e o aluno1 com o aluno2
    aux = x;
    x = y;
    y = aux;

    auxAluno = aluno1;
    aluno1 = aluno2;
    aluno2 = auxAluno;

    printf("\n********** DEPOIS DA TROCA **********\n");

    printf("Valor de x depois da troca: %d\n", x);
    printf("Valor de y depois da troca: %d\n", y);
    printf("Aluno1:\n")    ;
    printf("Nome: %s\nCurso: %s\nMatricula: %d\n", aluno1.nome, aluno1.curso, aluno1.matricula);
    printf("\nAluno2:\n");
    printf("Nome: %s\nCurso: %s\nMatricula: %d\n", aluno2.nome, aluno2.curso, aluno2.matricula);

    return 0;
}