#include <stdio.h>
#include <stdlib.h> //necessário para utilizar as funções malloc e free

int main() {
    int *vetor, tam = 5;

    vetor = (int*) malloc(tam * sizeof(int)); //malloc(quantidade de bytes a serem alocados)

    vetor[0] = 123;
    vetor[1] = 454;
    vetor[2] = 9;
    vetor[3] = 567;
    vetor[4] = 42;

    for(int i = 0; i < tam; i++) {
        printf("%d\n", vetor[i]);
    }

    free(vetor); //necessário para liberar(desalocar) a memória que foi alocada antes
    //Função obrigatória para que não ocorra vazamento de memória

    return 0;
}