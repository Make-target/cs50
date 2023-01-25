#include<cs50.h>
#include<strings.h>
#include<stdio.h>

void recursion (int j);

int main()
{
    int n = 1;
    recursion(n);
    return 0;
}

void recursion (int j)
{
    if (j > 3)
    {
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("i: %i\n", i);
    }
    printf("\n j: %i \n\n", j);
    recursion(j + 1);
    printf("\n j: %i \n\n", j);
}