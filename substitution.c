#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //input 2 argc in array
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // second input needs to be 26 letters all different characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) && strlen(argv[1]) == 26)
        {
            //comparing i and j to stop duplicate letters
            for (int j = i + 1; j < strlen(argv[1]); j++)
            {
                if (toupper(argv[1][j]) == toupper(argv[1][i]))
                {
                    printf("Characters must not repeat!\n");
                    return 1;
                }
                else
                {   
                    //everything is correct and apply substitution
                    
                    //user input plaintext
                    string plaintext = get_string("plaintext: ");
                    
                    //ciphertext
                    printf("ciphertext: ");
                                        
                    // sorting out the plaintext
                    for (int k = 0; k < strlen(plaintext); k++)
                    {   
                        //consider the case when the text input are not letters over the iteration i
                        if (!isalpha(plaintext[k]))
                        {
                            printf("%c", plaintext[k]);
                        }
                        else
                        {
                            //if letters...
                            // if lowercase
                            if (islower(plaintext[k]))
                            {
                                plaintext[k] = tolower(argv[1][plaintext[k] - 'a']);
                            }
                            //if not lower it is upper
                            else
                            {
                                plaintext[k] = toupper(argv[1][plaintext[k] - 'A']);
                            }
                            printf("%c", plaintext[k]);
                        }
                    }
                    printf("\n");
                    return 0; 
                }   
            }    
        }
        else
        {
            printf("Characters must be alphabets and 26 letters long\n");
            return 1;
        }
    }   
    printf("\n");
}
