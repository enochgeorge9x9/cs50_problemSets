#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(void);
float dollars_cents(void);

int main(void)
{
    float cents = dollars_cents(); //storing the converted dollars to cents
    float remaining = cents; // Making a temp var to store cents so that it doesn't have to repeat the functions
    int total_coins = 0; //To keep track of how many coins were used
    while (remaining >= 25) //if its greater than 25 cents it will minus 25 from remaining
    {
        remaining -= 25;
        total_coins += 1;
    }

    while (remaining >= 10) //if its greater than 10 cents it will minus 210 from remaining
    {
        remaining -= 10;
        total_coins += 1;
    }

    while (remaining >= 5) //if its greater than 5 cents it will minus 5 from remaining
    {
        remaining -= 5;
        total_coins += 1;
    }

    while (remaining >= 1) //if its greater than 1 cents it will minus 1 from remaining
    {
        remaining -= 1;
        total_coins += 1;
    }
    printf("%i\n", total_coins); //Return the total number of coins used


}

//convers dollars to cents
float dollars_cents(void)
{
    float input  = get_positive_float();
    float cents = round(input * 100);
    return cents;


}

//Reprompt user to put a positive float number
float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0.00);
    return n;
}