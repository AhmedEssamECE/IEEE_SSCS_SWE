#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *clear_allocation(size_t count, size_t size)
{
    int *arr = (int *)malloc(count * size);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    memset(arr, 0, count * size);
    return arr;
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = clear_allocation(n, sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}