#include <stdio.h>
#include <stdlib.h>

void allocate(float **p, int tam);
void readValues(float *p);
int findAverageAndLowerValues(float *p, int tam, float **pm);
void showValues(float *p, int tam);

int main()
{
    float *vet = NULL, *p_lower_vet = NULL;
    char should_continue;
    int vet_count = 0, lower_vet_q;

    do {
        allocate(&vet, vet_count + 1);
        readValues(vet + vet_count);
        vet_count++;

        printf("\nDeseja continuar <S/N>: ");
        scanf("%c", &should_continue);
        fflush(stdin);
    } while(should_continue != 'n' && should_continue != 'N');
    
    printf("\nNumeros digitados:\n");
    showValues(vet, vet_count);

    lower_vet_q = findAverageAndLowerValues(vet, vet_count, &p_lower_vet);
    printf("\nMenores que a media\n");
    showValues(p_lower_vet, lower_vet_q);

    printf("\n\n");
    system("pause");
}
  
void allocate(float **p, int tam)
{
    *p = (float*)realloc(*p, tam * sizeof(float));
    if(*p == NULL)
        exit(1);
}

void readValues(float *p)
{  
    printf("\nNumero: ");
    scanf("%f", p);
    fflush(stdin);
}

int findAverageAndLowerValues(float *vet, int tam, float **p_lower_vet)
{
    int i, lower_vet = 0;
    float average = 0;
    for(i = 0; i < tam; i++, vet++)
    average += *vet;
    average /= tam;

    printf("\nMedia = %.2f\n\n", average);

    vet -= tam;   
    for(i = 0; i < tam; i++, vet++)
        if(*vet < average)  
        { 
            allocate(p_lower_vet, lower_vet + 1);
            *(*p_lower_vet + lower_vet) = *vet;
            lower_vet++;
        }

    return lower_vet;
}
    
void showValues(float *p, int tam)
{
    int i;
    for(i = 0; i < tam; i++, p++)
        printf("\n%.2f", *p);
}
