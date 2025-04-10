#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));

    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    p->idade = 25;
    p->altura = 1.75;
    
    printf("Idade: %d, Altura: %.2f\n", p->idade, p->altura);

    free(p); // Libera a memória
    return 0;
}
