#include <stdio.h>
#include <stdlib.h>

int main()
{

    char ch;
    scanf("%c", &ch);
    if (ch >= 'a' && ch <= 'z')
    {
        printf("Lower\n");
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("Upper\n");
    }
    else
    {
        return 0;
    }

    return 0;
}