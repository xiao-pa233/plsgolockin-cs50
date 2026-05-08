#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int sum_scores(string input);
string results(int n1, int n2);

int scores[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(void)
{
    string input_one = get_string("Player 1: ");
    string input_two = get_string("Player 2: ");

    int score_one = sum_scores(input_one);
    int score_two = sum_scores(input_two);

    printf("%s", results(score_one, score_two));

}

int sum_scores(string input)
{
    int sum = 0;
 
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        if (islower(input[i]))
        {
            sum += scores[input[i] - 'a'];
        }

        else if (isupper(input[i]))
        {
            sum += scores[input[i] - 'A'];
        }
    }

    return sum;
}


string results(int n1, int n2)
{
    if(n1 > n2)
    {
        return "Player 1 wins!\n";
    }
    else if(n2 > n1)
    {
        return "Player 2 wins!\n";
    }
    else
    {
        return "Tie!\n";
    }
}

