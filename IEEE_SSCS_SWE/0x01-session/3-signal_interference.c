#include <stdio.h>
#include <string.h>
#include <time.h>
int signal_strength = 0;
void boost_signal(int n)
{
    int signal_strength = 100;
    printf("booster: signal strength= %d\n", n);
}
int main()
{
    printf("signal strength= %d\n", signal_strength);
    boost_signal(123);
    printf("signal strength= %d\n", signal_strength);
    return 0;
}