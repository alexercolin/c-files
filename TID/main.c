#include <stdio.h>
#include "header.h"


int main() {
    struct Values *entry = NULL;
    printf("Hello, from TID!\n");
    allocate(&entry);
    read_values(entry);
    print_message(entry);
    return 0;
} 