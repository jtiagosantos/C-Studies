#include <stdio.h>

/*Função que encontra o menor elemento de um vetor passando como parâmetro
e retorna o valor do menor como resultado.
*/

float menorElementoVetor(float vetor[], unsigned tamanhoVetor) {
    unsigned pos;
    float menor;

    menor = vetor[0];

    for(pos=0; pos<tamanhoVetor; pos++) {
        if(vetor[pos] < menor) {
            menor = vetor[pos];
        }
    }

    return menor;
}

/*Função que encontra o menor elemento de um vetor passando como parâmetro
e retorna o valor do menor como resultado.
*/

float maiorElementoVetor(float vetor[], unsigned tamanhoVetor) {
    unsigned pos;
    float maior;

    maior = vetor[0];

    for(pos=0; pos<tamanhoVetor; pos++) {
        if(vetor[pos] > maior) {
            maior = vetor[pos];
        }
    }

    return maior;
}

/*Função que retorna a média dos valores de um vetor passado como parâmetro*/

float mediaValoresVetor(float vetor[], unsigned tamanhoVetor) {
    unsigned i;
    float media = 0.0;

    for(i=0; i<tamanhoVetor; i++) {
        media += vetor[i];
    }

    media = media / tamanhoVetor;

    return media;
}
//void significa que a função não retornará nada
void mostraVetor(float vetor[], unsigned tamanhoVetor) {
    unsigned pos;

    if(tamanhoVetor == 0) {
        printf("[]\n");
        return; //quando a função é do tipo void, podemos retornar sem colocar nada.
    }

    printf("[");
    for(pos=0; pos<tamanhoVetor; pos++) {
        if(pos != tamanhoVetor - 1) {
            printf("%.2f, ", vetor[pos]);
        }else {
            printf("%.2f]\n", vetor[pos]);
        }
    }
}

int main() {
    float v[4], menor, maior, media;
    float v2[6] = {8.3, 20.5, 17, 1, 0, 12}; //Outra maneira de atribuir valores para um vetor

    v[0] = 5;
    v[1] = 3.7;
    v[2] = 8.4;
    v[3] = 9.5;

    menor = menorElementoVetor(v, 4);
    maior = maiorElementoVetor(v, 4);
    media = mediaValoresVetor(v, 4);
    printf("Maior elemento: %.2f\n", maior);
    printf("Menor elemento: %.2f\n", menor);
    printf("Media dos valores: %.2f\n", media);
    mostraVetor(v, 4);

    printf("----------------------------------\n");

    menor = menorElementoVetor(v2, 6);
    maior = maiorElementoVetor(v2, 6);
    media = mediaValoresVetor(v2, 6);
    printf("Maior elemento: %.2f\n", maior);
    printf("Menor elemento: %.2f\n", menor);
    printf("Media dos valores: %.2f\n", media);
    mostraVetor(v2, 6);

    return 0;
}