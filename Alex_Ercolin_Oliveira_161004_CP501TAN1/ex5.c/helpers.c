#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void allocate(Product **vet, int size)
{
    *vet = (Product *)realloc(*vet, size * sizeof(Product));

    if (*vet == NULL)
    {
        printf("Falha ao alocar memória");
        exit(1);
    }
}

void addProduct(Product *product)
{
    printf("\nNome:\n");
    scanf("%s", product->name);
    fflush(stdin);

    printf("\nCódigo:\n");
    scanf("%i", &(product->code));
    fflush(stdin);

    printf("\nQuantidade:\n");
    scanf("%i", &(product->quantity));
    fflush(stdin);

    printf("\nPreço:\n");
    scanf("%f", &(product->price));
    fflush(stdin);
}

void showProducts(Product *product, int size)
{
    for (int i = 0; i < size; i++, product++)
    {
        printf("\n %s\n", product->name);
        printf("  Código %i\n", product->code);
        printf("  Quantidade %i\n", product->quantity);
        printf("  Preço %.2f\n", product->price);
    }
}

void updateProductQuantity(Product *product, int rows)
{
    int code = 0;
    float quantity = 0;

    printf("\n## Atualizar quantidade ##: ");
    printf("\nCódigo do produto: ");
    scanf("%i", &code);
    fflush(stdin);

    for (int i = 0; i < rows; i++, product++)
    {
        if (product->code == code)
        {
            printf("\nQuantidade: ");
            scanf("%f", &quantity);
            fflush(stdin);
            product->quantity = quantity;
            return;
        }
    }

    printf("\nProduto não encontrado!\n");
}