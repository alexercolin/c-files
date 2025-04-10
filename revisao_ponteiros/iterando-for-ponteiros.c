#include <stdio.h>

int main() {
    int numeros[] = {5, 15, 25, 35, 45};
    int *ptr = numeros;  // Ponteiro apontando para o primeiro elemento

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  // Acessa o valor deslocando o ponteiro
    }

    return 0;
}

#include <stdio.h>

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int *ptr;  // Ponteiro para inteiro

    // Inicializa o ponteiro com o endereço do primeiro elemento
    for (ptr = numeros; ptr < numeros + 5; ptr++) {
        printf("%d ", *ptr);  // Dereferência do ponteiro para obter o valor
    }

    return 0;
}

#include <stdio.h>

int main() {
    char str[] = "Hello";
    char *ptr;

    for (ptr = str; *ptr != '\0'; ptr++) {
        printf("%c ", *ptr);
    }

    return 0;
}
