#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Point;

void attribute(Point * p, int x, int z);

int main () {
    Point *p = NULL;

    p = (Point*)malloc(sizeof(Point));

    if(p == NULL) {
        printf("Error to allocate memory");
        exit(1);
    }

    p->a = 10;
    p->b = 20;

    attribute(p, 1, 2);

    printf("p -> a = %i \n", p->a );
    printf("p -> b = %i \n", p->b );

    free(p);

    return 0;
}

void attribute(Point *p, int x, int z) {
    p->a = x;
    p->b = z;
}
