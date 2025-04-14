#include <cs50.h>
#include <stdio.h>

void print_pyr(int size, int dots);

int main(void)
{
    int n;
    do
    {
        n = get_int("Size? ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        print_pyr(n, i);
    }
}

void print_pyr(int size, int dots)
{
    for (int j = 0; j < size; j++)
    {
        if (j < (size - (dots + 1)))
            printf(" ");
        else
            printf("#");
    }

    printf("\n");
}
