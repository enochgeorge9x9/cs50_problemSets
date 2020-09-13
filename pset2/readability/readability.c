#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letter(char text[]);
long count_word(char word[]);
long count_sentence(char text[]);

int main(void)
{
    char text[500];
    do
    {
        printf("Text: ");
        fgets(text, sizeof(text), stdin);
    } while (strlen(text) - 1 == 0);

    //*letters words and sentences count
    int letter = count_letter(text);
    long word = count_word(text);
    long sentences = count_sentence(text);

    //*Calculating the Grade level index
    float L = (letter / (float)word) * 100;
    float S = ((float)sentences / word) * 100;
    float index = round((0.0588 * L) - (0.296 * S) - 15.8);

    //*Before Grade 1 and Grade 16+
    if (index <= 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

//*Calculating how many sentences are there in a paragraph
long count_sentence(char text[])
{
    long count = 0;
    for (long i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count += 1;
        }
    }
    return count;
}

//*Calculating how many words are there in senternce
long count_word(char word[])
{
    long count = 1;
    for (long i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == 32)
        {
            count += 1;
        }
    }
    return count;
}

int count_letter(char letter[])
{
    int count = 0;
    for (int i = 0, n = strlen(letter); i < n; i++)
    {
        if (isalnum(letter[i]))
        {
            count += 1;
        }
    }
    return count;
}