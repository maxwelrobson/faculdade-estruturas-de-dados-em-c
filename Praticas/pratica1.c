#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes Globais
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

//Definição de Estrutura
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função Principal

int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));

    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        return 1;
    }
    

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    // Laço principal do menu
    do
    {
        printf("=======================================\n");
        printf(" BIBLIOTECA - PARTE 1\n");
        printf("=======================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprestimo\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");

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

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf("Digite a edicao: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada();

                // Ao cadastrar, o livro automaticamente se torna disponível.
                biblioteca[totalLivros].disponivel = 1;

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
                        //Mostra o status de disponibilidade.
                        printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
                    }
                    printf("----------------------------\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 3:
                printf("Realizar Emprestimo\n");

                if (totalEmprestimos >= MAX_EMPRESTIMOS)
                {
                    printf("Limite de emprestimos atingido!\n");
                } else {
                    printf("Livros disponiveis:\n");
                    int disponiveis = 0;
                    for (int i = 0; i < totalLivros; i++)
                    {
                        if (biblioteca[i].disponivel)
                        {
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            disponiveis++;
                        }                      
                    }

                    if (disponiveis == 0)
                    {
                        printf("Nenhum livro disponivel para emprestimo\n");
                    } else {
                        printf("\nDigite o numero do livro que deseja emprestar: ");
                        int numLivro;
                        scanf("%d", &numLivro);
                        limparBufferEntrada();

                        int indice = numLivro - 1;

                        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel)
                        {
                            printf("Digite o nome do usuario que esta pegando o livro: ");
                            fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                            emprestimos[totalEmprestimos].indiceLivro = indice;

                            biblioteca[indice].disponivel = 0;

                            totalEmprestimos++;
                            printf("\nEmprestimo realizado com sucesso!\n");
                        } else {
                            printf("\nNumero de livro invalido ou livro insiponivel\n");
                        }
                    }
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;


            case 4:
                printf("Lista de Emprestimos\n\n");
                if (totalEmprestimos == 0)
                {
                    printf("Nenhum emprestimo realizado.\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++)
                    //Usa o índice armazenado no empréstimo para buscar o nome do livro.
                    {
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("EMPRESTIMO %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro]. nome);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                    }
                    printf("--------------------------------\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                

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


    // LIBERAÇÃO DA MEMÓRIA
    // Antes de terminar, e ESSENCIAL liberar a memoria que foi alocada dinamicamente.
    // Isso evita "memory leaks" (vazamentos de memória).
    free(biblioteca);
    free(emprestimos);

    printf("Memoria liberado com sucesso.\n");

    return 0;
}
