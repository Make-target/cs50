#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string x); // check if user input digit only

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == 0) // check if user provide two command-line arguments and that second argument is the digit, if is not, close the program
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int code = atoi(argv[1]); // convert the digit that user provide in second argument - from string to int
    string plaintext = get_string ("plaintext:  ");
    int n_of_user_characters = strlen(plaintext); // count how many characters user input in plaintext
    char ciphertext[n_of_user_characters]; // make arrey which size is sutiable to n_of_user_characters, to avoid any unpredictable output
    for (int i = 0; i < n_of_user_characters; i++) // change plaintext to ciphertext by adding code to ASCII
    {
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                ciphertext[i] = ((plaintext[i] - 'a') + code) % 26 + 'a'; // substract 'a' from plaintext[i] to count modulo from code, and add 'a' back
            }
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                ciphertext[i] = ((plaintext[i] - 'A')) + code % 26 + 'A';
            }
        else                                                            // any other character which is not a letter
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < n_of_user_characters; i++) // print every single character from ciphertext
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}
bool only_digits(string x)
{
    int user_characters = strlen(x); // count how many characters user provide in the plaintext, to know when stop to the loop
    bool digit_or_not = 1;
    for (int i = 0; i < user_characters && digit_or_not != 0; i++)
    {
        digit_or_not = isdigit(x[i]); // check if characters in x are digits
    }
    return digit_or_not;
}