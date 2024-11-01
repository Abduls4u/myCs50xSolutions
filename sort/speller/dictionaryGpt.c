#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Number of buckets in the hash table, chosen based on performance needs
const unsigned int N = 10000;

// Hash table
node *table[N];

// Word count to track the size of the dictionary
unsigned int word_count = 0;

// Hash function - Generates a hash based on the sum of characters in the word
unsigned int hash(const char *word)
{
    unsigned long hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash * 31 + tolower(word[i])) % N; // Ensuring all lowercase, modulo to fit within bucket count
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer to store each word temporarily
    char word[LENGTH + 1];

    // Read each word from the dictionary file
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy the word into the node
        strcpy(new_node->word, word);

        // Hash the word to obtain an index
        unsigned int index = hash(word);

        // Insert node into hash table at the appropriate location
        new_node->next = table[index];
        table[index] = new_node;

        // Increment word count
        word_count++;
    }

    // Close the dictionary file
    fclose(file);

    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to get the index
    unsigned int index = hash(word);

    // Access the linked list at the hashed index
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Compare words case-insensitively
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    // If the word is not found
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Free linked list in each bucket
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
