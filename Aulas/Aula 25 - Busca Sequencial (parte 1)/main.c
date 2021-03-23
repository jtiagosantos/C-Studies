#include <stdio.h>

//Faça uma função que receba como parâmetro um vetor de
//números reais e uma chave de busca. A função deve retornar 
//verdadeiro (qualquer valor diferente de zero) caso a chave
//ocorra no vetor, e falso (zero) caso contrário.

int buscarSequencialmente(float vetor[], unsigned tamanhoVetor, float chave) {
    for(unsigned i=0; i<tamanhoVetor; i++) {
        if(vetor[i] == chave) {
            return 1;
        }
    }
    return 0;
} 

int main() {
    float vetor[4]={4.5, 3.99, 1.5, 9.1};
    float chave; 

    printf("Informe a chave de busca: ");
    scanf("%f%*c", &chave);

    if(buscarSequencialmente(vetor, 4, chave)) {
        printf("Chave encontrada no vetor!");
    }else {
        printf("Chave nao encontrada no vetor!");
    }
    
    return 0;
}