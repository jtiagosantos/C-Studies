#include <stdio.h>

void mergeSort(float v[], float vaux[], unsigned inicio, unsigned fim) {
    unsigned meio, i, j, k;

    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(v, vaux, inicio, meio);
        mergeSort(v, vaux, meio+1, fim);

        //Intercalação
        i = inicio;
        k = inicio;
        j = meio+1;

        while(i <= meio && j <= fim) {
            if(v[i] < v[j]) { vaux[k] = v[i]; i++; }
            else { vaux[k] = v[j]; j++; }
            k++;
        }

        while(i <= meio) { vaux[k] = v[i]; i++; k++; }
        while(j <= fim) { vaux[k] = v[j]; j++; k++; }

        for(k = inicio; k <= fim; k++) {
            v[k] = vaux[k];
        }
    }
}

void mostrarVetor(float v[], int tamVet) {
    for(int i = 0; i < tamVet; i++) {
        printf("[%d] = %.1f\n", i, v[i]);
    }
}

int main() {
    float vector[11] = {499.32, 7.9, 5.4, 114.99, 44.09, 36.11, 76.5, 91.0, 2.1, 19.32, 237.45 };
    float aux[11];

    mergeSort(vector, aux, 0, 10);
    mostrarVetor(vector, 11);

    return 0;
}