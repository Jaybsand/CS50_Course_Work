#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//create a variable possibly char or string that collects user input *COMPLETED*
//create a fuction to count words *COMPLETED*
//create a fuction to count letters *COMPLETED*
//create a fuction to count sentences *COMPLETED*
//count_letters function should count all single characters and return the total integer *COMPLETED*
//count_words function should ignore upper and lower case *MAYBE COMPLETED*
//count_words function should recognize spaces (isblank +1) *COMPLETED*
//count_sentences fuction should recognize punctuations (ispunct) *COMPLETED*
//calculate the int of letters words and sentences using coleman-liau *COMPLETED*
//Letters/Words * 100 = *COMPLETED*
//Sentences/Words * 100 = *COMPLETED*
//0.588 * Letters - 0.296 * Sentences - 15.8 *COMPLETED*
//output results with parameters if i < 1 printf("Before Grade 1"), if i is > 16 printf("Grade 16+") *COMPLETED*

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
void printGrade(int p);

int main(void)
{
    string sentence = get_string("Text: ");

    int l = count_letters(sentence);

    int w = count_words(sentence);

    int s = count_sentences(sentence);

    double let, sent;

    let = l / (float)w * 100;

    sent = s / (float)w * 100;

    int coleman = round(0.0588 * (float)let - 0.296 * (float)sent - 15.8);

    printGrade(coleman);

}


int count_letters(string text)
{
    int num = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            num++;
        }
    }

    return num;
}

int count_words(string text)
{
    int num = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            num++;
        }
    }
    return num;
}

int count_sentences(string text)
{
    int num = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num++;
        }
    }
    return num;
}

void printGrade(int p)
{
    if (p < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (p > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", p);
    }
}
