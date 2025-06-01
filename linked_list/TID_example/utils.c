#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Lista *criar_lista()
{
    return NULL;
}

Lista *inserir_lista(Lista *l, int i)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprimir_lista(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d\n", p->info);
    }
}

int vazia(Lista *l)
{
    return (l == NULL);
}

Lista *buscar(Lista *l, int v)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == v)
        {
            return p;
        }
    }
    return NULL;
}

Lista *remover_lista(Lista *l, int v)
{
    Lista *p = l;
    Lista *ant = NULL;

    if (p == NULL)
    {
        return l;
    }

    while (p != NULL && p->info != v)
    {
        printf("p->info: %d\n", p->info);
        ant = p;
        printf("ant->info: %d\n", ant->info);

        p = p->prox;
        printf("p->info depois: %d\n", p->info);
    }

    if (ant == NULL)
    {
        l = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }

    free(p);
    return l;
}