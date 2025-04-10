#include <stdio.h>
#include <stdlib.h>

int calculateFatorial(int value) {
    int fatorial = 1
    while(value != 0) {
        fatorial *= value;
        value--;
    }

    return fatorial;
}

int main() {
    int value = 5;


    printf("Pressione enter para calcular os 10 primeiros numeros da sequencia de Fibonacci\n");
    getchar();


    printf("NFatorial = %i \n", calculateFatorial(value));

    return 0;
}

