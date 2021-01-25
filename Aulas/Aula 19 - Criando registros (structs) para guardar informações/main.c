#include <stdio.h>

//Ao cirar um struct, cria-se um novo tipo.
//Ao criar um struct fora de alguma função, ele fica com escopo global

/*
struct tipoFuncionario {
    char nome[30]; //campo
    float salario;
    char funcao[20];
    char setor[30];
};
*/

//Usando struct dentro de outro struct
struct tipoEspecieDeArvore {
    char nomeCientifico[30];
    char nomePopular[30];
    float alturaMaximaConhecida;
};

struct tipoArvoreCatalogada {
    struct tipoEspecieDeArvore especie;
    unsigned short int idade;
    float altura;
    float diametroDoTronco;
};

int main() { 
    //Como criar um struct significa criar um novo tipo, podemos usar
    //o struct como usaríamos um tipo normal: tipo variável.
    //A única diferença é que tem que colocar a keyword "struct" antes.
    /*
    struct tipoFuncionario x, y;

    //Agora podemos atribuir um dado para cada campo do struct
    //variável.campo desejado do struct

    scanf("%[^\n]%*c", x.nome);
    scanf("%f%*c", &x.salario);

    printf("%s ganha um salario de R$%.2f\n", x.nome, x.salario);
    */

    //Acessando um campo de um struct que está dentro de outro struct
    struct tipoArvoreCatalogada minhaArvore;

    scanf("%[^\n]%*c", minhaArvore.especie.nomeCientifico); //usa-se a notação de ponto
    scanf("%[^\n]%*c", minhaArvore.especie.nomePopular);

    scanf("%d%*c", &minhaArvore.idade);


    //Tirando a necessidade de ter que colocar a keyword "struct" quando for usar o tipo criado.
    //Para isso, basta usar a keyword "typedef";

    //Exemplo:
    typedef struct tipoPessoa {
        char nomeCompleto[30];
        unsigned int idade;
        float peso;
    }tipoPessoa;

    //Usando o struct
    tipoPessoa paulo;

    strcpy(paulo.nomeCompleto, "Paulo Oliveira dos Santos");

    printf("Nome completo de Paulo: %s\n", paulo.nomeCompleto);

    //*Bônus*
    //Acessando o tamanho de bytes do struct
    printf("Tamanho de bytes do struct tipoPessoa: %lu\n", sizeof(tipoPessoa));

    return 0;
}