#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    // get key from command line argument
    if (argc != 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // turn key into integer
    int k = atoi(argv[1]);
    k %= 26;
    printf("key: %i\n", k);

    // prompt user for plaintext
    printf("plaintext:");
    string p = get_string();

    printf("ciphertext:");

    // iterate throught each character in the plaintext string
    for (int i = 0; i < strlen(p); i++) {

        // check if character is alphabetic
        if (isalpha(p[i])) {

            // check if character is uppercase
            if isupper(p[i]) {
                // shift plaintext character by key and prints ciphertext
                printf("%c", (((p[i] - 'A' + k) % 26) + 'A'));
            } else {
                printf("%c", (((p[i] - 'a' + k) % 26) + 'a'));
            }
        } else {
            printf("%c", p[i]);
        }
    }
    printf("\n");

}