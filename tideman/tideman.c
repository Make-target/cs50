#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool cycle_check(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    for (int i = 0; i < candidate_count; i++)
    {
        // If name given by voter is the same as in the candidates array, save number of candidate to ranks array
        if (!strcasecmp(name, candidates[i]))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i + 1 < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Count how many pairs has been created
    int counter = 0;
    for (int i = 0; i + 1 < candidate_count; i++)
    {
        // Add i to j to avoid cheking the same pairs
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Check how many voters choos candidate j over candidate i
            if (preferences[i][j] < preferences[j][i])
            {
                pairs[counter].loser = i;
                pairs[counter].winner = j;
                counter++;
            }
            // Check how many voters choose candidate i over candidate j
            else if (preferences[i][j] > preferences[j][i])
            {
                pairs[counter].loser = j;
                pairs[counter].winner = i;
                counter++;
            }
        }
    }
    // Update global variable
    pair_count = counter;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Selevtive algorithm
    for (int i = 0; i < pair_count; i++)
    {
        // Save pair to check
        int winner_adventage = preferences[pairs[i].winner][pairs[i].loser];
        // Variable to save winner pair if found any
        pair winner_pair;
        // Variable to save index of winner pair that will be usefull when swapping pairs
        int index = 0;
        for (int j = i + 1; j < pair_count; j++)
        {
            // If any pair above [i] has bigger winning score than [i], save it at winner_adventage for next loop run
            if (winner_adventage < preferences[pairs[j].winner][pairs[j].loser])
            {
                winner_adventage = preferences[pairs[j].winner][pairs[j].loser];
                winner_pair = pairs[j];
                index = j;
            }
        }
        // Swap pairs
        if (index > 0)
        {
            pairs[index] = pairs[i];
            pairs[i] = winner_pair;
        }
    }
    return;
}

bool cycle_check(int winner, int loser)
{
    printf("Loser before loop: %i\n", loser);
    if (winner == loser)
    {
        printf("First true\n");
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        printf("I after loop: %i\n", i);
        if (locked[loser][i])
        {
            if (cycle_check(winner, i))
            {
                printf("Second true\n\n");
                return true;
            }
        }
    }
    printf("False\n\n");
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle_check(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int counter = 0;
    int winners[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!locked[j][i])
            {
                winners[i]++;
            }
        }
        if (winners[i] == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}