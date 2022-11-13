#include <cs50.h>
#include <stdio.h>

int modulo(int x);

int main(void)
{
    int x = 0;
    modulo(x);
}

int modulo(int x)
{
    long card_number = 101213141516171819;
    for (int i = 0; i < 0; i++)
    {
        int every_first_digit = 0;
        int every_second_digit = 0;

        x = card_number % 10;
        card_number -= x;
        if (every_second_digit > 9)
        {
            while(every_second_digit > 10)
            {
                every_second_digit *= 0.10;
            }
        }
        printf (" !hi, %ld! ", card_number);
    }
    int card = 40330201;
    int modulo_a = 10;
    int second_digit_1 = card % modulo_a;
    int modulo_b = modulo_a * 100;
    int second_digit_2 = card % modulo_b;
    int modulo_c = modulo_b * 100;
    int second_digit_3 = card % modulo_c;
    int every_first_digit = 0;
    int every_second_digit = 0;


        {
            while(second_digit_2 > 10)
            {
                second_digit_2 *= 0.10;
            }
        }


        {
            while(second_digit_3 > 10)
            {
                second_digit_3 *= 0.10;
            }
        }



    int a = 40330201;
    int b = a % 10;
    a -= b;

    printf ("!    %d        %d            %d              !", second_digit_1, second_digit_2, second_digit_3);



    return x;

}