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

typedef struct tipoPilha {
    struct tipoNo *topo; //ponteiro para variável do tipoNo
} tipoPilha;

void criaPilha(tipoPilha *pPilha) {
    pPilha->topo = NULL;
}

void insereNaPilha(tipoPilha *pPilha, tipoAluno *al) {
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *al;
    aux->prox = pPilha->topo;
    pPilha->topo = aux;
}

int removeDaPilha(tipoPilha *pPilha, tipoAluno *res) {
    tipoNo *tmp;

    tmp = pPilha->topo;
    if(tmp) {
        pPilha->topo = tmp->prox;
        *res = tmp->dado;
        free(tmp);
        return 1;
    }

    return 0;
}

void mostraPilha(tipoPilha *pPilha) {
    tipoNo *aux;

    aux = pPilha->topo;

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
    tipoPilha l1, l2;

    criaPilha(&l1);

    strcpy(aluno.nome, "Jose");
    strcpy(aluno.curso, "Ciencia da Computacao");
    aluno.coeficienteRendimento = 8.0;
    aluno.pibic = 1;

    insereNaPilha(&l1, &aluno);

    strcpy(aluno.nome, "Maria");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 9.0;
    aluno.pibic = 1;
    
    insereNaPilha(&l1, &aluno);

    mostraPilha(&l1);

    return 0;
} 