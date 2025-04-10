#include <stdio.h>
#include <stdlib.h>

int main () {
    int vet[10] = {0 ,1, 2, 3, 4, 5, 6, 7, 8, 9};
    int counter = 0;

    int endValue = sizeof(vet) / sizeof(vet[0]) -1;

    while(counter < endValue){

        int aux = vet[0];
        vet[counter] = vet[endValue];
        vet[endValue] = aux;

        endValue--;
        counter ++;
    }

    printf("Vetor invertido: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");


    return 0;
}