#include <stdio.h>

long fatorial(int n) {
    if(n > 1) {
        return fatorial(n-1) * n;
    }
    return 1;
    
}

int main() {
    int num;

    scanf("%d%*c", &num);
    printf("%lld", fatorial(num));

    return 0;
}