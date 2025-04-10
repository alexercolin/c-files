#include <stdio.h>
#include <stdlib.h>

void evenOrOdd(int *value) {
    if(*value % 2 == 0) {
        printf("É par \n");
    } else {
        printf("É impar \n");
    }
}

int main () {
    int value;

    printf("Digite um número inteiro e pressione enter: \n");

    scanf("%i", &value);

    evenOrOdd(&value);

    return 0;
}