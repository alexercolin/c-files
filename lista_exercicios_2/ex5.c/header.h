typedef struct
{
    char name[100];
    int code;
    int quantity;
    float price;
} Product;

void allocate(Product **vet, int size);
void addProduct(Product *vet);
void updateProductQuantity(Product *vet, int size);
void showProducts(Product *vet, int rows);