#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Product *products = NULL;
    int rows = 0;
    int option = 0;

    printf("Bem vindo ao sistema de gestão de estoque\nSelecione a opcão desejada\n\n");

    do
    {
        printf("\n[1] Cadastro de Produto\n[2] Alterar quantiade de produto\n[3] Sair\n");

        printf("\nOpcão: ");
        scanf("%i", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            allocate(&products, rows + 1);
            addProduct(products + rows);
            rows++;
            break;
        case 2:
            updateProductQuantity(products, rows);
            break;
        }

    } while (option != 3);

    system("clear");
    showProducts(products, rows);

    free(products);

    return 0;
}
