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

typedef struct tipoFila {
    struct tipoNo *prim; //ponteiro para variável do tipoNo
    struct tipoNo *ult;
    unsigned numElementos;
} tipoFila;

void criaFila(tipoFila *pLista) {
    pLista->prim = NULL;
    pLista->ult = NULL;
    pLista->numElementos = 0;
}

void insereNaFila(tipoFila *pLista, tipoAluno *al) {
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *al;
    aux->prox = NULL;
    if(pLista->ult) {
        pLista->ult->prox = aux;
    }else {
        pLista->prim = aux;
    }
    pLista->ult = aux;

    pLista->numElementos++;
}

float mediaCoeficiente(tipoFila *pLista) {
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

void mostraFila(tipoFila *pt) {
    for(int i = 0; i < pt->numElementos; i++) {
        printf("Nome: %s\n", pt[i].prim->dado.nome);
        printf("Curso: %s\n", pt[i].prim->dado.curso);
        printf("Coeficiente: %.2f\n", pt[i].prim->dado.coeficienteRendimento);
        if(pt[i].prim->dado.pibic) {
            printf("Eh aluno de PIBIC\n");
        }else {
            printf("Nao eh aluno de PIBIC\n");
        }
    }
}

//Remove o primeiro elemento da fila

//testa condição se a lista estiver vazia
unsigned removeDaFila(tipoFila *pLista, tipoAluno *res) {
    tipoNo *tmp;
    tmp = pLista->prim;
    if(tmp) {
        pLista->prim = tmp->prox;
        if(pLista->prim == NULL) { pLista->ult = NULL; }
        *res = tmp->dado;
        free(tmp);
        pLista->numElementos--;
        return 1;
    }

    return 0;
}

unsigned buscaElementoNaFila(tipoFila *pLista, char *nome, tipoAluno *retorno) {
    tipoNo *aux;
    unsigned pos = 0;
    aux = pLista->prim;

    while(aux) {
        pos++;
        if(!strcmp(nome, aux->dado.nome)) {
            *retorno = aux->dado;
            return pos;
        }
        aux = aux->prox;
    }
    return 0;
}

int main() {
    tipoAluno aluno;
    tipoFila l1;
    tipoAluno *pAluno; 
    char nome[30];

    criaFila(&l1);

    strcpy(aluno.nome, "Jose");
    strcpy(aluno.curso, "Ciencia da Computacao");
    aluno.coeficienteRendimento = 8.0;
    aluno.pibic = 1;

    insereNaFila(&l1, &aluno);

    strcpy(aluno.nome, "Maria");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 9.0;
    aluno.pibic = 1;
    
    insereNaFila(&l1, &aluno);

    strcpy(aluno.nome, "Joao");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 7.0;
    aluno.pibic = 0;
    
    insereNaFila(&l1, &aluno);

    strcpy(aluno.nome, "Ganimedes");
    strcpy(aluno.curso, "Engenharia da Computacao");
    aluno.coeficienteRendimento = 6.5;
    aluno.pibic = 0;

    mostraFila(&l1);

    printf("Informe um nome para buscar: "); 
    scanf("%[^\n]%*c", nome);

    if(removeDaFila(&l1, nome)) {
        printf("Elemento removido com sucesso\n");
    }else {
        printf("Nao removi o elemento porque nao encontrei\n");
    }

    mostraFila(&l1);

    return 0;
}