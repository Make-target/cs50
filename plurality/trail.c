#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void trail(int number);
void recursion();
int MAX = 4;

int main()
{
    typedef struct
    {
        int number;
        int count;
    }
    save_digit;
    int user_numbers[MAX];
    for(int i = 0; i < 4; i++)
    {
        user_numbers[i] = get_int("%i number: ", i + 1);
    }
    for(int i = 0; i < 4; i++)
    {

        int array_number = 0;
        save_digit digit;
        digit.number = user_numbers[i];
        digit.count = 0;
        for(int j = 1; i + j < MAX; j++)
        {
            if (digit.number < user_numbers[j + i])
            {
                array_number = j + i;
                digit.number = user_numbers[j + i];
                digit.count = 1;
            }
        }
        if (digit.count == 1)
        {
            user_numbers[array_number] = user_numbers[i];
            user_numbers[i] = digit.number;
        }
    }
    printf("First: %i\nSecond: %i\nThird: %i\nFourth: %i\n", user_numbers[0], user_numbers[1], user_numbers[2], user_numbers[3]);
    int user_input = get_int("Number: ");
    trail(user_input);
    return 0;
}

void trail(int number)
{
    if (number >= 10)
    {
        return;
    }
    number++;
    trail(number);
    printf("%i\n", number);
}

void recursion()
{
    return;
}