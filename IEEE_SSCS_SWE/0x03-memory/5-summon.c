#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *summon_allies(int *allies, int n)
{

    allies = (int *)malloc(n * sizeof(int));
    if (allies == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Please Enter the value of allies[%d]: ", i);
        scanf("%d", &x);
        allies[i] = x;
    }
    return allies;
}

int main()
{
    int *allies;
    int n = 0;
    printf("Enter number of allies: ");
    scanf("%d", &n);

    allies = summon_allies(allies, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", allies[i]);
    }
    return 0;
}
