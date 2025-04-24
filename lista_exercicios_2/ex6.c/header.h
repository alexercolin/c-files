typedef struct
{
    char name[100];
    int registration;
    float grade;
} Student;

void allocate(Student **vet, int size);
void addStudent(Student *vet);
void updateStudentGrade(Student *vet, int size);
void showStudent(Student *vet, int size); 