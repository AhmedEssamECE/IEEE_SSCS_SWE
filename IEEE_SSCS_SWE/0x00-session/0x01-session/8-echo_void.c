#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

void echo(int n)
{
    if (n <= 0)
    { // Base case
        printf("%d: Echo...\n", n);
        return;
    }
    printf("%d: Echo...\n", n);
    echo(n - 1); // Recursive call
}

int main()
{
    echo(5);
    return 0;
}