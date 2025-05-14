#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void allocate(BankAccount **vet, int size)
{
    *vet = (BankAccount *)realloc(*vet, size * sizeof(BankAccount));

    if (*vet == NULL)
    {
        printf("Falha ao alocar memória");
        exit(1);
    }
}

void registerClient(BankAccount *vet)
{
    printf("\nNome:\n");
    scanf("%s", vet->name);
    fflush(stdin);

    printf("\nSaldo:\n");
    scanf("%f", &(vet->balance));
    fflush(stdin);
}

void showValues(BankAccount *vet, int size)
{
    for (int i = 0; i < size; i++, vet++)
    {
        printf("\nCliente %i\n", i);
        printf("  Nome %s\n", vet->name);
        printf("  Conta %i\n", vet->number);
        printf("  Saldo %.2f\n", vet->balance);
    }
}

void deposit(BankAccount *vet, int rows)
{
    int accountNumber = 0;
    float value = 0;

    printf("\nConta para depósito: ");
    scanf("%i", &accountNumber);
    fflush(stdin);

    for (int i = 0; i < rows; i++, vet++)
    {
        if (vet->number == accountNumber)
        {
            printf("\nValor: ");
            scanf("%f", &value);
            fflush(stdin);
            vet->balance += value;
            return;
        }
    }

    printf("\nConta não encontrada!");
}

void withdraw(BankAccount *vet, int rows)
{
    int accountNumber = 0;
    float value = 0;

    printf("\nConta para retirada: ");
    scanf("%i", &accountNumber);
    fflush(stdin);

    for (int i = 0; i < rows; i++, vet++)
    {
        if (vet->number == accountNumber)
        {
            printf("\nValor: ");
            scanf("%f", &value);
            fflush(stdin);
            if (value > vet->balance)
            {
                printf("\nSaldo insuficiente!");
                return;
            }
            vet->balance -= value;
            return;
        }
    }

    printf("\nConta não encontrada!");
}