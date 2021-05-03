#include <stdio.h>

void intercala(float v1[], unsigned tamV1, float v2[], unsigned tamV2, float aux[]) {
    unsigned i = 0, j = 0, k = 0;

    while(i <= tamV1 && j <= tamV2) {
        if(v1[i] < v2[j]) {
            aux[k] = v1[i]; i++;
        }else {
            aux[k] = v2[j]; j++;
        }
        k++;
    }

    while(i < tamV1) { aux[k] = v1[i]; i++; k++; }
    while(j < tamV2) { aux[k] = v1[j]; j++; k++; }
}

int main() {


    return 0;
}