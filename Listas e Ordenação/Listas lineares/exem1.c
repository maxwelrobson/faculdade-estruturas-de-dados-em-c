#include <stdio.h>
#include <stdlib.h>

void main()
{
    // 1. Alocando a memória inicial
    // "Ei, me arranja um espaço na memória para guardar 3 números do tipo inteiro (int)".
    int *numeros = (int *)malloc(3 * sizeof(int));

    // 2. Preenchendo a lista
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;

    // 3. Realocando a memória para expandir a lista
    //"Ei, sistema, lembra daquele bloco de memória para 3 inteiros? Eu preciso que ele agora tenha espaço para 5 inteiros".
    numeros = (int *)realloc(numeros, 5 * sizeof(int));

    // 4. Adicionando os novos valores
    numeros[3] = 40;
    numeros[4] = 50;
}
