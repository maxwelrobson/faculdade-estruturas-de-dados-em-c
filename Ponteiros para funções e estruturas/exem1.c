#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main () {
    //p é um ponteiro para uma Pessoa
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));

    printf("Digte o nome: ");
    scanf("%s", p->nome);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    printf("%s temm %d anos. \n", p->nome, p->idade);

    free(p);
    return 0;
}