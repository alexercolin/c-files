#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char cpf[13];
    char name[20];
} Military;

typedef struct
{
    int id;
    int qmilitary;
    char org[20];
    char patent[20];
    float salary;
} Path;

void militaryAllocate(Military **military, int quantity);
void pathAllocate(Path **path, int quantity);
void registerMilitary(Military *military, int q)

    int main()
{
    Military *military = NULL;
    Path *path = NULL;
    int option = 0;

    militaryAllocate(&military, 5);
    pathAllocate(&path, 5);

    do
    {
        printf("\n[1]Cadastro Militar\n[2]Trocar patente\n[3]Mostrar patente\n[4]Fim\nOpcao: ");
        scanf("%i", &option);

        switch (option)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;
        }

    } while (option != 4);

    return 0;
}

void militaryAllocate(Military **military, int quantity)
{
    *military = (Military *)realloc(*military, quantity * sizeof(Military));

    if (*military == NULL)
    {
        printf("Error to allocate memory");
        exit(1);
    }
}
void pathAllocate(Path **path, int quantity)
{
    *path = (Path *)realloc(*path, quantity * sizeof(Path));

    if (*path == NULL)
    {
        printf("Error to allocate memory");
        exit(1);
    }
}