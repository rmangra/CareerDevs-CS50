#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    // Gets user's full name and stores it as a string
    string s = get_string();

    // Check if first index of the string is a letter
    if (isalpha(s[0])) {
        // Print capitalized letter
        printf("%c", toupper(s[0]));
    }
    // Iterate through the length of the string
    for (int i = 0; i < strlen(s); i++) {
        // Increment counter when blank space is encountered
        while (isblank(s[i])) {
            i++;
            // Check for letter at index i
            if (isalpha(s[i])) {
            // Print capitalized letter
            printf("%c", toupper(s[i]));
            }
        }
    }
    printf("\n");
}