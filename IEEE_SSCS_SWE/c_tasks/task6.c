#include <stdio.h>
#include <stdlib.h>
#include "_putchar.h"

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            _putchar(i + '0');
            _putchar(j + '0');
            if ((i != 8) || (j != 9))
            {
                _putchar(',');
                _putchar(' ');
            }
        }
        putchar("\n");
    }
    return 0;
}
