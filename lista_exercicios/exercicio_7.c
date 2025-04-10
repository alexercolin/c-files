#include <stdio.h>
#include <stdlib.h>

int main () {
    int value, *p_value;

    value = 97;
    p_value = &value;

    printf("Endereco de memória do ponteiro: %p \n", &p_value);
    printf("Endereco de memória da variavel: %p \n", &value);
    printf("Valor da variável: %i \n", value);
    return 0;
}