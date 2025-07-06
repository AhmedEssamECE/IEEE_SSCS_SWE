#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>
int sum_them_all(const unsigned int n, ...)
{
    int sum = 0;

    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i++)
    {
        // Accessing current variable
        // and pointing to next one
        sum += va_arg(list, int);
    }
    va_end(list);

    return sum;
}
int main()
{
    int sum = 0;
    sum = sum_them_all(5, 1, 2, 3, 4, 5);
    printf("%d", sum);

    return 0;
}
