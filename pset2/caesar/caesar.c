#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> //Using atoi function (to covert string into a number)
#include <cs50.h>
#include <string.h>

char encipher_text(char text[], int key);
bool validate_key(char arg[]);

int main(int argc, char *argv[])
{
    if (argc != 2 || !validate_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    char text[500];
    do
    {
        printf("plaintext: ");
        fgets(text, sizeof(text), stdin);
    } while (strlen(text) - 1 == 0);

    char encipher = encipher_text(text, key);
    // printf("ciphertext: %c\n", encipher);
}

//*Encrypt the given text with the key given
char encipher_text(char text[], int key)
{
    char formula;
    printf("ciphertext: ");
    for (long i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            //* Ci = (Pi +k) % 26
            int m = 65;
            if (islower(text[i]))
            {
                m = 97;
            }
            formula = (text[i] - m + key) % 26 + m;
            printf("%c", formula);
            // return formula;
        }
        else
            // return text[i];
            printf("%c", text[i]);
    }
    printf("\n");
    return 0;
}

//*Checking if the given argument is a digit
bool validate_key(char arg[])
{
    for (int i = 0, len = strlen(arg); i < len; i++)
    {
        if (!isdigit(arg[i]))
        {
            return false;
        }
    }
    return true;
}