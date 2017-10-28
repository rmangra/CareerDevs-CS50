#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: "); // prompts user for height of pyramids
        height = get_int();
    }
    while (height < 0 || height > 23);

    for (int i = 0 ; i < height; i++)
    {

        for (int j = 1; j < height - i; j++)    // prints spaces for left pyramid

        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++) // prints hashes for left pyramid
        {
            printf("#");
        }

        printf ("  ");  //prints gap

        for (int l = 0; l <= i; l++) // prints hashes for right pyramid
        {
            printf("#");
        }

        printf("\n");   // prints new line
    }
}