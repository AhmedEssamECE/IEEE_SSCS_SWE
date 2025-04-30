#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_strong_signal(int strength)
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
void check_signal(int strength)
{
    if (is_strong_signal(strength) == 1)
    {
        printf("Strong signal detected.\n");
    }
    else
    {
        printf("No signal detected.\n");
    }
}
int main()
{
    int strength;
    printf("Enter the strength of the signal: ");
    scanf("%d", &strength);
    check_signal(strength);
    return 0;
}