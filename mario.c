#include <cs50.h>
#include <stdio.h>

int n;
int y = 1;
int x = 1;
const string say_bye = ("\nGood bye!\n");

void bye(void);
void blocks(void);
int main(void)
{
    while (x == 1)
    {
        n = get_int("Specify high of the tower between 1 and 8: \n");
        if (n < 9 && n >= 1)
        {
            blocks();
            x = get_int ("\n\nDo yo want to try again? 1 for yes or 2 for no: \n");
        }
        else
        {
            x = get_int ("\n\nYou must type between 1 and 8. Do you want to try again? 1 for yes or 2 for no: \n");
            y = 0;
        }
            if (x != 1)
        {
            break;
        }
    }
    bye();
}




void bye(void)
{
    if ( x != 1)
            {
                 printf ("%s", say_bye);
            }
}

void blocks(void)
{
    int c = 0;
    int n_meter = n;
    for (int i = 0; i < n; i++)
    {
        printf ("\n\n");
        int decrease = n_meter--;
        for (int b = decrease; b > 0; b--)
        {
            printf(" ");
        }
            c++;
            for (int d = 0; d < c; d++)
            {
                printf ("#");
            }
            printf ("  ");
            for(int e = 0; e < c; e++)
            printf ("#");
    }
}




















