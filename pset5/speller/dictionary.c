// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

struct node
{
    char word[LENGTH +1];
    struct node *next;
}

typedef struct node *node_t;

node_t hashtable[HASHTABLE_SIZE]

// # words in dictionary
unsigned long words = 0;

// prototype
node_t make_node(const char *key)

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, 'r');
    if (!file)
    {
    return false;
    }

    //hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++ )
    {
        hashtable[i] = NULL;
    }

    char buffer[LENGTH]
    while fscanf((file, "%s", buffer) != EOF)
    {
        // all words in dictionary s/be lower case
        node_t node = make_node(buffer)

    }

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
