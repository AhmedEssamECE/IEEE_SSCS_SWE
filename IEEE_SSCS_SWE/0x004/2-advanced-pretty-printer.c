#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void advanced_pretty_printer(const char flag, const char *separator, const unsigned int n, ...)
{
    va_list args;
    va_start(args, n);

    for (unsigned int i = 0; i < n; i++)
    {
        switch (flag)
        {
        case 's':
        {
            // Handle string (char*) type
            char *str = va_arg(args, char *);
            printf("%s", str);
            break;
        }
        case 'i':
        {
            // Handle integer type
            int num = va_arg(args, int);
            printf("%d", num);
            break;
        }
        default:
            printf("Unknown type flag '%c'", flag);
            va_end(args);
            return;
        }

        // Print separator unless it's the last element
        if (i < n - 1)
        {
            printf("%s", separator);
        }
    }

    va_end(args);
    printf("\n");
}

// Example usage:
int main()
{

    advanced_pretty_printer('s', ", ", 3, "Hello", "World", "!");

    // Print integers
    advanced_pretty_printer('i', " - ", 4, 10, 20, 30, 40);

    return 0;
}