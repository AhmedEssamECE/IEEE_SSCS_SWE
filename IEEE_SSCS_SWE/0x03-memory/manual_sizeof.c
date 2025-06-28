#include <stdio.h>

int manual_sizeof()
{
    int x, y;
    int *ptr1 = &x;
    int *ptr2 = &x + 1;
    return ((char *)ptr2 - (char *)ptr1);
}

int main()
{
    printf("Size of int: %d bytes\n", manual_sizeof());
    return 0;
}