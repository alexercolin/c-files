#include <stdio.h>
#include <stdlib.h>

#define KILOGRAM_TO_POUND_RATIO 2.2;

void kilogramsToPounds (float kg) {
    float pounds = kg *  KILOGRAM_TO_POUND_RATIO;

    printf("Peso em quilogramas: %.2f \n", kg);
    printf("Peso em libras: %.2f \n", pounds);

}

int main () {
    float kg;

    printf("Digite um peso em quilogramas: \n");

    scanf("%f", &kg);

    kilogramsToPounds(kg);

    return 0;
}