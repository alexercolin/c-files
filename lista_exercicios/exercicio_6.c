#include <stdio.h>

int main() {
    char original[3];
    
    char hexValues[3];     
    int decimalValues[3];  
    
    printf("Digite 3 caracteres: \n");
    for (int i = 0; i < 3; i++) {
        printf("Digite o %d° caractere: ", i + 1);
        scanf(" %c", &original[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        hexValues[i] = original[i];  
        
        decimalValues[i] = original[i];  
    }
    
    printf("\nValores originais, em hexadecimal e decimal:\n");
    for (int i = 0; i < 3; i++) {
        printf("Original[%d] = '%c'  Hexadecimal = 0x%X  Decimal = %d\n", i, original[i], hexValues[i], decimalValues[i]);
    }

    return 0;
}
