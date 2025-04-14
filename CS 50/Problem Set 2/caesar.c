#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key_1);

char rotate(int k, char ch);

int main(int argc, string key[])

{

    if ((argc != 2) || (!only_digits(key[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("Plaintext: ");

    int keyint = atoi(key[1]);

    for (int j = 0, len = strlen(plaintext); j < len; j++)
    {
        plaintext[j] = rotate(keyint, plaintext[j]);
    }

    string ciphertext = plaintext;
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool only_digits(string key_1)
{
    for (int i = 0, length = strlen(key_1); i < length; i++)
    {
        if (!isdigit(key_1[i]))
            return 0;
    }

    return 1;
}

char rotate(int k, char ch)
{
    if (isupper(ch))
    {
        ch = ((int) (ch - 'A') + k) % 26;
        ch += 'A';
    }

    else if (islower(ch))
    {
        ch = ((int) (ch - 'a') + k) % 26;
        ch += 'a';
    }

    return ch;
}
