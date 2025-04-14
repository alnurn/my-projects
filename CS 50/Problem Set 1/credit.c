#include <cs50.h>
#include <stdio.h>

#define amex 15
#define amexstart_one 34
#define amexstart_two 37

#define visa_first 13
#define visa_second 16
#define visa_start 4

#define mastercard 16
#define mastercard_d 51
#define mastercard_u 55

typedef struct
{
    int counter, total_sum;
} general;

general result(long int num);

int main(void)
{
    long int credit_number;
    int first_dgs;
    int first_dg;

    credit_number = get_long("Enter the number card\n");

    general gen = result(credit_number);
    char str[gen.counter];
    sprintf(str, "%li\n", credit_number);
    sscanf(str, "%2i", &first_dgs);
    sscanf(str, "%1i", &first_dg);

    if ((gen.counter == amex) && (gen.total_sum % 10 == 0) &&
        (first_dgs == amexstart_one || first_dgs == amexstart_two))
    {
        printf("AMEX\n");
    }
    else if ((gen.counter == visa_first || gen.counter == visa_second) &&
             (gen.total_sum % 10 == 0) && (first_dg == visa_start))
    {
        printf("VISA\n");
    }
    else if ((gen.counter == mastercard) && (gen.total_sum % 10 == 0) &&
             (first_dgs >= mastercard_d) && (first_dgs <= mastercard_u))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

general result(long int num)
{
    general g;
    int counter = 0, sum = 0, sum_d = 0, remainder_digit = 0, digit, remainder;

    do
    {
        remainder = num % 10;
        num = num / 10;

        if ((counter % 2) > 0)
        {
            digit = remainder * 2;

            for (int i = 0; i < 2; i++)
            {
                remainder_digit = digit % 10;
                sum_d += remainder_digit;
                digit /= 10;
            }
        }
        else
            sum += remainder;

        counter++;
    }
    while (num > 0);
    g.counter = counter;
    g.total_sum = sum_d + sum;

    return (g);
}
