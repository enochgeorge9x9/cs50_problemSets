//Program that build mario bricks

#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);

int main(void)
{
    int i, m, j;
    int input = get_positive_int();
    for (i = 0; i < input; i++)
    {
        //Prints spacees before the #
        for (m = input - 1; m > i; m--)
        {
            printf(" ");
        }

        //Prints the "#"
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        //Prints 2 spacees between the #
        for (m =0; m <1; m++)
        {
            printf("  ");
        }
        
        //Prints the after the middle spaces"#"
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}


//Promte user for positive integer
int get_positive_int(void)
{
    int n;
    do
    {
        do
        {
            n = get_int("Enter Height between 1 and 8: ");
        }
        while (n < 1);
    }
    while (n > 8);
    return n;
}