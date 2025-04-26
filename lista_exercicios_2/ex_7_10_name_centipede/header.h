typedef struct Person
{
    char name[50];
    struct Person *next;
} Person;

void add(Person **list, char name[50]);
void print(Person *list);
void rem(Person **list, char name[50]);
