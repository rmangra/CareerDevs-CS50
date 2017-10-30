#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void) {
    string name = get_string();
    printf("%s\n", name);
    printf("%c\n", name[0]);
    if (isalpha(name[0]) == true) {

        printf("%c\n", name[0]);
    }

}