#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>

int count_letter(char *text);
int count_word(char *word);

int main(void)
{
    char *text= "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.";
    // string text = get_string("Text: ");
    int letter = count_letter(text);
    int word = count_word(text);
    printf("%i letters(s)\n", letter);
}

int count_word(char *word)
{
    int count = 0;
    for(int i = 0,n = strlen(word); i < n; i++)
    {
        if(isalnum(word[i] != 0))
        {
            count += 1;
        }
    }
    printf("word: %i\n", count);
    return count;
}

int count_letter(char *letter)
{
    int count = 0;
    for(int i = 0,n = strlen(letter); i < n; i++)
    {
        printf("hi")
    }
    return count;
}