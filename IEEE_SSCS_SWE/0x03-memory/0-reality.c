#include <stdio.h>
#include <stdlib.h>
void status(int n)
{
    if (n > 0)
    {
        printf("Positive\n");
    }
    else if (n < 0)
    {
        printf("Negative\n");
    }
    else
    {
        printf("Zero\n");
    }
}
int main()
{
    int x;

    scanf("%d", &x);
    void (*fun_ptr)(int);

    fun_ptr = status;
    fun_ptr(x);

    return 0;
}
