// Definundo a estrutura para uma Aluno

struct Aluno {
    char nome[50];
    int idade;
    float media;
};

//Usando typedef para criar o tipo Aluno

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

