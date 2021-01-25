#include <stdio.h>
#include <string.h> //include necessário para utilizar funções em strings

int main() {
    char string1[100], string2[50];
    unsigned char tamString;

    printf("Entre com uma string: ");
    scanf("%[^\n]%*c", string1);
    printf("Entre com outra string: ");
    scanf("%[^\n]%*c", string2);

    //Retorna o tamanho de uma string
    tamString = strlen(string1);
    printf("O tamanho da string 1 eh: %d\n", tamString);
    printf("O tamanho da string 2 eh: %d\n", strlen(string2)); 

    //Retorna 0 caso duas strings sejam iguais
    /*Se retornar um valor menor que zero, quer dizer que a string1 vem antes
    da strings (na ordem alfabética). Se retornar um valor maior que 0, então
    a string2 vem antes que a string2 (na ordem alfabética)*/
    if(strcmp(string1, string2) == 0) {
        printf("As duas strings sao iguais\n");
    }else if(strcmp(string1, string2) < 0) {
        printf("A string %s vem antes da string %s, em ordem alfabetica.\n", string1, string2);
    }else {
        printf("A string %s vem depois da string %s, em ordem alfabetica.\n", string1, string2);
    }
    //Pode usar também strcasecmp, caso queira considerar maiúsculas e minúsculas iguais
    
    //Copiar uma string para outra string
    //strcpy(string1, string2); //copiar a string2 para a string1
    //strncpy(string1, string2, 3); //vai copiar só três caracteres


    //Concatenar strings
    printf("%s\n", strcat(string1, string2));

    return 0;
}