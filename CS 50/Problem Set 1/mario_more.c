#include <cs50.h>
#include <stdio.h>

void print_first(int size, int spaces);
void print_second(int space);

int main(void)
{
    int n;
    do
    {
        n = get_int("Size? ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        print_first(n, i);
        print_second(i);
    }
}

void print_first(int size, int spaces)

{
    for (int j = 0; j < size; j++)
    {
        if (j < (size - (spaces + 1)))
            printf(" ");
        else
            printf("#");
    }

    printf("  ");
}

void print_second(int space)
{
    for (int c = 0; c < (space + 1); c++)
    {
        printf("#");
    }

    printf("\n");
}
