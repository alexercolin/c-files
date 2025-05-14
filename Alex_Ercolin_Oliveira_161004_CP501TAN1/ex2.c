#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char title[50];
    char author[50];
    int pageNumbers;
    int code;
} Book;

void showBooks(Book books[]);

int main()
{
    Book books[10] = {
        {"Dom Casmurro", "Machado de Assis", 256, 1001},
        {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", 96, 1002},
        {"1984", "George Orwell", 328, 1003},
        {"Cem Anos de Solidão", "Gabriel García Márquez", 417, 1004},
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1178, 1005},
        {"Crime e Castigo", "Fiódor Dostoiévski", 561, 1006},
        {"Harry Potter e a Pedra Filosofal", "J.K. Rowling", 309, 1007},
        {"A Metamorfose", "Franz Kafka", 104, 1008},
        {"O Processo", "Franz Kafka", 224, 1009},
        {"Orgulho e Preconceito", "Jane Austen", 432, 1010}};

    showBooks(books);

    return 0;
}

void showBooks(Book books[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("\n#### Book %i ####\n", i + 1);
        printf("Title: %s \n", books[i].title);
        printf("Author: %s \n", books[i].author);
        printf("Page Number: %i \n", books[i].pageNumbers);
        printf("Code: %i \n", books[i].code);
    };
}