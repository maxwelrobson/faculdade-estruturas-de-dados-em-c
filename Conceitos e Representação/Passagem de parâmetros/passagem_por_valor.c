#include <stdio.h>

void dobrar(int x) {
    x = x * 2;
    printf("Dentro da funcao: %d\n", x);
}

int main() {
    int numero = 5;
    dobrar(numero);
    printf("Fora da funcao: %d", numero );
    return 0;
}