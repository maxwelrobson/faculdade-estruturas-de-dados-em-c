struct No {
    int dado;
    struct No* proximo;
};

//  Insere um novo nó no inicio da lista.
void inserirNoInicio(struct No** inicio, int valor) {

    // 1. Criamos nosso "novo nó" alocando memória para ele.
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    //
    novo->dado = valor;
    novo->proximo = *inicio;
    *inicio = novo;
} 

// Remove o primeiro nó da lista.
void removerDoInicio(struct No** inicio) {
    if (inicio == NULL || *inicio == NULL)
    {
        printf("A lista já está vazia. Nada a remover\n")
        return;
    }

    struct No *noParaRemover = *inicio;
    *inicio = (*inicio)->proximo;
    free(noParaRemover);
}