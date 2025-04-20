#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char model[50];
    int year;
    float price;
    char licensePlate[10];

} Vehicle;

void allocate(Vehicle **vehicle, int rows);
void readVehicles(Vehicle *vehicle);
void showVehicles(Vehicle *vehicle, int rows);

int main()
{

    Vehicle *vehicle = NULL;
    int rows = 0;
    char should_continue;

    do
    {
        printf("\n#### Cadastro de veículos no sistema ####\n");
        allocate(&vehicle, rows + 1);
        readVehicles(vehicle + rows);
        rows++;

        printf("\n Gostaria de continuar cadastrando ?(S/N) ");
        scanf(" %c", &should_continue);
        fflush(stdin);
    } while (should_continue == 'S' || should_continue == 's');

    showVehicles(vehicle, rows);

    free(vehicle);
    return 0;
}

void allocate(Vehicle **vehicle, int rows)
{
    *vehicle = (Vehicle *)realloc(*vehicle, rows * sizeof(Vehicle));
    if (*vehicle == NULL)
    {
        printf("Erro ao alocar memória");
        exit(1);
    }
}

void readVehicles(Vehicle *vehicle)
{
    printf("\n - Modelo: ");
    scanf("%s", vehicle->model);
    fflush(stdin);

    printf("\n - Ano: ");
    scanf("%i", &(vehicle->year));
    fflush(stdin);

    printf("\n - Preço: ");
    scanf("%f", &(vehicle->price));
    fflush(stdin);

    printf("\n - Placa: ");
    scanf("%s", vehicle->licensePlate);
    fflush(stdin);
}

void showVehicles(Vehicle *vehicle, int rows)
{
    for (int i = 0; i < rows; i++, vehicle++)
    {
        printf("\n#### Veiculo %i ####\n", i + 1);
        printf("\n - Modelo: %s", vehicle->model);
        printf("\n - Ano: %i", vehicle->year);
        printf("\n - Preço: %.2f", vehicle->price);
        printf("\n - Placa: %s\n", vehicle->licensePlate);
    }
}
