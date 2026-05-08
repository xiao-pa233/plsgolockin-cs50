#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//prototype
int key_char(string input);
int key_len(string input);
int char_rep(string input);

//will read user input auto
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (key_len(argv[1]) != 0)
    {
        return 1;
    }

    if (key_char(argv[1]) != 0)
    {
        return 1;
    }

    if (char_rep(argv[1]) != 0)
    {
        return 1;
    }

    string key = argv[1];

    string text = get_string("plaintext:  ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = toupper(key[text[i] - 'A']);
            }
            else
            {
                text[i] = tolower(key[text[i] - 'a']);
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}

//key is distinctive
int char_repeat(string input)
{
    int exist[26] = {0}; //set 26 int values to 0

    for (int i=0; i<26; i++)
    {
        exist[toupper(input[i]) - 'A']++;
    }

    for (int i=0; i<26; i++)
    {
        if (exist[i] != 1)
        {
            return 1;
        }
    }
        return 0;

}

//key length
int key_len(string input)
{
    if (strlen(input) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    else
    {
        return 0;
    }

}

//key alphabetical
int key_char(string input)
{
    int string_len = strlen(input);
    for (int i=0; i < string_len; i++)
    {
        if (!isalpha(input[i]))
        {
            printf("Key must not contain characters other than alphabets.");
            return 1;
        }
    }
        return 0;

}
