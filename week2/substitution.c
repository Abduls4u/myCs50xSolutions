#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool is_valid(char  *str);
void encipher(char *str, char *key);

int main(int argc, char *argv[])
{
     // Check that there is exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Set key to second cmdline argument
    char *key = argv[1];

    // Validate key
    if (!is_valid(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    char *plaintext = get_string("Plaintext:  ");

    // Encrypt and output ciphertext
    encipher(plaintext, key);

    return (0);
}

bool is_valid(char *key)
{
    // validate key length
    if (strlen(key) != 26)
    {
        return (false);
    }


    // Create a boolean array to check if alphabet is already present
    bool letters[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return (false);
        }
        int position = tolower(key[i]) - 'a';
        // Check if a letter is in current position
        if (letters[position])
        {
            return (false);
        }
        // Set the letter in current position to true
        letters[position] = true;
    }
    return (true);
}

void encipher(char *plaintext, char *key)
{
    printf("Ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        
        if (isalpha(c))
        {
            // Get the position of the character
            int index = tolower(c) - 'a';
            // Use the position to index the key array and also set its value to its corresponding case
            char cipher_char = isupper(c) ? toupper(key[index]) : tolower(key[index]);
            printf("%c", cipher_char);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}