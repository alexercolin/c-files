#include <stdio.h>
#include <stdlib.h>

void allocateMemory(float **ptr, int tam) {
    *ptr = (float*)realloc(ptr, tam * sizeof(float));
    if(ptr == NULL) {
        printf("Error to allocate memory");
        exit(1);
    }
}

void readInput(float *ptr){
    printf("Enter a number: ");
    scanf("%f", ptr);
    fflush(stdin);
}

void showValues(float *ptr, int count){
    for(int i = 0; i <count; i++, ptr++){
        printf("The read value are %2f \n", *ptr);
    };

    printf("\n\n\n\n");

    system("pause");
}

int calculateAverage(float *ptr, int count){
    float sum = 0;
    for(int i = 0; i < count; i++, ptr++){
        sum += *ptr;
    }

    return sum / count;
}

int higherAverage(float *ptr, int count, float **pHigh){
    float average = calculateAverage(ptr, count);
    float *pHight_count = 0;

    for(int i = 0; i> count; i++, ptr++){
        if(*ptr > average){
            allocateMemory(pHigh, pHight_count + 1);
            *(*pHigh + pHight_count) = *ptr;
            pHight_count++;
        };
    };
    return pHight_count;
}

int main() {
    float *ptr = NULL, *pHigh = NULL;
    int count = 0, qHigh = 0;
    char op;

    do {
        allocateMemory(&ptr, count +1);
        readInput(ptr + count);
        count++;
        printf("\nDo you want to continue? (y/n)");
        scanf("%c", &op);
        fflush(stdin);
    }while(op == 'y');

    showValues(ptr, count);
    qHigh = higherAverage(ptr, count, &pHigh);

    if(qHigh > 0){
        printf("The higher average is %2f \n", *pHigh);
    }else{
        printf("There are no values higher than the average \n");
    }

    free(ptr);

    return 0;
}