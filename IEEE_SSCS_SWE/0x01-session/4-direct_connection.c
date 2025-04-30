#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    int variablesignal = 98;
    int *ptr = &variablesignal;
    printf("signal strength= %d\n", ptr);
    printf("signal strength= %d\n", *ptr);
    return 0;
}