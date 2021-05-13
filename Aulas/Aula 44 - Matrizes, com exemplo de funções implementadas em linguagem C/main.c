#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3
#define N 3

int identidade(int m[N][N]) {
    int lin, col;

    for(lin = 0; lin < N; lin++) {
        for(col = 0; col < N; col++) {
            if(lin == col && m[lin][col] != 1) {
                return 0;
            }else if(lin != col && m[lin][col] != 0){
                return 0;
            }
        }
    }
    return 1;
}

void preencheMatriz(int m[LINHAS][COLUNAS]) {
    int lin, col;

    for(lin = 0; lin < LINHAS; lin++) {
        for(col = 0; col < COLUNAS; col++) {
            m[lin][col] = rand()%100; //números pseudoaleatórios dem 0 a 100
        }
    }
}

void mostraMatrizes(int m[LINHAS][COLUNAS]) {
    int lin, col;

    for(lin = 0; lin < LINHAS; lin++) {
        for(col = 0; col < COLUNAS; col++) {
            printf("%03d ", m[lin][col]);
        }
        printf("\n");
    }
}

void somaMatrizes(int res[LINHAS][COLUNAS], int a[LINHAS][COLUNAS], int b[LINHAS][COLUNAS]) {
    int lin, col;

    for(lin = 0; lin < LINHAS; lin++) {
        for(col = 0; col < COLUNAS; col++) {
            res[lin][col] = a[lin][col] + b[lin][col];
        }
    }
}

void zeraMatriz(int m[LINHAS][COLUNAS]) {
    int lin, col;

    for(lin = 0; lin < LINHAS; lin++) {
        for(col = 0; col < COLUNAS; col++) {
            m[lin][col] = 0;
        }
    }
}

int main() {
    int mat1[LINHAS][COLUNAS], mat2[LINHAS][COLUNAS], r[LINHAS][COLUNAS];

    preencheMatriz(mat1);
    preencheMatriz(mat2);
    printf("Matriz 1:\n");
    mostraMatrizes(mat1);
    printf("\nMatriz:\n");
    mostraMatrizes(mat2);
    somaMatrizes(r, mat1, mat2);
    printf("\nSoma das matrizes:\n");
    mostraMatrizes(r);

    return 0;
}