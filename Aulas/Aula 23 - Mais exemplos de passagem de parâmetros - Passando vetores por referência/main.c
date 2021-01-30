#include <stdio.h>

void f(int x) {
    x = 0;
}

void g(int vet[], int n) { //o vet aqui não recebe o v de fora, apenas uma referência ao endereço de memória
    int cont;

    for(cont=0; cont<n; cont++) {
        vet[cont] = 0;
    }
}

int main() {
    int x = 10;
    int v[3] = {2, 4, 6};

    f(x); //passagem por valor - o valor é copiado para o parâmetro da função
    g(v, 3); //passagem por referência

    //SÓ OS VETORES SÃO PASSADOS POR REFERÊNCIA
    //REFERÊNCIA DE UMA VARIÁVEL = ENDEREÇO DELA

    //Um valor que é passado por valor, não tem seu valor alterado quando ele, passado como
    //parâmetro, sofre alteração na função.

    //Um valor que é passado por referência, quando é alterado na função, tem o seu valor original alterado também.

    printf("%d\n", x);
    
    return 0;
}