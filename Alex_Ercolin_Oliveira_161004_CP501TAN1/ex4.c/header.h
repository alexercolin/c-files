typedef struct
{
    int number;
    float balance;
    char name[100];
} BankAccount;

void allocate(BankAccount **vet, int size);
void registerClient(BankAccount *vet);
void showValues(BankAccount *vet, int size);
void deposit(BankAccount *vet, int rows);
void withdraw(BankAccount *vet, int rows);