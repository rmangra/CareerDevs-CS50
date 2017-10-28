#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {

    float input;

    /*prompts user to enter amount of change owed in dollars
    and rejects entries that are strings or negative numbers
    */
    do {
        printf("O hai! How much change is owed?\n");
        input = get_float();
    } while (input <= 0);

    //converts dollars to cents and returns a rounded integer value
    int change;
    change =  round(input * 100);
    int count = 0;

    //checks if quarters can be returned and counts them
    while (change >= 25) {
       change = change - 25;
       count++;
    }

    //checks if dimes can be returned and counts them
    while (change < 25 && change >= 10) {
        change = change - 10;
        count++;
    }

    //checks if nickels can be returned and counts them
    while (change < 10 && change >= 5) {
        change = change - 5;
        count++;
    }

    //checks if pennies can be returned and counts them
    while (change > 0) {
        change = change - 1;
        count++;
    }

    //print number of coins used
    printf("%i\n", count);
}