#include <stdio.h> 
#include <cs50.h>
#include <math.h>

int main(void)
{
    // user input: input a float which can hold any change value other than negatives
    float userInput;
    
    do
    {
        userInput = get_float("Change owed: ");
    }
    while (userInput <= 0);

    // multiply 100 to get accurate float
    float amount_left = round(userInput * 100);

    int number_of_coins = 0;
    
    // Greedy algorithm

    // Quarter
    while (amount_left >= 25) 
    {
        amount_left = amount_left - 25;
        number_of_coins++;
    }

    // Dime
    while (amount_left >= 10) 
    {
        amount_left = amount_left - 10;
        number_of_coins++;
    }

    // Nickel
    while (amount_left >= 5) 
    {
        amount_left = amount_left - 5;
        number_of_coins++;
    }
   
    // Penny
    while (amount_left >= 1) 
    {
        amount_left = amount_left - 1;
        number_of_coins++;
    }
    
    printf("%d\n", number_of_coins);
}