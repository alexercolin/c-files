#include <stdio.h>
#include <stdlib.h>
#include "header.h"

static int reg = 1000;

int main()
{
    BankAccount *client = NULL;
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
            (client + rows)->number = reg++;
            rows++;
            break;
        case 2:
            deposit(client, rows);
            break;
        case 3:
            withdraw(client, rows);
            break;
        }

    } while (option != 4);

    system("clear");
    showValues(client, rows);

    free(client);

    return 0;
}
