#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *get_reply()
{
    static char reply[100];
    printf("Enter your reply: ");
    scanf("%s", reply);
    return reply;
}
void main()
{
    char *reply = get_reply();
    printf("Your reply is: %s\n", reply);
    return;
}