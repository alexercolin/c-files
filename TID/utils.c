#include <stdio.h>
#include "header.h"

void print_message(struct Values *val) {
    printf("The number you typed: %i\n", val->value);
} 