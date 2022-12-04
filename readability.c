#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_characters(string text);
int count_letters(string text);
int count_words(string text);
int count_senteces(string text);
float count_average(float a, float b);
int count_grade(float a, float b);
string input;
int characters; // Use to let the loop know how many arrays have a string

int main(void)
{
    input = get_string("Text: ");
    characters = count_characters(input);
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_senteces(input);
    float l = count_average(letters, words);
    float s = count_average(sentences, words);
    int grade = count_grade(l, s);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
int count_characters(string text)
{
    int x = strlen(text);
    return x;
}
int count_letters(string text) // Count letters and reject any other characters
{
    int result = 0;
    for (int i = 0; i < characters; i++)
    {
        while ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            result++;
            break;
        }
    }
    return result;
}
int count_words(string text) // Use space to recognize the end of the word
{
    int result = 1;
    for (int i = 0; i < characters; i++)
    {
        if (input[i] == ' ')
        {
            result++;
        }
    }
    return result;
}
int count_senteces(string text) // Use '.', '?', '!' to recognize the end of the sentence
{
    int result = 0;
    for (int i = 0; i < characters; i++)
    {
        char stoppers[3] = {'.', '?', '!'};
        if (input[i] == stoppers[0] || input[i] == stoppers[1] || input[i] == stoppers[2])
        {
            result++;
        }
    }
    return result;
}
float count_average(float a, float b)
{
    float result = a / b * 100;
    return result;
}
int count_grade(float a, float b) // Calculate the grade by using a Coleman-Liau index
{
    float index = 0.0588 * a - 0.296 * b - 15.8;
    int result = round(index);
    return result;
}