#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

bool validate_key(char arg[]);

//* int main(int argc, char *argv[])
int main(void)
{
    //*Checking if the key is valide or not

    //!dont need for the final script
    char *argv[200] = {"ji", "VCHPRZGJNTLSKFBDQWAXEUYMOI"};
    int argc = 2;
    //!Nope dont need this in final output

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }

    else if (argc != 2 || !validate_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //*Getting the User Prompt
    // char text[500];
    // do
    // {
    //     printf("plaintext: ");
    //     fgets(text, sizeof(text), stdin);
    // } while (strlen(text) - 1 == 0);

    //!Temp
    string text = "hello, world";
    printf("plaintext: %s\n", (string) text);

    //*Encrypt the plaintext
    string ciphertext = text;
    string key = argv[1];
    printf("%s\n%s", ciphertext,key);
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if(isalpha(text[i]))
        {
            if(isupper(text[i]))
            {
                 ciphertext[i] = key[text[i] - 'A'] + 'A';
            }
            else
            {
                 ciphertext[i] = key[text[i] - 'a'] + 'a';   
            }
            
        }
    }

    printf("ciphertext: %s", ciphertext);

    

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