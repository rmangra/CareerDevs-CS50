#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");  // prompts user for height of pyramid
        height = get_int();
    }
    while (height < 0 || height > 23);  //constrains user inputs to between 0-23

    for (int i = 0 ; i < height; i++)
    {

        for (int j = 1; j < height - i; j++)  // prints spaces for pyramid

        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)  // prints hashes for pyramid
        {
            printf("#");
        }

        printf("#\n");  //prints an extra hash and a new line

    }
}