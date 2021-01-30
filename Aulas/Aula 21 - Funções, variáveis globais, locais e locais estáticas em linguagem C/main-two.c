#include <stdio.h>

unsigned x; 

//uma vavriável mantém seu valor por todo o programa, como uma variável global

int funcaoDeTeste() {
    //int cont = 0; -> aqui a variável sempre receberia zero quando a função fosse chamada
    static int cont = 0; //esse trecho só é chamado na primeira vez em que a função é chamada
    cont++; //cont sofre incremento e mantém o seu valor
    return cont;
}

/*
Em uma função, a diferenção entre uma variável simples (sem static) e uma variável static é que
a primeira é criada e destruída em tempo de execução da função. Por outro lado, uma variável
static é criada na função mas não é destruída, permanece na memória.
*/

int main() {
    int z;
    x = 5;

    z = funcaoDeTeste();
    z = funcaoDeTeste();
    z = funcaoDeTeste();

    printf("Valor de x: %d\nValor de z: %d\n", x, z);
    
    return 0;
}