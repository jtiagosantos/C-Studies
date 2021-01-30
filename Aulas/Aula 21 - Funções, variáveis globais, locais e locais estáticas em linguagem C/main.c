#include <stdio.h>

//Uma variriável é global quando é criada fora de qualquer função

unsigned x; // variável global

int funcaoDeTeste(int valor) {
    //int x; -> x dentro da função é variável local
    x = 10 + valor; // o x local que é alterado; o global continua com o mesmo valor
    return x;
}

/*
Quando uma função usa uma variável e esta não é local, então a fução usa a variável global.
Assim, a variável global tem seu valor alterado caso assim seja feito.
Agora, quando tem duas varáveis de mesmo nome, uma local e a outra global, a função
prioriza a variável local.
*/

int main() {
    int z;
    x = 5;

    z = funcaoDeTeste(3);

    printf("Valor de x: %d\nValor de z: %d\n", x, z);
    
    return 0;
}