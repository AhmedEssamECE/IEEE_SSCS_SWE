#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SQUARE(x) ((x) * (x))

int main()
{
    int x = -1;
    printf("The square of %d is %d\n", x, SQUARE(x));
    int x = 3;
    printf("The square of %d is %d\n", x, SQUARE(x));
    printf("The square of %d is %d\n", x, SQUARE(1 + 2));
    return 0;
}