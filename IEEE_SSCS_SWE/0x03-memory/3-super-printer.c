#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void super_printer(const char *flag, ...)
{
    va_list args;
    va_start(args, flag);

    // Process each character in the flag string
    for (int i = 0; flag[i] != '\0'; i++)
    {
        // Print separator between elements (but not before first element)
        if (i > 0)
        {
            printf(" ");
        }

        switch (flag[i])
        {
        case 'f':
        {
            // Handle float type
            double num = va_arg(args, double); // floats are promoted to double in varargs
            printf("%g", num);
            break;
        }
        case 'i':
        {
            // Handle integer type
            int num = va_arg(args, int);
            printf("%d", num);
            break;
        }
        case 'c':
        {
            // Handle char type
            // Note: chars are promoted to int in varargs
            char c = (char)va_arg(args, int);
            printf("%c", c);
            break;
        }
        case 's':
        {
            // Handle string (char*) type
            char *str = va_arg(args, char *);
            if (str == NULL)
            {
                printf("(nil)");
            }
            else
            {
                printf("%s", str);
            }
            break;
        }
        default:
            // Ignore unknown flags
            break;
        }
    }

    va_end(args);
    printf("\n"); // New line at the end
}

// Example usage:
int main()
{
    // Print different types
    super_printer("sifs", "Hello", 42, 3.14, "World");

    // Print with NULL string
    super_printer("scs", "Start", 'A', NULL);

    // Print with unknown flags (ignored)
    super_printer("icsc", 10, 'X', "Test", 'Z');

    return 0;
}