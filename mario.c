#include <stdio.h> 
#include <cs50.h>

int main(void)
{ 
    int height; 

    // user input
    do  
    {
        height = get_int("Number: ");
    }
    while (height < 1 || height > 8);


    // first half of pyramid
    for (int vertical = 0; vertical < height; vertical++) 
    {
        //printing spaces
        for (int spaces = height - 1 - vertical; spaces > 0; spaces--) 
        {
            printf(" ");
        }
        // printing horizontal hash
        for (int horizontal = 0; horizontal < vertical + 1; horizontal++) 
        {
            printf("#");
        }

        // second side of the pyramid
        printf("  ");
        // printing second half
        for (int horizontal = 0; horizontal < vertical + 1; horizontal++) 
        {
            printf("#");
        }

        printf("\n");
    }
}