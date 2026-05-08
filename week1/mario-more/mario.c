#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do

    {
        height = get_int("Height: ");
    }

    while (height <1 || height>8);

    for (int i=1; i<=height; i++)
    {
        for (int col = height - i; col>0; col--)
        {
            printf(" ");
        }

        for (int row=0; row<i; row++)
        {
            printf("#");
        }

        printf("  ");

        for (int row=0; row<i; row++)
        {
            printf("#");
        }

        printf("\n");
    }
}
