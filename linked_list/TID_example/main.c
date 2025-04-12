#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Lista *lista;

    lista = criar_lista();

    if (vazia(lista))
        printf("Lista vazia!\n");
    else
        printf("Lista NAO vazia!\n");

    lista = inserir_lista(lista, 10);
    lista = inserir_lista(lista, 20);
    lista = inserir_lista(lista, 5);

    printf("Conteúdo da lista:\n");
    imprimir_lista(lista);

    int elemento = 5;
    if (buscar(lista, elemento) == NULL)
        printf("Nao encontrou o elemento %d\n", elemento);
    else
        printf("Encontrou o elemento %d\n", elemento);

    free(lista);

    return 0;
}
