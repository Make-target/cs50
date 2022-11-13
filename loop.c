#include <cs50.h>
#include <stdio.h>

int main(void)

{
    unsigned long second_number = 0;
    unsigned long card_number =	371449635398431;
    unsigned long modulo_first = 100;
    unsigned long modulo_second = 10;
    unsigned long card_number_second_digit = card_number;
    unsigned long clock = card_number;
    while (card_number > 0)
    {
        clock *= 0.10; //Subtract one zero from variable card_number, so that the loop stops working when it reaches the last digit.
        unsigned long digit = card_number_second_digit % modulo_second; // Take a last-second number from the card number.
        modulo_second = modulo_second * 100; // Prepare the module to take another digit moved by two zeros to the left.
        while(digit >= 10) // Screens out the needed digit from the other modulo digits.
        {
            digit *= 0.10;
        }
        second_number += digit * 2; //It multiplies a digit by 2, as in the CS50 algorithm.
        printf ("%lu\n           %lu\n", digit, clock);
        if (clock < 10) // Close the loop if clock reach last digit.
        {
            break;
        }
    }

    printf ("%lu\n", card_number);
}