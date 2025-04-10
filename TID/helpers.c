#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void read_values(struct Values *val) {
    printf("Please type a number\n");
    scanf("%i", &(val->value));
    fflush(stdin);
}

void allocate(struct Values **val) {
    *val = (struct Values*)realloc(*val, sizeof(struct Values));
    if(*val == NULL) {
        printf("Error to allocate memory");
        exit(1);
    };
}