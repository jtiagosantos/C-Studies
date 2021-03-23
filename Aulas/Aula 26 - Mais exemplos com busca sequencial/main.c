#include <stdio.h>
#include <string.h>

typedef struct tipoAluno {
    char nome[50];
    int matricula;
    char curso[30];
} tipoAluno;

/*
    Faça uma função que receba como parâmetro um vetor de alunos
    (tipoAluno) e um nome para busca. A função deve retornar -1 caso
    o aluno buscado não exista no vetor; se não, deve retornar a posição
    de ocorrência.
*/

int buscarSequencialmente(tipoAluno vetor[], 
                          unsigned tamanhoVetor,
                          char chave[]) {
        
        for(unsigned i; i<tamanhoVetor; i++) {
            if(strcmp(vetor[i].nome, chave) == 0) {
                return i;
            }
        }
        return -1;
    }

int main() {
    tipoAluno alunos[7];
    char chave[40];
    int pos;

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

    for(int mat=0; mat<7; mat++) {
        alunos[mat].matricula = mat;
    }

    printf("Informe o nome do aluno: ");
    scanf("%[^\n]%*c", chave);

    pos = buscarSequencialmente(alunos, 7, chave);
    if(pos != -1) {
        printf("Curso: %s.\n", alunos[pos].curso);
        printf("Matricula: %d.\n", alunos[pos].matricula);
    }else {
        printf("Aluno nao foi encontrado na base de dados!.\n");
    }

    return 0;
}