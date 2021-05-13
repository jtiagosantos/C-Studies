#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

//quando passa matriz para uma função, é obrigatório colocar as dimensões da matriz
void zeraMatriz(int m[LINHAS][COLUNAS]) {
    int lin, col;

    for(lin = 0; lin < LINHAS; lin++) {
        for(col = 0; col < COLUNAS; col++) {
            m[lin][col] = 0;
        }
    }
}

int main() {
    int mat[LINHAS][COLUNAS]; //[linhas][colunas]

    zeraMatriz(mat);

    return 0;
}