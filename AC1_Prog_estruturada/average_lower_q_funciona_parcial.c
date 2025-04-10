#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int **arr, int counter) {
    *arr = (int*)realloc(*arr, counter * sizeof(int));

    if(arr == NULL) {
        printf("Error to allocate memory");
        exit(1);
    }
}

void showValues(int *arr, int counter){
    for(int i = 0; i < counter; i++, arr++){
        printf("\nO valor lido é %i \n", *arr);
    }
}

void showLowerValues(int *arr, int counter){
    for(int i = 0; i < counter; i++, arr++){
        printf("\nValor menor que a média é %i \n", *arr);
    }
}

int calculateAverage(int *arr, int counter) {
    int sum = 0;
    for(int i = 0; i < counter; i++, arr++){
        sum +=*arr;
    }

    return sum/counter;
}

void findLowerValues(int *arr, int *arr_lower, int average, int counter){
    for(int i = 0; i < counter; i++, arr++){
        if(*arr < average){
            arr_lower = arr;
            arr_lower++;
        };
    };

    arr_lower--;

    showLowerValues(arr_lower, counter - 1);
}

int main() {
    int *inputArr = NULL, *lowerValues = NULL;
    int counter = 0;
    int average = 0;
    char answer;

    do{
        allocateMemory(&inputArr, counter + 1);
        printf("Digite um valor inteiro\n");
        scanf("%i", inputArr + counter);
        fflush(stdin);

        counter++;

        printf("Gostaria de continuar ? (Y/N)\n");
        scanf("%c", &answer);
        fflush(stdin);
    } while(answer == 'Y');

    showValues(inputArr, counter);

    average = calculateAverage(inputArr, counter);

    printf("\n\nA média dos valores é: %i \n", average);

    findLowerValues(inputArr, lowerValues, average, counter);

    return 0;
}