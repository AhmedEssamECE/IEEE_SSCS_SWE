#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variable (stored in data segment)
int global_var = 42;

int main()
{
    // Local variable (stored in stack)
    int local_var = 10;

    // Dynamically allocated variable (stored in heap)
    int *dynamic_var = (int *)malloc(sizeof(int));
    *dynamic_var = 100;

    // String literal assigned to pointer (stored in read-only data/rodata segment)
    char *string_literal = "Hello, World!";

    // Print information about each variable
    printf("(%p : data) -> %d\n", (void *)&global_var, global_var);
    printf("(%p : stack) -> %d\n", (void *)&local_var, local_var);
    printf("(%p : heap) -> %d\n", (void *)dynamic_var, *dynamic_var);
    printf("(%p : rodata) -> \"%s\"\n", (void *)string_literal, string_literal);

    // Free dynamically allocated memory
    free(dynamic_var);

    return 0;
}