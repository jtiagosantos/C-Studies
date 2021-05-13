#include <stdio.h>

#define N 3

void multiplicaMatriz(int c[N][N], int a[N][N], int b[N][N]) {
    int x, y, z;

    for(x = 0; x < N; x++) {
        for(y = 0; y < N; y++) {
            //Calcular o produto interno da linha x de A com coluna y de B
            c[x][y] = 0;
            for(z = 0; z < N; z++) {
                c[x][y] += a[x][z] * b[z][y];
            }
        }
    }
}

int main() {


    return 0;
}