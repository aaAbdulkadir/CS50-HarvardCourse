#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // if input is not 2 i.e. ./mycaesar 2, it will prompt user to print
    // and return 1 means an error so it wont go any further
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //user input plaintext
    string plaintext = get_string("plaintext: ");

    // how much we want to shift our encryption
    int shift = atoi(argv[1]);
    // atoi changes the string into an integer. The array position argv[1]
    // represents the input from the user which will be a number

    for (int k = 0; k < strlen(argv[1]); k++)
    {
        if(!isdigit(argv[1][k]))
        { 
            return 1;
        }
    }

    //ciphertext
    printf("ciphertext: ");

    //loop
    for (int i = 0; i < strlen(plaintext); i++)
    {
        //consider the case when the text input are not letters over the iteration i
        if (!isalpha(plaintext[i]))
        {
            //if not letters, it is numbers or symbols which is kept the same
            printf("%c", plaintext[i]);
        }
        else
        {
            //else meaning it is letters thus needs to be split for lowercase and upper.
            //if greater than Z it means it has to be lowercase according to ASCII
            if (plaintext[i] > 'Z')
            {
                printf("%c", (plaintext[i] - 'a' + shift) % 26 + 'a');
            }
            else
            {
                //if else, it is a letter and < Z, it means the letter is uppercase
                printf("%c", (plaintext[i] - 'A' + shift) % 26 + 'A');
            }
        }
    }
    printf("\n");
}
