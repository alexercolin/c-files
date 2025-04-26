#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void add(Person **list, char name[50])
{
    Person *new_node = (Person *)malloc(sizeof(Person));
    if (new_node == NULL)
    {
        printf("Error to allocate memory");
        exit(1);
    }

    strcpy(new_node->name, name);
    new_node->next = *list;

    *list = new_node;
}

void print(Person *list)
{
    Person *current = list;
    while (current != NULL)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void rem(Person **list, char name[50])
{
    if (strcmp((*list)->name, name) == 0)
    {
        Person *temp = *list;
        *list = (*list)->next;
        free(temp);
        return;
    }

    Person *current = *list;
    Person *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        prev->next = current->next;
        free(current);
    }
}
