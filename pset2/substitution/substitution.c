#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

bool validate_key(char arg[]);
void array_val(char pos, string key);

int main(int argc, char *argv[])                  
{
    //*Checking if the key is valide or not
    if(argc != 2 || !validate_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    

    string key = argv[1];

    //*Getting the User Prompt
    char text[500];
    do
    {
        printf("plaintext: ");
        fgets(text, sizeof(text), stdin);
    } while (strlen(text) - 1 == 0);


    //*Encrpytion
    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            char x = text[i];
            if (islower(text[i]))
            {
                array_val(tolower(x), key);
            }
            else
            {
                array_val(toupper(x), key);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

//*Mapping array with given user string
void array_val(char pos, string key)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0, len = strlen(alpha); i < len; i++)
    {
        if (islower(pos))
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}

//*Validating the key is given is corrent
bool validate_key(char arg[])
{
    for (int i = 0, len = strlen(arg); i < len; i++)
    {
        if (isdigit(arg[i]))
        {
            return false;
        }
        for (int n = i + 1; n < len; n++)
        {
            if (toupper(arg[n]) == toupper(arg[i]))
            {
                return false;
            }
        }
    }
    return true;
}