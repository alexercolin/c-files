#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Student *students = NULL;
    int count = 0;
    int option = 0;

    printf("Bem vindo ao sistema de gestão de alunos\nSelecione a opcão desejada\n\n");

    do
    {
        printf("\n[1] Cadastrar novo aluno\n[2] Atualizar nota de aluno\n[3] Consultar informações de aluno\n[4] Sair\n");

        printf("\nOpcão: ");
        scanf("%i", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            allocate(&students, count + 1);
            addStudent(students + count);
            count++;
            break;
        case 2:
            updateStudentGrade(students, count);
            break;
        case 3:
            showStudent(students, count);
            break;
        }

    } while (option != 4);

    system("clear");
    
    free(students);

    return 0;
} 