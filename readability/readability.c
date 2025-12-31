#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string input = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);

    // Compute the Coleman-Liau index
    int grade = (int)round(0.0588 * l - 0.296 * s - 15.8);

    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int num_letter = 0;
    for (int i=0, len = strlen(text); i<len; i++)
    {
        if (isalpha(text[i]))
        {
            num_letter++;
        }
    }
    return num_letter;
}

int count_words(string text)
{
    // Return the number of words in text
    int num_words = 0;
    for (int i=0, len = strlen(text); i<len; i++)
    {
        if (isspace(text[i]))
        {
            num_words = num_words+1;
        }
    }
    return num_words;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int num_sent = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num_sent = num_sent+1;
        }
    }
    return num_sent;
}
