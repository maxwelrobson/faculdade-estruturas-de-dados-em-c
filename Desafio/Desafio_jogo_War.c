#include <stdio.h>
#include <string.h>

//Constantes Globais
#define MAX_TERRITORIO 5
#define TAM_STRING 100

struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios[MAX_TERRITORIO];
    int totalTerritorios = 0;

    printf("==================================\n");
    printf("WAR ESTRUTURADO - CADASTRO INICIAL\n");
    printf("==================================\n");

    printf("\nVamos cadastrar os 5 territorios iniciais do nosso mundo\n");

    
    for (int i = 0; i < MAX_TERRITORIO; i++)
    {
        printf("--- Cadastro Territorio %d ---\n", i+1);
        printf("Nome do Territorio: ");
        fgets(territorios[totalTerritorios].nome, TAM_STRING, stdin);

        printf("Cor do Exercito: ");
        fgets(territorios[totalTerritorios].cor, TAM_STRING, stdin);

        territorios[totalTerritorios].nome[strcspn(territorios[totalTerritorios].nome, "\n")] = '\0';
        territorios[totalTerritorios].cor[strcspn(territorios[totalTerritorios].cor, "\n")] = '\0';

        printf("Numero de Tropas: \n");
        scanf("%d", &territorios[totalTerritorios].tropas);
        limparBufferEntrada();

        totalTerritorios++;
    }

    printf("\nCadastro inicial concluido com sucesso!");
}
