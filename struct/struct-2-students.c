#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[2][50];  // Array of 2 strings, each up to 49 characters
    int age[10];
    int grade;
};

int main () {
    struct student *stu;
    stu = (struct student*)malloc(sizeof(struct student));

    if(stu == NULL) {
        printf("Error to allocate memory\n");
        return 1;
    }

    printf("Type the studentA name: ");
    scanf("%s", stu->name[0]);
    printf("Type the studentB name: ");
    scanf("%s", stu->name[1]);

    printf("Type the studentA age: ");
    scanf("%d", &stu->age[0]);
    printf("Type the studentB age: ");
    scanf("%d", &stu->age[1]);

    printf("StudentA Name: %s\n", stu->name[0]);
    printf("StudentB Name: %s\n", stu->name[1]);
    printf("StudentA Age: %d\n", stu->age[0]);
    printf("StudentB Age: %d\n", stu->age[1]);

    free(stu);
    return 0;
}