#include <stdio.h>
#include <string.h>

typedef struct tipoAluno {
    char nome[50];
    int matricula;
    char curso[30];
} tipoAluno;

void ordenarAlunosPorNome(tipoAluno alunos[], int tamanhoAlunos) {
    unsigned penultimo = tamanhoAlunos - 1;
    tipoAluno aux;
    unsigned i, cont, posMenor;

    for(i=0; i < penultimo; i++) {
        posMenor = i;
        for(cont=i+1; cont < tamanhoAlunos; cont++) {
            if(strcmp(alunos[cont].nome, alunos[posMenor].nome) < 0) {
                posMenor = cont;
            }
        }

        aux = alunos[i];
        alunos[i] = alunos[posMenor];
        alunos[posMenor] = aux;
    }
}

void mostrarAlunos(tipoAluno alunos[], int tamanhoAlunos) {
    unsigned i;

    for(i = 0; i < tamanhoAlunos; i++) {
        printf("****************************\n");
        printf("%s\n", alunos[i].nome);
        printf("%s\n", alunos[i].curso);
        printf("\n");
    }
}


int main() {
    tipoAluno alunos[7];

    strcpy(alunos[0].nome, "Maria Joaquina");
    strcpy(alunos[1].nome, "Ancelmo Goes");
    strcpy(alunos[2].nome, "Aderbal Lacerda");
    strcpy(alunos[3].nome, "Guilerminilda dos Santos Lacerda");
    strcpy(alunos[4].nome, "Alfonsin da Silveira");
    strcpy(alunos[5].nome, "kimosabison Pereira");
    strcpy(alunos[6].nome, "Genildsa Cardoso");

    strcpy(alunos[0].curso, "Ciencia da Computacao");
    strcpy(alunos[1].curso, "Ciencia da Computacao");
    strcpy(alunos[2].curso, "Engenharia de Software");
    strcpy(alunos[3].curso, "Engenharia de Software");
    strcpy(alunos[4].curso, "Matematica");
    strcpy(alunos[5].curso, "Matematica");
    strcpy(alunos[6].curso, "Engenharia de Software");

    printf("Vetor alunos antes de ordenar:\n");
    mostrarAlunos(alunos, 7);

    ordenarAlunosPorNome(alunos, 7);
    printf("\n");

    printf("Vetor alunos depois de ordenar:\n");
    mostrarAlunos(alunos, 7);

    return 0;
}