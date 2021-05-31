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

int buscaElementoNaLista(tipoLista *pLista, char *nome, tipoAluno *retorno) {
    tipoNo *aux;

    aux = pLista->prim;

    while(aux) { //aux != NULL
        if(!strcmp(nome, aux->dado.nome)) {
            *retorno = aux->dado;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

tipoAluno * buscaElementoNaListaV2(tipoLista *pLista, char *nome) {
    tipoNo *aux;

    aux = pLista->prim;

    while(aux) { //aux != NULL
        if(!strcmp(nome, aux->dado.nome)) {
            return &(aux->dado);
        }
        aux = aux->prox;
    }
    return NULL;
}

void mostraAluno(tipoAluno pt) {
    printf("Nome: %s\n", pt.nome);
    printf("Curso: %s\n", pt.curso);
    printf("Coeficiente: %.2f\n", pt.coeficienteRendimento);
    if(pt.pibic == 1) {
        printf("Eh aluno de PIBIC\n");
    }else {
        printf("Nao eh aluno de PIBIC\n");
    }
}

int main() {
    tipoAluno aluno;
    tipoLista l1;
    tipoAluno *pAluno;
    char nome[30];

    printf("Informe um nome para buscar: ");
    scanf("%[^\n]%*c", nome);

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

    strcpy(aluno.nome, "Joao");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 7.0;
    aluno.pibic = 0;
    
    insereElementoLista(&l1, &aluno);

    pAluno = buscaElementoNaListaV2(&l1, nome);

    if(pAluno) {
        printf("Encontrado na Lista:\n");
        mostraAluno(*pAluno);
    }else {
        printf("Nao encontrou!\n");
    }

    return 0;
}