#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Gettting input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // scoring both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Loop for printing the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!!!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!!!\n");
    }
    else if (score1 == score2)
    {
        printf("it's a Tie!\n");
    }
}




int compute_score(string word)
{
// Computing and returning score for word
    int score = 0;  //intializing score to zero to calculate loop
    for (int i = 0, s = strlen(word); i < s; i++)
// variable i gets 0, variable s gets the length of word, if i os less then s add 1 to i
    {
        if (isupper(word[i])) // checking if uuper case
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i])) // cheking if lower case
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score; // return the results of the loop
}

