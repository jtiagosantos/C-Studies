#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoAluno {
    char nome[30];
    char pibic; //verdadeiro or falso
    char curso[30];
    float coeficienteRendimento;
} tipoAluno;

typedef struct tipoNo {
    tipoAluno dado;
    struct tipoNo *prox; //ponteiro para o próximo elemento do mesmo tipo
} tipoNo;

typedef struct tipoLista {
    struct tipoNo *prim; //ponteiro para variável do tipoNo
} tipoLista;

void criaLista(tipoLista *pLista) {
    pLista->prim = NULL;
}

void insereElementoLista(tipoLista *pLista, tipoAluno *al) {
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *al;
    aux->prox = pLista->prim;
    pLista->prim = aux;
}

void mostraLista(tipoLista *pLista) {
    tipoNo *aux;

    aux = pLista->prim;

    while(aux) { //aux != NULL
        printf("Nome: %s\n", aux->dado.nome);
        printf("Curso: %s\n", aux->dado.curso);
        printf("Coeficiente: %.2f\n", aux->dado.coeficienteRendimento);
        if(aux->dado.pibic) {
            printf("Eh aluno de PIBIC.\n");
        }else {
            printf("Nao eh aluno de PIBIC.\n");
        }

        aux = aux->prox;
    }
}

int main() {
    tipoAluno aluno;

    tipoAluno *p = (tipoAluno*) malloc(sizeof(tipoAluno));
    tipoLista l1, l2;

    criaLista(&l1);

    strcpy(aluno.nome, "Jose");
    strcpy(aluno.curso, "Ciencia da Computacao");
    aluno.coeficienteRendimento = 8.0;
    aluno.pibic = 1;

    insereElementoLista(&l1, &aluno);

    strcpy(aluno.nome, "Maria");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 9.0;
    aluno.pibic = 1;
    
    insereElementoLista(&l1, &aluno);

    mostraLista(&l1);

    return 0;
}