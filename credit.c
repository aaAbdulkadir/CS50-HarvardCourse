#include <stdio.h>
#include <cs50.h>
#include <math.h>

// validate a credit card, take the second last number and the numbers alternating before that and multiply it by two. if the number> 10 then add the digits within that number together. add it to the remaining numbers and if it ends in a zero, it is a credit card.
// to get the last digit, do % 10 and itll give you. to get the second last digit, divide by 100 then take the % of 10. this is process. i.e. loop

int main(void)
{
    // user input. must be so that a credit card number is input and not letters
    long credit_card_number;

    do
    {
        credit_card_number = get_long("Input your credit card number: ");
    }
    while (credit_card_number <= 0);

    // luhns algorith

    // this is for calculations later on
    long CC_number;
    CC_number = credit_card_number;

    // add the last number and the alternating numbers together

    long last_number, alternate_even, sum, division;
    long limit_1 = 1000000000000000;
    long sum_even = 0;

    last_number = credit_card_number % 10;

    for (division = 100; division <= limit_1; division = division * 100)
    {
        alternate_even = (credit_card_number / division) % 10;
        sum_even = sum_even + alternate_even;
    }
    sum = sum_even + last_number;

    // find the second last number and the alternating numbers and multiply by 2. if multiplication > 9 then add two digits.

    long alternate_odd, division2, bigger_than_9, sum_odd;
    long sum_odd_1 = 0;
    long sum_odd_2 = 0;

    for (division2 = 10; division2 <= limit_1; division2 = division2 * 100)
    {
        alternate_odd = ((credit_card_number / division2) % 10) * 2;

        if (alternate_odd > 9)
        {
            bigger_than_9 = (alternate_odd % 10) + (alternate_odd / 10);
            sum_odd_1 = sum_odd_1 + bigger_than_9;
        }

        else
        {
            sum_odd_2 = sum_odd_2 + alternate_odd;
        }
    }
    sum_odd = sum_odd_1 + sum_odd_2;

    // add the two results together. if number ends in 20 it is valid.

    long total_sum;
    total_sum = sum_odd + sum;

    // print whether it is AMEX, MASTERCARD, VISA or INVALID

    // finds number of digits in card

    int count = 0;

    while (credit_card_number > 0)
    {
        credit_card_number = credit_card_number / 10;
        count = count + 1;
    }

    // finds first two digits

    long digits, power;
    power = pow(10, (count - 2));
    digits = CC_number / power;

    // finds first digit

    long digit;
    power = pow(10, (count - 1));
    digit = CC_number / power;

    //American express - 15 digits, starts with 34 or 37
    // Mastercard - 16 digits, starts with 51 - 55
    // VISA - 13 or 16 digits starts with 4

    if (total_sum % 10 == 0)
    {
        if (count == 15 && (digits == 34 || digits == 37))
        {
            printf("AMEX\n");
            return 0;
        }

        else if ((count == 13 || count == 16) && digit == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (count == 16 && (digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }
}