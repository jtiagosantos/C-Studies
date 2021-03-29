#include <stdio.h>

int main() {
    int n1, n2, n3;

    printf("Entre com o valor de n1: ");
    scanf("%d%*c", &n1);
    printf("Entre com o valor de n2: ");
    scanf("%d%*c", &n2);
    printf("Entre com o valor de n3: ");
    scanf("%d%*c", &n3);

    if(n1>n2 && n1>n3) {
        printf("Maior eh o %d\n", n1);
    }else {
        if(n2>n3) {
            printf("Maior eh o %d\n", n2);
        }else {
            printf("Maior eh o %d\n", n3);
        }
    }

    return 0;
}