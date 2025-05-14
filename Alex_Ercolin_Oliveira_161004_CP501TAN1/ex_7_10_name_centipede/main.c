#include <stdio.h>
#include "header.h"
#include <string.h>

int main()
{
    Person *list = NULL;

    add(&list, "joao");
    add(&list, "alex");
    add(&list, "valentina");
    add(&list, "adriana");

    printf("\nLista \n\n");
    print(list);

    rem(&list, "alex");
    rem(&list, "joao");

    printf("\nLista Atualizada\n\n");

    print(list);

    return 0;
}
