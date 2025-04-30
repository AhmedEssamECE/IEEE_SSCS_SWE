#include <stdio.h>
#include <string.h>
#include <time.h>
void print_message(char *msg)
{

    printf("message= %s\n", msg);
}
int main()
{
    char msg[] = "hello world";
    print_message(msg);
    return 0;
}