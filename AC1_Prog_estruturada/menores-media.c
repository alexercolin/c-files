#include <stdio.h>
#include <stdlib.h>

void allocate(int **value, int size);
void readValues(int *value);
void showValues(int *value, int size);
int calculateAverage(int *value, int size);
void findValuesLowerThanAverage(int *value, int **lower_value, int size,  int average);

int main() {
    int *input_values = NULL, *lower_values = NULL;
    int size = 0, average;
    char persist;

    do {
        allocate(&input_values, size+1);
        readValues(input_values+size);
        size++;

        printf("Do you want to continue ? (y/n)");
        scanf("%c", &persist);
        fflush(stdin);

    } while (persist == 'y');


    showValues(input_values, size);

    average = calculateAverage(input_values, size);

    printf("Average: %i \n", average);

    findValuesLowerThanAverage(input_values, &lower_values, size, average);

    return 0;
}

void allocate(int **value, int size) {
    *value = (int*)realloc(*value, size * sizeof(int));

    if(value == NULL){
        printf("Error to allocate memory");
        exit(1);
    }
}

void readValues(int *value) {
    printf("\nNumero:");
    scanf("%i", value);
    fflush(stdin);
};
 
void showValues(int *value, int size) {
    for(int i = 0; i < size; i++, value++){
        printf("Valor[%i] = %i \n", i, *value);
    }
}

int calculateAverage(int *value, int size) {
    int sum = 0, i;

    for(i = 0; i < size; i++, value++){
        sum+=*value;
    }
    return sum / size;

}

void findValuesLowerThanAverage(int *value, int **lower_value, int size, int average) {
    int lower_size = 0;
    
    for(int i = 0; i < size; i++, value++){
        if(*value < average){
            allocate(lower_value, lower_size+1);
            *(*lower_value+lower_size) = *value;
            lower_size++;
        }
    }

    showValues(*lower_value, lower_size);
}

