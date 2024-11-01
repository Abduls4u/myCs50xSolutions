#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int compute_score(char *str);

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    char *player1 = get_string("First word: ");
    char *player2 = get_string("Second word: ");

    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!!!!\n");
    }
}

int compute_score(char *str)
{
    int score = 0;

    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isupper(str[i]))
        {
            score += POINTS[str[i] - 'A'];
        }
        else if (islower(str[i]))
        {
            score += POINTS[str[i] - 'a'];
        }
    }
    return (score);
}