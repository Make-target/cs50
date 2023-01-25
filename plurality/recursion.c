#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>


int MAX = 20;
int user_numbers[20]; // the numbers to check
int index_to_check = 0;
int PROVIDED_NUMBERS = 0;
void trail();

int main(int argc, string argv[])
{
    PROVIDED_NUMBERS = argc - 1; // how many numbers does the user provides
    for (int i = 0; i < PROVIDED_NUMBERS; i++) // convert the numbers from string to int
    {
        user_numbers[i] = atoi(argv[i + 1]);
    }
    trail();
    printf("Sorted: ");
    int j = 0;
    while (j < PROVIDED_NUMBERS) // print the sorted numbers
    {
        printf("%i, ", user_numbers[j]);
        j++;
    }
    printf("\n");
    return 0;
}

void trail() // sort the numbers from high to low
{
    int end_if_sorted = 0;
    int check_number = user_numbers[index_to_check]; // number to check
    int if_swap = 0; // reset
    int greater_number_index = 0; // reset
    for (int i = 1; i + index_to_check < PROVIDED_NUMBERS; i++) // find greater number
    {
        if (check_number < user_numbers[i + index_to_check])
        {
            if_swap = 1; // tick if the loop found any greater number than in check_number
            greater_number_index = i + index_to_check; // save in which array the loop found the greater number
            check_number = user_numbers[i + index_to_check]; // save the greater number
        }
    }
        if (if_swap == 1) // switch the greater and the smaller number
    {
        user_numbers[greater_number_index] = user_numbers[index_to_check];
        user_numbers[index_to_check] = check_number;
    }
    for (int i = 0; i < PROVIDED_NUMBERS - 1; i++) // check if the numbers are already sorted
    {
        if (user_numbers[i] >= user_numbers[i + 1])
        {
            end_if_sorted++;
        }
    }
        if (end_if_sorted == PROVIDED_NUMBERS - 1)
    {
        return;
    }
    index_to_check++; // move to the next number
    trail(); // recursion
}