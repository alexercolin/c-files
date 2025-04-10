#include <stdio.h>
#include <stdlib.h>


int main () {
    int size;
    int *vet;

    printf("Digite a quantidade de elementos de um vetor: \n");

    scanf("%i", &size);

    vet = (int*)malloc(size * sizeof(int));

    if (vet == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os valores do vetor: \n");

    for (int  i = 0; i < size; i++){
        printf("vetor[%i] =  ", i);
        scanf("%d", &vet[i]);
    }

    printf("Os elementos do vetor e seu respectivo endereco de memoria: \n");

    for (int  i = 0; i < size; i++){

        printf("vetor[%i] = %i  \n", i, vet[i]);
        printf("vetor[%i] = %p  \n", i, &vet[i]);
    }

    return 0;
}