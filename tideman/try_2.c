#include <cs50.h>
#include <stdio.h>
#include <strings.h>

int MAX = 3;
bool a[4][4] = {
    {false, false, true, false},
    {false, false, false, false},
    {false, false, false, true},
    {true, false, false, false}
};


int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int winner = i;
            int loser = j;
            bool cycle = false;
            if (a[i][j])
            {
                for (int k = 0; k < 4 && !cycle; k++)
                {
                    if (a[j][k])
                    {
                        if (a[k][i])
                        {
                            cycle = true;
                        }
                    }
                }
            }
            if (!cycle)
            {
                printf("No cycle on Winner: %i \n Loser: %i\n\n", winner, loser);
            }
        }
    }
    return 0;
}