#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])  // accepts command line arguments which will always be a string
{
    printf("%s\n", argv[1]);
    if (argc != 2)// more or less than one input will make argc not equal 2
    {
        printf("Please enter a single word as a key\n");
        return 1;
    }


    //need to ensure key is alpha only
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Please enter a single word as a key\n");
            return 1;
        }
    }

    string key = argv[1]; //key needs to be all lower case
    int keyLen = strlen(key);
    for (int kl = 0; kl < keyLen; kl++)
    {
        key[kl] = tolower(key[kl]);
    }
    // we are given the cipher equation Ci = (Pi + Kj ) % 26. ASCII A is 65, ASCII a is 97. 'A' is the 0-th uppercase letter.
    // I need to subtract 65 from the given uppercase letter to access the index in the alphabet. Then I need to add the key to
    // shift the letter. From here I need the modulus of 26 in the event that the key is larger than 26. Finally
    // I need to add 65 back to the value to convert it back to an uppercase letter. Repeat for lowercase with 'a'.
    // ONLY do this if the character in plaintext is a letter.

    string message = get_string("Plaintext: ");

    for (int  i = 0, n = strlen(message), j = 0; i < n; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                message[i] = ((message[i] - 'A') + (key[(j++) % keyLen] - 'a')) % 26 + 'A';
            }
            else if (islower(message[i]))
            {
                message[i] = ((message[i] - 'a') + (key[(j++) % keyLen] - 'a')) % 26 + 'a';
            }
        }
    }

    printf("ciphertext: %s\n", message);
    return 0;

}