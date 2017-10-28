#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes;
    do
    {
        printf("Minutes: ");  //Prompts user to enter number of minutes
        minutes = get_int();
    }
    while (minutes < 0);

    int bottles = minutes * 12;
    printf("Bottles: %i \n", bottles);
}
