#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes Globais
#define MAX_LIVROS 50
#define TAM_STRING 100

//Definição de Estrutura
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função Principal

int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // Laço principal do menu
    do
    {
        printf("=======================================\n");
        printf(" BIBLIOTECA - PARTE 1\n");
        printf("=======================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: \n");

        // Lê a opção do usuário    
        scanf("%d", &opcao);
        limparBufferEntrada();  //Limpa o '\n' deixado pelo scanf.

        //Processamento da opção
        switch (opcao)
        {
        case 1:
            printf("Cadastro de novo livro\n");

            if (totalLivros < MAX_LIVROS)
            {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o nome do autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite o nome da editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")];
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")];
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")];

                printf("Digite a edicao: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada();

                totalLivros++;

                printf("\nLivro cadastrado com sucesso\n");
            } else {
                printf("Biblioteca cheia! Nao e possivel cadastrar mais livros\n");
            }
            break;

            case 2:
                printf("Lista de Livros cadastrados\n\n");

                if (totalLivros == 0)
                {
                    printf("Nenhum livro cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++)
                    {
                        printf("---------------------------\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                    }
                    printf("----------------------------\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("\nsaindo do sistema...\n");
                break;

        default:
            printf("\nOpcao invalida! Tente novamente. \n");
            printf("\nPressione Enter para continuar ... ");
            getchar();
            break;
        }
    } while (opcao != 0);
    
}
