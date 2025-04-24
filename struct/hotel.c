#include <stdio.h>
#include <stdlib.h>

typedef struct quarto {
    int num;
    char categoria; //S-solteiro ou F-familiar
    char status; //L-livre ou O-ocupado
} quarto;

typedef struct hospede {
    int n_quarto;
    char nome[30];
    int acompanhante;
    int dias;
} hospede;

void aloca_quarto(quarto **q, int qtde);
void aloca_hospede(hospede **h, int qtde);
void cadastra_quarto(quarto *q, int qtde);
void cadastra_hospede(hospede *h, quarto *q);
int busca_quarto(quarto *q, char cat);
void check_out(hospede *h, int qtde, quarto *q);

int main()
{
    quarto *pq = NULL;
    hospede *ph = NULL;
    int op, cont = 0, pos;
    
    aloca_quarto(&pq, 15);
    cadastra_quarto(pq, 15);
    
    do {
        printf("\n[1]Check-in \n[2]Check-out \n[3]Fim \nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);
        
        switch(op) {
            case 1: 
                aloca_hospede(&ph, cont+1);
                cadastra_hospede(ph+cont, pq);
                cont++;
                break;
            case 2: 
                check_out(ph, cont, pq);
                break;
        }
    } while(op != 3);
}//main

void aloca_quarto(quarto **q, int qtde)
{
    if((*q = (quarto*)realloc(*q, qtde*sizeof(quarto))) == NULL)
        exit(1);
}//aloca_quarto

void aloca_hospede(hospede **h, int qtde)
{
    if((*h = (hospede*)realloc(*h, qtde*sizeof(hospede))) == NULL)
        exit(1);
}//aloca_hospede

void cadastra_quarto(quarto *q, int qtde)
{
    int i;
    for(i = 0; i < qtde; i++, q++) {
        q->num = i+1;
        q->status = 'L';
        if(i < 5) //5 quartos de Solteiro
            q->categoria = 'S';
        else //10 quartos Familiar
            q->categoria = 'F';
    }
}//cadastra_quarto

void cadastra_hospede(hospede *h, quarto *q)
{
    printf("\nNome: ");
    scanf("%s", h->nome);
    fflush(stdin);
    
    do {
        printf("\nQtde de acompanhantes - max.3: ");
        scanf("%i", &h->acompanhante);
        fflush(stdin);
    } while(h->acompanhante < 0 || h->acompanhante > 3);
    
    if(h->acompanhante == 0)
        q->categoria = 'S';
    else
        q->categoria = 'F';
    
    printf("\nDias: ");
    scanf("%i", &h->dias);
    fflush(stdin);
    
    h->n_quarto = busca_quarto(q, q->categoria);
    
    if(h->n_quarto == -1)
        printf("\nNao ha quartos com a categoria desejada\n\n");
    else
        printf("\nCadastro com sucesso - quarto = %i\n\n", h->n_quarto);
    
    printf("Pressione Enter para continuar...");
    getchar();
}//cadastro

int busca_quarto(quarto *q, char cat)
{
    int i;
    for(i = 0; i < 15; i++, q++)
        if(q->categoria == cat && q->status == 'L') {
            q->status = 'O';
            return(q->num);
        }
    return -1;
}//busca

void check_out(hospede *h, int qtde, quarto *q)
{
    int numq, i;
    printf("\nQuarto: ");
    scanf("%i", &numq);
    fflush(stdin);
    
    (q+numq-1)->status = 'L';
    
    for(i = 0; i < qtde; i++, h++)
        if(h->n_quarto == numq) {
            printf("\nNome: %s\n", h->nome);
            if(h->acompanhante == 0)
                printf("\nValor a pagar: %.2f\n\n\n", h->dias*85.00);
            else
                printf("\nValor a pagar: %.2f\n\n\n", h->dias*(h->acompanhante+1)*65.00);
            printf("Pressione Enter para continuar...");
            getchar();
        }//if
}//check-out
