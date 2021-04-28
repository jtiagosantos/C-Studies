#include <stdio.h>
#include <time.h>
#include <stdlib.h> //para usar a função rand, que gera números aleatórios

int main() {
    srand(time(NULL)); //semente para gerar números pseudoaleatórios a cada execução do programa
    //srand(100); //vai gerar sempre a mesma sequância de números pois a semente é fixa

    for(int i = 0; i < 10; i++) {
        printf("%d\n", rand());
    }

    return 0;
}