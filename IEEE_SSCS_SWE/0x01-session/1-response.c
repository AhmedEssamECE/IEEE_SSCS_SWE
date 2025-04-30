#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_response_detected(int strength)
{
    if (strength > 50)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int strength;
    printf("Enter the strength of the signal: ");
    scanf("%d", &strength);
    if (is_response_detected(strength) == 1)
    {
        printf("The signal is a response.\n");
    }
    else
    {
        printf("The signal is not a response.\n");
    }
    return 0;
}