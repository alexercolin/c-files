#include <stdio.h>
#include <stdlib.h>

static int reg = 1000;

typedef struct
{
    char name[30];
    int account;
    float balance;
} Client;

void allocate(Client **vet, int size);
void registerClient(Client *vet);
void showValues(Client *vet, int size);
void deposit(Client *vet, int rows);

int main()
{
    Client *client = NULL;
    int rows = 0;
    int option = 0;

    printf("Bem vindo ao sistema de conta bancária\nSelecione a opcão desejada\n\n");

    printf("Cadastro[1]\nDepósito[2]\nRetirada[3]\nSair[4]\n");

    do
    {
        printf("\nOpcão: ");
        scanf("%i", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            allocate(&client, rows + 1);
            registerClient(client + rows);
            (client + rows)->account = reg++;
            rows++;
            break;
        case 2:
            deposit(client, rows);
            break;
        }

    } while (option != 4);

    system("clear");
    showValues(client, rows);

    free(client);

    return 0;
}

void allocate(Client **vet, int size)
{
    *vet = (Client *)realloc(*vet, size * sizeof(Client));

    if (*vet == NULL)
    {
        printf("Falha ao alocar memória");
        exit(1);
    }
}

void registerClient(Client *vet)
{
    printf("\nNome:\n");
    scanf("%s", vet->name);
    fflush(stdin);

    printf("\nSaldo:\n");
    scanf("%f", &(vet->balance));
    fflush(stdin);
}

void showValues(Client *vet, int size)
{
    for (int i = 0; i < size; i++, vet++)
    {
        printf("\nCliente %i\n", i);
        printf("  Nome %s\n", vet->name);
        printf("  Conta %i\n", vet->account);
        printf("  Saldo %.2f\n", vet->balance);
    }
}

void deposit(Client *vet, int rows)
{
    int accountNumber = 0;
    float value = 0;

    printf("\nConta para depósito: ");
    scanf("%i", &accountNumber);
    fflush(stdin);

    for (int i = 0; i < rows; i++, vet++)
    {
        if (vet->account == accountNumber)
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
