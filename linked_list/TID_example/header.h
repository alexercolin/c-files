#ifndef HEADER_H
#define HEADER_H

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

Lista *criar_lista();
Lista *inserir_lista(Lista *l, int i);
void imprimir_lista(Lista *l);
int vazia(Lista *l);
Lista *buscar(Lista *l, int v);

#endif // HEADER_H
