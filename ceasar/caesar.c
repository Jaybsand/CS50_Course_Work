#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// Step 1. creating a fucntion that takes command line argument in this case char type. *COMPLETED*
// Step 2. checking to make sure there is no more then 2 arguments if more user will be advised. *COMPLETED*
// Step 3. checking the command line arguments to see if they are alphabetical if so user will be advise. *COMPLETED*
// Step 4. converting char command line argument into a integer using atoi. *COMPLETED*
// Step 5. prompt the user for strings they want to encrypt *COMPLETED*
// Step 6. create a fuction that can check text for upper and lower case and special characters *COMPLETED*
// Step 7. using caeser formula  Ci = (Pi + K) % 26 to shift char *COMPLETED*
// Step 8. end result is printf ciphertext *COMPLETED*

void encryptor(char *text, int key);

int main(int argc, char *argv[]) // Step 1.
{
    if (argc == 2) // Step 2.
    {
        for (int i = 0; argv[1][i] != '\0'; i++) // Step 3.
        {
            if (isalpha(argv[1][i]) != 0)
            {
                printf("Usage: ./caesar key");
                printf("\n");
                return 1;
            }
        }
    }

    else if (argc < 2)
    {
        printf("Usage: ./caesar key");
        printf("\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./caesar key");
        printf("\n");
        return 1;
    }

    int key = atoi(argv[1]); // Step 4.
    char *plaintext = get_string("Enter Text: "); // Step 5.

    encryptor(plaintext, key); // Step 8.

}


void encryptor(char *text, int key) // Step 6.
{
    printf("ciphertext: "); // Step 9.

    for (int i = 0; text[i] != '\0'; i++) // creating a way to check each character in the plain text
    {
        if (islower(text[i])) // Step 6.
        {
            printf("%c", ((text[i] - 'a' + key) % 26) + 'a'); // Step 7.
        }
        else if (isupper(text[i]))
        {
            printf("%c", ((text[i] - 'A' + key) % 26) + 'A');
        }
        else if (text[i])
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}