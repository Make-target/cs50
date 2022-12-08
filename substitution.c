#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool letters_only(string x, int z); // check if the user provides alphabetical characters only
bool no_doubles(string x); // check if the user didn't provide any double characters
bool invalid_characters(string x); // check if the user didn't provide characters unwanted by CS50

int main(int argc, string argv[])
{
    string key = argv[1]; // save a second argument provided by the user
    if (argc != 2) // make sure the user provides two arguments
    {
        printf ("Usage: ./substitution key\n");
        return 1;
    }
    else if (letters_only(key, strlen(key)) == false || invalid_characters(key) == false)
    {
        printf("Alphabetic characters only\n");
        return 1;
    }
    else if (strlen(key) != 26) // check if the user provides 26 characters in a key variable
    {
        printf("Key must contain 26 characters.'n");
        return 1;
    }
    else if(no_doubles(key) == false)
    {
        printf ("No doubles characters in the key argument");
        return 1;
    }
    string plaintext = get_string("plaintext:  "); // take text that the user wants to change for cyphertext
    int n_of_user_characters = strlen(plaintext); // count how many characters the user provides in the key
    char cyphertext[n_of_user_characters]; // make char array suitable to characters in the key
    printf("ciphertext: ");
    for (int i = 0; i < n_of_user_characters; i++) //
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') // check if is lowercase
        {
            int n_letter = plaintext[i] - 'a'; // subtract 65 from the character to save a number of characters from 0 to 26
            char c = tolower(key[n_letter]); // and use this number to find character at key[] array than change it for lower case
            printf("%c", c);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            int n_letter = plaintext[i] - 'A';
            char c = toupper(key[n_letter]);
            printf("%c", c);
        }
        else // print any non-alphabetical characters as they are
        {
            printf ("%c", plaintext[i]);
        }
    }
    printf("\n");
}

bool letters_only(string x, int z)
{
    bool y = 1;
    for (int i = 0; i < z; i++)
    {
        y = isalpha(x[i]);
    }
    return y;
}
bool no_doubles(string x)
{
    for (int i = 0; i < 26; i++)
    {
        int counter = 0; // count how many times characters is double
        for (int z = 0; z < 26; z++) // compare all characters to each in x
        {
            if (x[i] == x[z])
            {
                counter++; // if found two identical characters are present, add 1 to counter
                if (counter == 2) // if found more than one similar character return false
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool invalid_characters(string x)
{
    for(int i = 0; i < 26; i++)
    {
        if (x[i] == '^' || x[i] == '[')
        {
            return false;
        }
    }
    return true;
}