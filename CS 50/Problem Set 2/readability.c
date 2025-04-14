#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int lettercount, sentencecount, wordcount;
} general;

general count(string t);

int main(void)
{

    string text = get_string("Text: ");
    general gen = count(text);

    float index = (5.88 * gen.lettercount / (float) gen.wordcount) -
                  (29.6 * gen.sentencecount / (float) gen.wordcount) - 15.8;

    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
    {
        int level = round(index);
        printf("Grade %i\n", level);
    }

    // printf("Letters, sentences, words %i %i %i\n", gen.lettercount, gen.sentencecount,
    // gen.wordcount);
}

general count(string t)
{
    general g;
    int lcount = 0;
    int scount = 0;
    int wcount = 0;

    for (int i = 0, l = strlen(t); i < l; i++)
    {
        if (isalpha(t[i]))
            lcount += 1;

        if ((t[i] == '.') || (t[i] == '!') || (t[i] == '?'))
            scount += 1;

        if (isspace(t[i]))
            wcount += 1;
    }
    g.lettercount = lcount;
    g.sentencecount = scount;
    g.wordcount = wcount + 1;

    return g;
}
