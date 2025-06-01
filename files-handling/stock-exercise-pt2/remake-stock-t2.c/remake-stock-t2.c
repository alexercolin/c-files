#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int reg;
    char product[20];
    int quantity;
    float price;
} Data;

void allocate(Data **data, int quantity);
void insert(Data *data);
void record(Data *data);
int checkRecords();

int main()
{
    Data *pd = NULL;
    int option;

    allocate(&pd, 1);

    do
    {
        printf("\n[1]Cadastro\n[2]Altera\n[3]Deleta\n[4]Mostra\n[5]Fim\nOpcao: ");
        scanf("%i", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            insert(pd);
            break;

        case 2:
        case 3:
            break;

        case 4:
            break;
        }

    } while (option != 5);

    return 0;
}

void allocate(Data **data, int quantity)
{
    *data = (Data *)realloc(*data, quantity * sizeof(Data));

    if (*data == NULL)
    {
        printf("Error to allocate memory");
        exit(1);
    }
}

// 1 - verifica quantos registros existem no arquivo
// 2 - insere o numero do registro no dado
// 3 - Recebe os dados digitados pelo usuario
// 4 - Grava no arquivo

void insert(Data *data)
{
    int count;
    count = checkRecords();
    data->reg = count + 1;

    printf("\nRegisto: %i", data->reg);

    printf("\nProduto: ");
    scanf("%s", data->product);
    fflush(stdin);

    printf("\nQuantidade: ");
    scanf("%i", &(data->quantity));
    fflush(stdin);

    printf("\nPreco: ");
    scanf("%f", &(data->price));
    fflush(stdin);

    record(data);
}

void record(Data *data)
{
    FILE *fptr = NULL;
    fptr = fopen("stock.bin", "ab");

    if (fptr == NULL)
    {
        printf("Error to open file");
    }
    else
    {
        fwrite(data, sizeof(Data), 1, fptr);
    }

    fclose(fptr); // NAO ESQUECER, se nao, nao grava
}

int checkRecords()
{
    FILE *fptr = NULL;
    long int count = 0;

    fptr = fopen("stock.bin", "rb");

    if (fptr == NULL)
    {
        return count;
    }
    else
    {
        fseek(fptr, 0, 2);
        count = ftell(fptr) / sizeof(Data);
        fclose(fptr);
        return count;
    }
}