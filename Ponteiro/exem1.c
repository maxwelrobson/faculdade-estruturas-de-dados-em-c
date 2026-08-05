#include <stdio.h>

int main () {
    int x = 10;
    int *p = &x;

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", &x);
    printf("Conteudo de p (o endereco): %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    *p = 20; //Modificando o valor através do ponteiro
    printf("Novo valor de x: %d\n", x); //Vai imptimir 20!
    printf("Conteudo de p (o endereco): %p\n", p);

    return 0;
}