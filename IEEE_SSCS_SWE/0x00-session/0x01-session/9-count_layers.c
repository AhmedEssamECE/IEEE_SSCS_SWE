#include <stdio.h>
#include <string.h>
int sum_layers(int n)
{

    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum_layers(n - 1);
    }
}

int main()
{
    int x = sum_layers(5);
    printf("sum of layers= %d\n", x);
    int y = sum_layers(10);
    printf("sum of layers= %d\n", y);
    printf("sum of layers= %d\n", sum_layers(20));
    return 0;
}