//user input the card num
//check if valid
    //
//if valid, check which type
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    long card;

    do
    {
        card = get_long("Number: ");
    }
    while(card<=0); //check if positive

    //to determine the length of card, add 1 for each loop

    int length_card = 0;

    //now we check if valid: start from 2nd last

    int total_sum = 0;
    long num_digit2 = card / 10;
    long num_digit = card;

    //first loop to calc sum digits multi by 2
    while(num_digit2 > 0)
    {
        int temp = (num_digit2 % 10)*2;

        if (temp >= 10)
        {
            total_sum += (temp % 10) + (temp / 10);
        }

        else
        {
            total_sum += temp;
        }

        num_digit2 = num_digit2 / 100;
        length_card ++;
    }

    //sum num that wasn't multi by 2
    while(num_digit>0)
    {
        total_sum += num_digit % 10;
        num_digit = num_digit /100;
        length_card ++;
    }


   //printf("%i\n", length_card);

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
    }

    else
    {   //express check

        //determine first 2 digits
        while (card>=100)
        {
            card = card / 10;
        }

        if((length_card == 15) && (card == 34 || card == 37))
        {
            printf("AMEX\n");
        }

        else if((length_card == 16) && (card >= 51 && card <= 55))
        {
            printf("MASTERCARD\n");
        }

        else if((length_card == 16 || length_card == 13) && (card >= 40 && card <= 49))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
}
