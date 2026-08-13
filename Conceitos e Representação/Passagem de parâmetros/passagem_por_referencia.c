#include <stdio.h>

void dobrar(int* x) {
    *x = (*x) * 2;
}

int main() {
    int numero = 5;
    dobrar(&numero);
    printf("Numero dobrado: %d", numero);
    return 0;
} 