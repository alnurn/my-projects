#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    int coins_counter;
    int coins[] = {25, 10, 5, 1};

    do
    {
        change = get_int("change owed: ");
    }
    while (change < 0);

    coins_counter = 0;

    for (int i = 0; i < 4; i++)
    {
        coins_counter += change / coins[i];
        change = change % coins[i];
    }

    printf("%i\n", coins_counter);
}
