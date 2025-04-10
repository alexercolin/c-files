#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet[8] = {2, 2, 2, 4, 2, 7, 9, 3};
    
    int counted[8] = {0};
    
    printf("Valores repetidos e suas incidências:\n");
    int isRepeated = 0;
    
    for (int i = 0; i < 8; i++) {
        if (counted[i] == 1) {
            continue;
        }
        
        int *actualValue = &vet[i];
        int counter = 1; 
        
        for (int j = i + 1; j < 8; j++) {
            if (vet[i] == vet[j]) {
                counter++;
                counted[j] = 1; 
            }
        }
        
        if (counter > 1) {
            printf("Valor %d aparece %d vezes\n", *actualValue, counter);
            isRepeated = 1;
        }
    }
    
    return 0;
}