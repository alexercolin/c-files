#include <stdio.h>
#include <stdlib.h>

int main() {
    int *fibonacci;


    printf("Pressione enter para calcular os 10 primeiros numeros da sequencia de Fibonacci\n");
    getchar();

    int firstValue = 0;
    int secondValue = 1;

    fibonacci = (int*)malloc(10 * sizeof(int));

    if (fibonacci == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    fibonacci[0] = firstValue;
    fibonacci[1] = secondValue;


    for(int counter = 2; counter < 10; counter++){
        fibonacci[counter] = fibonacci[counter - 1] + fibonacci[counter -2 ];
    }

    printf("Os dez primeiros elementos da sequencia de Fibonacci é\n");

    int *original_ptr = fibonacci;
    
    for(int newCounter = 0; newCounter < 10; newCounter++, fibonacci++){
        printf("%i \n", *(fibonacci));
    }

    fibonacci = original_ptr;
    free(fibonacci);

    return 0;
}

