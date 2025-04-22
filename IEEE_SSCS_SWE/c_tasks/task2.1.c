#include <stdio.h>
#include "_putchar.h"

int main(void)
{
    int i = 5;

    while (i)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            putchar(c);
        }
        putchar('\n');
        i--;
    }
    return 0;
}