#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int age;
    int grade;
    char course[50];
} Student;

void showStudents(Student students[]);

int main()
{
    Student students[10] = {
        {"João Silva", 19, 85, "Ciência da Computação"},
        {"Maria Oliveira", 20, 90, "Engenharia Civil"},
        {"Pedro Santos", 18, 78, "Física"},
        {"Ana Souza", 21, 92, "Matemática"},
        {"Lucas Ferreira", 19, 80, "Medicina"},
        {"Juliana Costa", 22, 88, "Direito"},
        {"Mateus Alves", 20, 75, "Administração"},
        {"Carolina Lima", 19, 82, "Psicologia"},
        {"Gabriel Mendes", 21, 87, "Arquitetura"},
        {"Isabela Martins", 20, 95, "Biologia"}};

    showStudents(students);

    return 0;
}

void showStudents(Student students[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("\n#### Student %i ####\n", i + 1);
        printf("Name: %s \n", students[i].name);
        printf("Age: %i \n", students[i].age);
        printf("Grade: %i \n", students[i].grade);
        printf("Course: %s \n", students[i].course);
    };
}