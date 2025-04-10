#include <stdio.h>
int main()
{
int n = 10;
int *p;
p = &n;
*p = 20;

(*p)++;
n++;

printf("%d\n", n);
printf("%d\n", *p);
return 0;
}
