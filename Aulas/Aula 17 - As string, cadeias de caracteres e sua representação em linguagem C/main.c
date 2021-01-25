#include <stdio.h>

int main() {
    /*
    char letra;

    letra = 65;
    printf("%hhd\n", letra); //usa-se hhd para printar numero do tipo char

    printf("%c\n", letra); //usa-se c para printar o valor na tabela ascii

    for(letra=32; letra<127; letra++) {
        printf("%hhd --> %c\n", letra, letra);
    }
    */

    /*
    char nome[100]; //100 = número máximo que nome pode ter de caracteres
    unsigned pos = 0;

    nome[0] = 'J';
    nome[1] = 'o';
    nome[2] = 's';
    nome[3] = 'e';
    nome[4] = ' ';
    nome[5] = 'T';
    nome[6] = 'i';
    nome[7] = 'a';
    nome[8] = 'g';
    nome[9] = 'o';
    nome[10] = 0; // ou '\0_'

    while(nome[pos] != 0) {
        printf("%c", nome[pos]);
        pos++;
    }
    printf("\n");

    //O mesmo resultado, mas de forma mais simples
    printf("%s\n", nome); //%s -> imprime string
    */

    //Leitura de string
    //1º método (letra por letra)
    /*
    char nome[100];
    unsigned cont = 0;
    printf("Entre com um nome: ");

    do {
        scanf("%c", &nome[cont]);
        if(nome[cont] == '\n') { // \n representa a tecla Enter
            nome[cont] = 0;
        }
        cont++;
    }while(nome[cont-1] != 0);

    printf("%s\n", nome);
    */

    //2º método (com scanf)
    /*
    char nome[100];

    printf("Entre com um nome: ");
    scanf("%[^\n]%*c", nome); //[^\n] significa que o scanf vai ler tudo, menos o enter. Assim, 
                              //o scanf para de ler quando for dado enter | ^ sigifica não

    printf("Nome: %s\n", nome);
    */

   //Exemplo
    char nome[100];
    char curso[50];

    printf("Entre com o nome: ");
    scanf("%[^\n]%*c", nome);

    printf("Entre com o curso que esta fazendo: ");
    scanf("%[^\n]%*c", curso);

    printf("%s faz %s.\n", nome, curso);

    return 0;
}