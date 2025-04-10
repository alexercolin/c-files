#include <stdio.h>
#include <stdlib.h>

int main () {
    int vet[5] = {1, 2, 3, 4, 5};
    int sum = 0, i;

    for(i = 0; i < 5; i++){
        sum+=vet[i];
    }

    printf("Soma do vetor: %i \n", sum);
    printf("Endereco de memoria do vetor: %p\n", vet);
    printf("Endereco de memoria do vetor no terceiro elemento: %p\n", &vet[2]);
    printf("Tamanho do bloco de memoria reservado para o vetor: %lu bytes\n", sizeof(vet));
    printf("Tamanho de memoria reservado para o primeiro valor do vetor: %lu bytes\n", sizeof(vet[0]));

    return 0;

}