#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoAluno {
	char nome[30];
	char pibic;
	char curso[30];
	float coeficienteRendimento;
} tipoAluno;

typedef struct tipoNo {
	tipoAluno dado;
	struct tipoNo *prox;
} tipoNo;

typedef struct tipoFila {
	tipoNo *prim;
	tipoNo *ult;
} tipoFila;

void mostraAluno(tipoAluno al) {
	printf("Nome: %s\n", al.nome);
	printf("Curso: %s\n", al.curso);
	printf("Coeficiente de Rendimento: %.2lf\n", al.coeficienteRendimento);
	if(al.pibic) {
		printf("Eh aluno de PIBIC\n");
	}else {
		printf("Nao eh aluno de PIBIC\n");
	}
}

void mostraFila(tipoFila *pLista) {
	tipoNo *aux;

	aux = pLista->prim;

	while(aux) {
		mostraAluno(aux->dado);
		aux = aux->prox;
	}
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

}

void criaFila(tipoFila *pLista) {
	pLista->prim = NULL;
	pLista->ult = NULL;
}

int removeDaFila(tipoFila *pLista, tipoAluno *res) {
    tipoNo *tmp;
    
    tmp = pLista->prim;
    if(tmp) {
        pLista->prim = tmp->prox;
        if(pLista->prim == NULL) { pLista->ult = NULL; }
        *res = tmp->dado;
        free(tmp);
        return 1;
    }
    return 0;
}

int main() {

    return 0;
}