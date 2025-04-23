
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    /*output should be: number n last digit is (even | odd),
    the last digit is num, and it is (more | less) than 5*/
    int last_digit = n % 10;
    if (n % 2 == 0)
    {
        printf("number %d last digit is even\n", n);
    }
    else
    {
        printf("number %d last digit is odd \n", n);
    }
    if (last_digit > 5)
    {
        printf("the last digit is %d and it is more than 5\n", last_digit);
    }
    else
    {
        printf("the last digit is %d and it is less than 5\n", last_digit);
    }
    return (0);
}
