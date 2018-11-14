#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])  // accepts command line arguments which will always be a string
{
    if (argc != 2)// more or less than one input will make argc not equal 2
    {
        printf("Please enter a single positive integer as a key\n");
        return 1;
    }

    int key = atoi(argv[1]); // convert the string at argv[1] to int

    if (key < 0) // the key needs to be a positive int
    {
        printf("Please enter a single positive integer as a key\n");
        return 1;
    }

    // we are given the cipher equation Ci = (Pi + k ) % 26. ASCII A is 65, ASCII a is 97. 'A' is the 0-th uppercase letter.
    // I need to subtract 65 from the given uppercase letter to access the index in the alphabet. Then I need to add the key to
    // shift the letter. From here I need the modulus of 26 in the event that the key is larger than 26. Finally
    // I need to add 65 back to the value to convert it back to an uppercase letter. Repeat for lowercase with 'a'.
    string message = get_string("Plaintext: ");

    for (int  i = 0, n = strlen(message); i < n; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                message[i] = ((message[i] - 65 + key) % 26) + 65;
            }
            if (islower(message[i]))
            {
                message[i] = ((message[i] - 97 + key) % 26) + 97;
            }
        }
    }
    printf("ciphertext: %s\n", message);
    return 0;
}