#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void pretty_printer(const char *separator, const unsigned int n, ...)
{
    va_list args;
    va_start(args, n);

    for (unsigned int i = 0; i < n; i++)
    {
        int num = va_arg(args, int);
        printf("%d", num);

        // Print separator if not the last number
        if (i < n - 1 && separator != NULL)
        {
            printf("%s", separator);
        }
    }

    va_end(args);
    printf("\n");
}
int main()
{
    pretty_printer(NULL, 5, 1, 2, 3, 4, 5);
    pretty_printer("|", 5, 1, 2, 3, 4, 5);
    pretty_printer(" - ", 5, 1, 2, 3, 4, 5);
    pretty_printer(" | ", 5, 1, 2, 3, 4, 5);
    pretty_printer(" || ", 5, 1, 2, 3, 4, 5);
    pretty_printer(" ||| ", 5, 1, 2, 3, 4, 5);
    pretty_printer(" |||| ", 5, 1, 2, 3, 4, 5);
    pretty_printer(" ||||| ", 5, 1, 2, 3, 4, 5);
    pretty_printer(" |||||| ", 5, 1, 2, 3, 4, 5);
}