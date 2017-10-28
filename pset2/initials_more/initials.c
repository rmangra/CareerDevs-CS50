#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //Gets user's full name and stores it as a string
    string s = get_string();

    /*If the first item in the string is a letter,
    it will print the capital letter*/
    if (isalpha(s[0]))
    {
        printf("%c", toupper(s[0]));
    }

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        /*Evaluates where spaces are in the string,
        and checks the next element of the string*/
        while (isblank(s[i]))
        {
            i++;
            /*If the element in the string is a letter,
            it will print the capital letter*/
            if (isalpha(s[i]))
            {
                printf("%c", toupper(s[i]));
            }
        }
    }
    printf("\n"); //Prints the initials
}