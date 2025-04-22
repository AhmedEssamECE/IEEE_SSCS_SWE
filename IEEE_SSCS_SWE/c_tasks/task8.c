#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 9;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            int sol = j * i;
            printf("%d", sol);
            if (j != 9)
            {
                printf(",");
            }
        }

        printf("\n");
    }
}
