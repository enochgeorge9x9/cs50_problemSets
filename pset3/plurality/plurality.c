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

    // int voter_count[1];
    // printf("Number of Voters: ");
    // scanf("%i", (int)voter_count);

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        // char name[MAX];
        // printf("Vote: ");
        // fgets(name, sizeof(name), stdin);

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
    //look for the candidate called name
    for (int i = 0; i < candidate_count; i++)
    {
        //if candidate found, update their vote total and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    //if no candidate found, don't update any vote totals and return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //find the highest number of votes
    int maxvotes = 0;
    for(int i=0; i < candidate_count; i++)
    {
        if(candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }

    //printing the winner of the highest votes
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
