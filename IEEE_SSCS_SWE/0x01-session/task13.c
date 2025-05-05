#include <stdio.h>

int counter(char *mystring)
{
    int count = 1; // Start with 1 word (even if no spaces)
    while (*mystring != '\0')
    {
        if (*mystring == ' ')
        {
            count++;
        }
        mystring++;
    }
    return count;
}

int main()
{
    char mystring[] = "Hello World";
    printf("Number of words: %d\n", counter(mystring));
    return 0;
}