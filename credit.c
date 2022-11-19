#include <cs50.h>
#include <stdio.h>

unsigned long american_express_15 = 100000000000000;
unsigned long master_card_or_visa_16 = 1000000000000000;
unsigned long visa_13 = 1000000000000;
unsigned long user_card = 0;
unsigned long card = 0;
int first_digit = 0;
int second_digit = 0;
int digit = 0;
int modulo = 10;

int main (void)
{

    user_card = get_long ("\n\n\n\n\n\nCard number: ");
    card = user_card;
    while (card != 0)
    {
        digit = card % modulo; // Search for the last digit of card number
        first_digit += digit; // Add last digit to a pot
        card *= 0.10;         // Move to another digit by subtracting one zero

        digit = card % modulo;
        if (digit * 2 > 9) // Separate and add numbers greater than 9(after multiplying) as in Lunh's Algorithm
        {
            digit = digit * 2;
            int x = digit;
            x = digit % 10;
            second_digit += x;
            x = digit * 0.10;
            second_digit += x;
            card *= 0.10;

        }

        else // Multiply only if smaller than 10
        {
        second_digit += digit * 2;
        card *= 0.10;
        }
    }
    int result = (first_digit + second_digit) % 10; // Check if a card is valid by Luhn's Algorithm
    while (user_card != 0)
    {
            if (result == 0)
     {
         printf("Valid card.\n");
     }
    else
      {
         printf("Invalid card.\n");
      }
      break;
    }
    unsigned long x = user_card;
    if (result == 0) // Check beginning numbers to determine the card provider
    {
        do
        {
            x *= 0.10;
            if ((user_card > american_express_15 && x == 37) || x == 34)
            {
                printf("American Express");
            }
            else if ((user_card > master_card_or_visa_16 && x == 51) || x == 52 || x == 53 || x == 54 || x == 55)
            {
                printf("Master Card\n");
            }

        }
        while(x > 99);
        x *= 0.10;
        if (((user_card > master_card_or_visa_16 || user_card > visa_13) && x == 4) || x == 5)
            {
                printf("Visa\n");
            }
    }
    else if (user_card == 0)
        {
        printf("Invalid card.\n");
        }
}

