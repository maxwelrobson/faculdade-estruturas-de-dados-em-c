// Encadeada simples

struct No
{
    int dado;   // Onde guardamos a informação
    struct No *proximo; // A "seta" que aponta para o próximo nó
};

// Duplamente encadeada

struct No
{
    int dado;
    struct No* proximo;
    struct No* anterior;
};

