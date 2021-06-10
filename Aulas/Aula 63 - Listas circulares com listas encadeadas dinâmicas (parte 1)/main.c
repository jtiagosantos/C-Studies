#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoAluno {
    char nome[30];
    char pibic; //verdadeiro ou falso
    char curso[30];
    float coeficienteRendimento;
} tipoAluno;

typedef struct tipoNo {
    tipoAluno dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoListaCircular {
    tipoNo *atual;
    unsigned numElementos;
    char nomeEquipe[30];
} tipoListaCircular;

void mostraAluno(tipoAluno al) {
    printf("Nome: %s\n", al.nome);
    printf("Curso: %s\n", al.curso);
    printf("coeficiente de Rendimento: %.2f\n", al.coeficienteRendimento);
    if(al.pibic) {
        printf("Eh aluno de pibic\n\n");
    }else {
        printf("Nao eh aluno de pibic\n\n");
    }
}

void criaListaCircular(tipoListaCircular *pLista, char *nome) {
    pLista->atual = NULL;
    pLista->numElementos = 0;
    strcpy(pLista->nomeEquipe, nome);
}

void mostraListaCircular(tipoListaCircular *pLista) {
    tipoNo *aux;

    if(pLista->atual) {
        aux = pLista->atual;
        printf("*** Elemento da vez\n");
        mostraAluno(aux->dado);
        printf("*********************\n");
        aux = aux->prox;
        while(aux != pLista->atual) {
            mostraAluno(aux->dado);
            aux = aux->prox;
        }
    }
}

void proximoDaVez(tipoListaCircular *pLista) {
    if(pLista->atual) { //se tiver algum elemento na lista circular
        pLista->atual = pLista->atual->prox; //o atual recebe o próximo dele
    }
}

void insereNaListaCircular(tipoListaCircular *pLista, tipoAluno *al) {
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *al;
    if(pLista->atual) {
        aux->prox = pLista->atual->prox; //o elemento a ser inserido terá o próximo do atual como próximo dele
        pLista->atual->prox = aux; //o próximo do atual será o elemento inserido (aux)
    }else {
        pLista->atual = aux; //caso a lista circular esteja vazia, então o elemento inserido será o próprio elemento atual
        aux->prox = aux; //o próximo do elemento inserido será o próprio elemento
    }
    pLista->numElementos++;
}


int main() {
    tipoAluno aluno;
    tipoListaCircular l1, l2;
    tipoAluno *pAluno;
    char nome[30];

    criaListaCircular(&l1, "Turma 1");

    strcpy(aluno.nome, "Jose");
    strcpy(aluno.curso, "Ciencia da Computacao");
    aluno.coeficienteRendimento = 8.0;
    aluno.pibic = 1;

    insereNaListaCircular(&l1, &aluno);

    printf("#######################################\n");
    mostraListaCircular(&l1);

    strcpy(aluno.nome, "Maria");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 9.0;
    aluno.pibic = 1;

    insereNaListaCircular(&l1, &aluno);

    printf("#######################################\n");
    mostraListaCircular(&l1);

    strcpy(aluno.nome, "Joao");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 7.0;
    aluno.pibic = 0;

    insereNaListaCircular(&l1, &aluno);

    printf("#######################################\n");
    mostraListaCircular(&l1);

    strcpy(aluno.nome, "Ana");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 10.0;
    aluno.pibic = 0;

    insereNaListaCircular(&l1, &aluno);

    printf("#######################################\n");
    mostraListaCircular(&l1);

    strcpy(aluno.nome, "Ganimedes");
    strcpy(aluno.curso, "Matematica");
    aluno.coeficienteRendimento = 9.0;
    aluno.pibic = 0;

    insereNaListaCircular(&l1, &aluno);

    printf("#######################################\n");
    mostraListaCircular(&l1);

    for(int i = 0; i < 5; i++) {
        proximoDaVez(&l1);
        printf("#######################################\n");
        mostraListaCircular(&l1);
        fgetc(stdin);
    }

    return 0;
}