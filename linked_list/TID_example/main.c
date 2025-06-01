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
    lista = inserir_lista(lista, 8);
    lista = inserir_lista(lista, 9);

    printf("Conteúdo da lista:\n");

    int elemento = 5;
    if (buscar(lista, elemento) == NULL)
        printf("Nao encontrou o elemento %d\n", elemento);
    else
        printf("Encontrou o elemento %d\n", elemento);

    lista = remover_lista(lista, 5);

    imprimir_lista(lista);

    free(lista);

    return 0;
}
