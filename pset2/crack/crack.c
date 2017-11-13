#include <cs50.h>
#include <ctype.h>
#include <crypt.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    // get key from command line argument and checks for proper format
    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    string hash = argv[1];
    string salt = "50";


    return 0;
}