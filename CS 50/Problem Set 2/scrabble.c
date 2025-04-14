#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int add(string s);
int scorenumbers[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{

    string player_1 = get_string("Player1: ");
    string player_2 = get_string("Player2: ");

    int p_1 = add(player_1);
    int p_2 = add(player_2);

    if (p_1 > p_2)
        printf("Player 1 wins \n");
    else if (p_1 < p_2)
        printf("Player 2 wins \n");
    else
        printf("It's tie ! \n");
}

int add(string s)
{
    int sum = 0;

    for (int i = 0, length_1 = strlen(s); i < length_1; i++)
    {
        s[i] = toupper(s[i]);

        if (isalpha(s[i]))
        {
            int index = s[i] - 'A';
            sum += scorenumbers[index];
        }
    }
    return sum;
}
