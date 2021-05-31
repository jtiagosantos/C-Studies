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

int removeElementoDaLista(tipoLista *pLista, char *nome) {
    tipoNo *aux, *tmp;

    if(pLista->prim) {
        if(!strcmp(nome, pLista->prim->dado.nome)) {
            tmp = pLista->prim;
            pLista->prim = tmp->prox;
            free(tmp);
            return 1;
        }
        aux = pLista->prim;
        while(aux->prox) { 
            if(!strcmp(nome, aux->prox->dado.nome)) {
                tmp = aux->prox;
                aux->prox = tmp->prox;
                free(tmp);
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

float mediaCoeficiente(tipoLista *pLista) {
    tipoNo *aux;
    unsigned cont = 0;
    float soma = 0.0;
    aux = pLista->prim;

    while(aux) {
        soma += aux->dado.coeficienteRendimento;
        cont++;
        aux = aux->prox;
    }
    if(cont) { soma = soma / cont; }

    return soma;
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

    if(removeElementoDaLista(&l1, nome)) {
        printf("Elemento removido com sucesso\n");
    }else {
        printf("Nao removi o elemento porque nao encontrei\n");
    }

    return 0;
}