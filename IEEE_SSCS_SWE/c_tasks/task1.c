#include <stdio.h>
#include <stdlib.h>
#include "_putchar.h"

int main()
{
    char i;
    for (i = "a"; i <= "z"; i++)
    {
        if (i == 'q')
        {
            continue;
        }

        _putchar(i);
    }
    for (char j = "Z"; j >= "A"; j--)
    {
        if (j == 'Q')
        {
            continue;
        }

        _putchar(i);
    }
    return 0;
}
