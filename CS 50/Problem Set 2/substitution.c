#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int alphabet, samechar;
} general;

general keychecker(string k);
string cipher(string ptext, string keyone);

int main(int argc, string key[])

{
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    general gen = keychecker(key[1]);

    if (strlen(key[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (gen.alphabet)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if (gen.samechar)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: %s\n", cipher(plaintext, key[1]));

    return 0;
}

general keychecker(string k)
{
    general g;

    for (int i = 0, len = strlen(k); i < len; i++)
    {
        if (!isalpha(k[i]))
        {
            g.alphabet = 1;
            return g;
        }
    }

    int charlist[26] = {0};

    for (int j = 0, l = strlen(k); j < l; j++)
    {

        k[j] = toupper(k[j]);
        int index = k[j] - 'A';

        charlist[index] += 1;

        if (charlist[index] > 1)
        {
            g.samechar = 1;
            return g;
        }
    }

    g.alphabet = 0;
    g.samechar = 0;

    return g;
}

string cipher(string ptext, string keyone)
{

    for (int n = 0, ln = strlen(ptext); n < ln; n++)
    {
        int number = toupper(ptext[n]) - 'A';

        if (isupper(ptext[n]))
            ptext[n] = toupper(keyone[number]);

        else if (islower(ptext[n]))
            ptext[n] = tolower(keyone[number]);
    }

    return ptext;
}
