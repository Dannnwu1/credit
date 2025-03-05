#include <cs50.h>
#include <stdio.h>

long get_card_nr(void);
int count_digit(long card_num);
bool check_digits(int digits);
int luhn_alg(long card_nr);
bool check_sum(int summ);
int get_first_2(long num, int num_len);

int main(void)
{
    // 1. prompt user for the creadit card number
    long card_nr = get_card_nr();
    // 2. count the digits of the number
    int card_dig = count_digit(card_nr);
    // printf("%i digits\n", card_dig);
    //   a.check if it is 13 digits or 16 digits
    if (check_digits(card_dig) != true)
    {
        printf("INVALID\n");
    }
    else
    {
        // printf("DIGITS VALID\n");
        // 3 .go with the Luhn's Algorithm
        int sum_card = luhn_alg(card_nr);
        // printf("%i\n", sum_card);
        // e. check if the digit's sum with 0 in the end
        if (check_sum(sum_card) != true)
        {
            printf("INVALID\n");
        }
        else
        {
            // 4.check which card is by the first 2 digits
            int first_2 = get_first_2(card_nr, card_dig);
            // printf("%i\n", first_2);
            // 5.print out the result
            if ((first_2 == 34 || first_2 == 37) && card_dig == 15)
            {
                printf("AMEX\n");
            }
            else if ((first_2 == 51 || first_2 == 52 || first_2 == 53 || first_2 == 54 ||
                      first_2 == 55) &&
                     card_dig == 16)
            {
                printf("MASTERCARD\n");
            }
            else if (((first_2 / 10) == 4) && (card_dig == 13 || card_dig == 16))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}

long get_card_nr(void)
{
    long card_nr;
    do
    {
        card_nr = get_long("Enter your credit card number: ");
    }
    while (card_nr < 0);
    return card_nr;
}

int count_digit(long card_num)
{
    int card_digits = 0;
    while (card_num > 0)
    {
        card_digits += 1;
        card_num /= 10;
    }
    return card_digits;
}

bool check_digits(int digits)
{
    if (digits == 13 || digits == 15 || digits == 16)
    {
        return true;
    }
    return false;
}

int luhn_alg(long card_nr)
{
    int digit_c = 1;
    int summ1 = 0;
    int summ2 = 0;
    while (card_nr > 0)
    {
        int digit = card_nr % 10;
        if (digit_c == 2) // a. get the second to last digits
        {
            digit *= 2;      // b. multiple 2
            if (digit >= 10) // check if the product is bigger than 10
            {
                digit = 1 + digit % 10; // reset the digit
            }
            summ1 += digit; // c. add the product digits
            digit_c = 1;
        }
        else if (digit_c == 1)
        {
            summ2 += digit; // d. sum the above step with the other digits
            digit_c += 1;   // digit_c up by 1
        }
        card_nr /= 10;
    }

    return summ1 + summ2;
}

bool check_sum(int summ)
{
    return summ % 10 == 0;
}

int get_first_2(long num, int num_len)
{
    if (num_len == 15)
    {
        return num / 10000000000000;
    }
    else if (num_len == 16)
    {
        return num / 100000000000000;
    }
    else if (num_len == 13)
    {
        return num / 100000000000;
    }
    return 0;
}
