#include <stdio.h>

int main() {
    int xInt, yInt;
    char xChar, yChar;
    unsigned char xUnnsignedChar, yUnsignedChar;
    unsigned int xUnsignedInt, yUnsignedInt;
    float xFloat, yFloat;
    double xDouble, yDouble;

    xInt = 65;

    printf("%c\n", xInt); //conversão implícita de inteiro para char no printf

    xChar = xInt;

    printf("%d\n", xChar); //conversão implícita do chart para int (deveria ser %hhd)

    xInt = 3;
    yInt = 2;

    xFloat = xInt / yInt;

    printf("%.2f\n", xFloat);

    xFloat = xInt / (float) yInt; //cast - conversão forçada

    printf("%.2f\n", xFloat);

    return 0;
}