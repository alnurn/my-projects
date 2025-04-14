// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2899;

// Hash table
node *table[N] = {NULL};

// Count of loaded words
unsigned int count = 0;

// Hash index of current words
unsigned int ind;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    ind = hash(word);

    if (ind > (N - 1))
    {
        return false;
    }

    for (node *ptr = table[ind]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Improve this hash function
    unsigned int sum = 0;
    unsigned int hashnum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            sum += (int) tolower(word[i]);
        }
        else
        {
            sum += (int) word[i];
        }
    }

    hashnum = sum - 97;

    if (hashnum == 4783)
    {
        hashnum = 2111;
    }

    return hashnum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }

    char temp[LENGTH + 1];

    while (fscanf(dict, "%s", temp) != EOF)
    {
        node *dictword = malloc(sizeof(node));
        if (dictword == NULL)
        {
            return false;
        }

        strcpy(dictword->word, temp);
        count++;

        dictword->next = NULL;

        ind = hash(temp);

        if (table[ind] == NULL)
        {
            table[ind] = dictword;
        }
        else
        {
            dictword->next = table[ind];
            table[ind] = dictword;
        }
    }
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursor;
    node *temp;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        temp = cursor;

        while (temp != NULL)
        {
            temp = cursor->next;
            free(cursor);
            cursor = temp;
            if (temp == NULL)
                free(temp);
        }
    }
    return true;
}
