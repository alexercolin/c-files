#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int data;
    struct No *prox;
} No;

typedef struct Pilha
{
    No *topo;
} Pilha;

void push(Pilha *Pilha, int data)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->data = data;
    novoNo->prox = Pilha->topo;
    Pilha->topo = novoNo;
}

int pop(Pilha *Pilha)
{
    if (Pilha->topo == NULL)
    {
        printf("Pilha \n");
        return -1;
    }
    No *temp = Pilha->topo;
    int pop = temp->data;
    Pilha->topo = Pilha->topo->prox;
    free(temp);
    return pop;
}

int verificaVazia(Pilha *Pilha)
{
    return Pilha->topo == NULL;
}

int main()
{
    Pilha Pilha;
    Pilha.topo = NULL;

    push(&Pilha, 10);
    push(&Pilha, 20);
    push(&Pilha, 30);

    printf("Pilha Vazia %s\n", verificaVazia(&Pilha) ? "Sim" : "Nao");

    pop(&Pilha);
    pop(&Pilha);
    pop(&Pilha);

    printf("Pilha Vazia? %s\n", verificaVazia(&Pilha) ? "Sim" : "Nao");

    return 0;
}
