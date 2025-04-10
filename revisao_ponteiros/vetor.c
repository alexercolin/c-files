#include <stdio.h>
int main()
{
    int n[4] = {1, 2, 3, 4};
    int *p;
    p = n;

    p++;

    printf("%d\n", n[0]);
    printf("%d\n", *p);

    return 0;
}
