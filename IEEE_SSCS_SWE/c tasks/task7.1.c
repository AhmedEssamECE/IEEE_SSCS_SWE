#include <unistd.h>
#include <stdio>
int _putchar(char c)
{
    return write(1, &c, 1);
}

int main(void)
{
    int i, j, k;

    for (i = 0; i < 8; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            for (k = j + 1; k < 10; k++)
            {
                putchar(i + '0');
                putchar(j + '0');
                putchar(k + '0');

                if (!(i == 7 && j == 8 && k == 9))
                {
                    _putchar(',');
                    _putchar(' ');
                }
            }
        }
    }
    _putchar('\n');
    return (0);
}
