#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Being
{

    char *name;
    int age;
    float energy_level;
};
void print_being(struct Being *b)
{
    // "Name: {name}, Age: {age}, Energy: {energy_level}"

    printf("Name: {%s}, Age: {%d}, Energy: {%f}\n", b->name, b->age, b->energy_level);
}
int main()
{
    struct Being b;
    b.name = "Ahmed";
    b.age = 20;
    b.energy_level = 100;
    print_being(&b);
    return 0;
}