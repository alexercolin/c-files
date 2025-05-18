#include <stdlib.h>
#include <stdio.h>

typedef struct dados
{
    char produto[20];
    int num;
    float preco;
} dados;

int main()
{
    dados p1, p2;
    FILE *fptr = NULL;
    printf("\nDigite produto, registro e preco: \n");
    scanf("%s %i %f", p1.produto, &(p1.num), &(p1.preco));
    fflush(stdin);
    // rotina gravar no arquivo
    if ((fptr = fopen("struct.bin", "ab")) == NULL)
        printf("\nErro");
    else
        fwrite(&p1, sizeof(dados), 1, fptr);
    fclose(fptr); // fora do if = wb, ab,....

    // rotina leitura no arquivo
    if ((fptr = fopen("struct.bin", "rb")) == NULL)
        printf("\nErro ao abrir o arquivo para leitura");
    else
    {
        printf("\n\nRegistros no arquivo:\n");
        printf("---------------------\n");
        int contador = 0;

        while (fread(&p2, sizeof(dados), 1, fptr) == 1)
        {
            contador++;
            printf("\nRegistro #%d:", contador);
            printf("\nProduto: %s", p2.produto);
            printf("\nRegistro: %i", p2.num);
            printf("\nPreco: %.2f\n", p2.preco);
        }

        if (contador == 0)
            printf("Nenhum registro encontrado no arquivo.\n");

        fclose(fptr);
    }

    printf("\n\nO registro que acabou de ser adicionado foi:");
    printf("\nProduto: %s", p1.produto);
    printf("\nRegistro: %i", p1.num);
    printf("\nPreco: %.2f\n", p1.preco);

    return 0;
} // main
