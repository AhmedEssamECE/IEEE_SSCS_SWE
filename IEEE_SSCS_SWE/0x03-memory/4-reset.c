#include <stdlib.h>
#include <stdio.h>
int globalvariable = 0;
int access_one(int num)
{
    static int counter = 0;
    globalvariable++;
    return ++counter;
}
int access_two(int num2)
{
    static int counter = 0;
    globalvariable++;
    counter++;
    return counter;
}

int main()
{

    int x = access_one(10);
    int y = access_one(20);
    int lastacess = access_one(38);
    int a = access_two(20);
    printf("number of access in acccess_one is %d \n", lastacess);
    printf("number of access in acccess_two is %d \n", a);
    printf("total number of access in both function is %d \n", globalvariable);

    return 0;
}