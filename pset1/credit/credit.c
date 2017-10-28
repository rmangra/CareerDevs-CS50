#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long cc, ccLength;
    int digits = 0;

    //prompt user for input
    do
    {
        cc = get_long_long("Number: ");
    }
    while (cc <= 0);
    ccLength = cc;

    //count the number of digits in cc number
    while (ccLength != 0)
    {
        ccLength /= 10;
        digits++;
    }

    //validate cc number length
    if (digits == 13 || digits == 15 || digits == 16)
    {
        //read cc number into an array to perform calcuations with Luhn's algorithm
        int ccArray [digits];
        for (int i = digits - 1; i >= 0; i--)
        {
            ccArray [i] = cc % 10;
            cc = cc / 10;
        }

        //multiply every other digit by 2 and then sum those digits
        int ccSum = 0;
        for (int j = digits - 2; j >= 0; j = j - 2)
        {
            if (ccArray[j] * 2 > 9)
            {
                ccSum += (ccArray[j] * 2) - 9;
            }
            else
            {
                ccSum += ccArray[j] * 2;
            }
        }

        //sum the remaining digits that were not multiplied by 2
        int ccSum2 = 0;
        for (int j = digits - 1; j >= 0; j = j - 2)
        {
            ccSum2 += ccArray[j];
        }

        //validate checksum
        if ((ccSum + ccSum2) % 10 == 0)
        {

            //validate company's identifier
            if (ccArray[0] == 4)
            {
                printf("VISA\n");
            }
            else if (ccArray[0] == 5 && (ccArray[1] == 1 || ccArray[1] == 2 || ccArray[1] == 3 || ccArray[1] == 4 || ccArray[1] == 5))
            {
                printf("MASTERCARD\n");
            }
            else if (ccArray[0] == 3 && (ccArray[1] == 4 || ccArray[1] == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    printf("INVALID\n");
    return 0;
}