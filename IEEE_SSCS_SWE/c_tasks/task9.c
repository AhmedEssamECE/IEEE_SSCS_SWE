#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;

    scanf("%d", &x);
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            int sum = i * j;
            printf("%d ", sum);
            if (j < x)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
}
