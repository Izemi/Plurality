#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Create a variable for the maximum number of votes
    int MaximumVotes = 0;
    // Iterate through the candidates and equalize the number of the highest votes with the MaximumVotes variable
    for (int i = 0; i < candidate_count; i++)
    {
        // Check the highest
        if (MaximumVotes < candidates[i].votes)
        {
            // Equalize it with MaximumVotes
            MaximumVotes = candidates[i].votes;
        }
    }
    // Now, show who the winner is
    for (int i = 0; i < candidate_count; i++)
    {
        // Find the one with the highest votes
        if (MaximumVotes == candidates[i].votes)
        {
            // Print their name
            printf("%s\n", candidates[i].name);
        }
    }
}