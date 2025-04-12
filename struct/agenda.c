#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int reg;
    char nome[90];
    float nota;
} Agenda;

void allocate(Agenda **agenda, int size);
void read_values(Agenda *agenda);
void show_values(Agenda *agenda, int size);


int main () {
    Agenda *agenda = NULL;
    int size = 0;
    static int reg = 1000;
    char should_continue;

    do {
        allocate(&agenda, size + 1);
        read_values(agenda + size);
        (agenda+size)->reg = reg++;

        size++;

        printf("Gostaria de continua adicionando itens na agenda ? (S/N) \n");
        scanf("%c", &should_continue);
        fflush(stdin);
    } while(should_continue == 's' || should_continue == 'S');

    system("clear");

    show_values(agenda, size);

    free(agenda);

    return 0;
}

void show_values(Agenda *agenda, int size) {
    for(int i = 0; i < size; i++, agenda++){
        printf("\nRegisto: %i\n", agenda->reg);
        printf("Nome: %s\n", agenda->nome);
        printf("Nota: %.2f\n", agenda->nota);
    }
}

void read_values(Agenda *agenda) {
    printf("Insira o nome: ");
    scanf("%s", agenda->nome);
    fflush(stdin);

    printf("Insira a nota: ");
    scanf("%f", &(agenda->nota));
    fflush(stdin);
}

void allocate(Agenda **agenda, int size) {
    *agenda = (Agenda*)realloc(*agenda, size * sizeof(Agenda));

    if(*agenda == NULL) {
        printf("Error to allocate memory");
        exit(1);
    }
}