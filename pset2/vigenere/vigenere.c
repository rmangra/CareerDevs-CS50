#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    // get key from command line argument
    if (argc != 2) {
        printf("Usage: ./vigenere key\n");
        return 1;

    }
    // iterate through each character of the key to make sure there no non-alphabetic characters
    for (int l = 0; l < strlen(argv[1]); l++) {
        if (!isalpha(argv[1][l])) {
            printf("Usage: ./vigenere key\n");
            return 1;
        }
    }
    // declare variables to make working with key value easier
    string key = argv[1];
    int keyLength = strlen(key);

    // prompt user for plaintext
    printf("plaintext: ");
    string p = get_string();
    //printf("%s\n", p);
    printf("ciphertext: ");

    // iterate throught each character in the plaintext string
    for (int i = 0, j = 0; i < strlen(p); i++) {

        // check if plaintext character is alphabetic
        if (isalpha(p[i])) {

            // adjusts key value
            if (isupper(key[j % keyLength])) {
                key[j % keyLength] -= 'A';
            } else if (islower(key[j % keyLength])) {
                key[j % keyLength] -= 'a';
            }

            // check if plaintext character is uppercase
            if (isupper(p[i])) {

                // shift plaintext character by key and prints ciphertext
                printf("%c", (((p[i] - 'A' + key[j % keyLength]) % 26) + 'A'));

                // check if plaintex character is lowercase
            } else if (islower(p[i])) {

                // shift plaintext character by key and prints ciphertext
                printf("%c", (((p[i] - 'a' + key[j % keyLength]) % 26) + 'a'));
            }

            j++;  // iterates the key position counter

        } else {
            // prints all non-alphabetic characters or spaces without ciphering them
            printf("%c", p[i]);
        }
    }
    printf("\n");
}