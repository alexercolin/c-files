#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void allocate(Student **vet, int size)
{
    *vet = (Student *)realloc(*vet, size * sizeof(Student));

    if (*vet == NULL)
    {
        printf("Falha ao alocar memória");
        exit(1);
    }
}

void addStudent(Student *student)
{
    printf("\nNome do aluno:\n");
    scanf("%s", student->name);
    fflush(stdin);

    printf("\nMatrícula:\n");
    scanf("%i", &(student->registration));
    fflush(stdin);

    printf("\nNota:\n");
    scanf("%f", &(student->grade));
    fflush(stdin);
}

void showStudent(Student *students, int size)
{
    char name[100];
    int found = 0;

    printf("\nDigite o nome do aluno que deseja buscar: ");
    scanf("%s", name);
    fflush(stdin);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            printf("\nNome do aluno: %s\n", students[i].name);
            printf("Matrícula: %i\n", students[i].registration);
            printf("Nota: %.2f\n", students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAluno não encontrado!\n");
    }
}

void updateStudentGrade(Student *students, int size)
{
    char name[100];
    float grade = 0;
    int found = 0;

    printf("\n## Atualizar nota ##: ");
    printf("\nNome do aluno: ");
    scanf("%s", name);
    fflush(stdin);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            printf("\nNova nota: ");
            scanf("%f", &grade);
            fflush(stdin);
            students[i].grade = grade;
            printf("\nNota atualizada com sucesso!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAluno não encontrado!\n");
    }
} 