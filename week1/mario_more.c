#include <stdio.h>
#include <cs50.h>

// function declaration.
void mario(int n);


int main(void)
{
    int number;
    do
    {
        number = get_int("Type in an int: ");
    } while (number <= 0);
    
    mario(number);
    return (0);
}

// function definition
void mario(int n)
{
    // Print the other pyramid
    for (int i = n, m = 0; i > 0; i--, m++)
    {
        // first half
        int tmp = i - 1;
        for (int j = 0; j < tmp; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (n - tmp); k++)
        {
            printf("#");
        }

        // Space in between
        printf("  ");

        // Second half of the pyramid
        for (int l = 0; l <= m; l++)
        {
            printf("#");
        }

        putchar('\n');
    }

}