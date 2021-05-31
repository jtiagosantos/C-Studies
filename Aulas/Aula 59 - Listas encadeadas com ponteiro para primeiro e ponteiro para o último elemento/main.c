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
    struct tipoNo *ult;
    unsigned numElementos;
} tipoLista;

void criaLista(tipoLista *pLista) {
    pLista->prim = NULL;
    pLista->ult = NULL;
    pLista->numElementos = 0;
}

void insereElementoInicioLista(tipoLista *pLista, tipoAluno *al) {
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *al;
    aux->prox = pLista->prim;
    if(pLista->prim == NULL) {
        pLista->ult = aux;
    }
    pLista->prim = aux;

    pLista->numElementos++;
}

void insereElementoFinalLista(tipoLista *pLista, tipoAluno *al) {
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

int removeElementoDaLista(tipoLista *pLista, char *nome) {
    tipoNo *aux, *tmp;

    if(pLista->prim) {
        if(!strcmp(nome, pLista->prim->dado.nome)) {
            tmp = pLista->prim;
            pLista->prim = tmp->prox;
            if(pLista->prim == NULL) {
                pLista->ult = NULL;
            }
            free(tmp);
            pLista->numElementos--;
            return 1;
        }
        aux = pLista->prim;
        while(aux->prox) { 
            if(!strcmp(nome, aux->prox->dado.nome)) {
                tmp = aux->prox;
                if(tmp == pLista->ult) {
                    pLista->ult = aux;
                }
                aux->prox = tmp->prox;
                free(tmp);
                pLista->numElementos--;
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

void mostraLista(tipoLista *pt) {
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

int main() {
    tipoAluno aluno;
    tipoLista l1;
    tipoAluno *pAluno;
    char nome[30];

    criaLista(&l1);

    strcpy(aluno.nome, "Jose");
    strcpy(aluno.curso, "Ciencia da Computacao");
    aluno.coeficienteRendimento = 8.0;
    aluno.pibic = 1;

    insereElementoInicioLista(&l1, &aluno);

    strcpy(aluno.nome, "Maria");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 9.0;
    aluno.pibic = 1;
    
    insereElementoInicioLista(&l1, &aluno);

    strcpy(aluno.nome, "Joao");
    strcpy(aluno.curso, "Engenharia de Software");
    aluno.coeficienteRendimento = 7.0;
    aluno.pibic = 0;
    
    insereElementoInicioLista(&l1, &aluno);

    strcpy(aluno.nome, "Ganimedes");
    strcpy(aluno.curso, "Engenharia da Computacao");
    aluno.coeficienteRendimento = 6.5;
    aluno.pibic = 0;

    insereElementoFinalLista(&l1, &aluno);    

    mostraLista(&l1);

    printf("Informe um nome para buscar: ");
    scanf("%[^\n]%*c", nome);

    if(removeElementoDaLista(&l1, nome)) {
        printf("Elemento removido com sucesso\n");
    }else {
        printf("Nao removi o elemento porque nao encontrei\n");
    }

    mostraLista(&l1);

    return 0;
}