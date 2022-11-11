#include <stdio.h>
#include <cs50.h>



int main(void)
{
    string user_name = get_string("what's your name: ");
    printf("hello, %s\n", user_name);
}