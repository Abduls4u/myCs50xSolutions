#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Create readability structure
typedef struct 
{
    float l_count;
    float w_count;
    float s_count;
} Readability;

Readability compute_count(char *text);

int main(void)
{
    char *str = get_string("Text: ");
    Readability readable = compute_count(str);
    float L = round((readable.l_count / readable.w_count) * 100);
    float S = round((readable.s_count / readable.w_count) * 100);
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

Readability compute_count(char *text)
{
    Readability readable;
    readable.l_count = 0;
    readable.w_count = 1;
    readable.s_count = 0;

    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        // count letters
        if (isalpha(c))
        {
            readable.l_count++;
        }

        // count sentence
        if (c == '.' || c == '!' | c == '?')
        {
            readable.s_count++;
        }

        // count words
        if (c == ' ')
        {
            readable.w_count++;   
        }
    }
    return (readable);
}