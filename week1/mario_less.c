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
    for (int i = n; i > 0; i--)
    {
        int tmp = i - 1;
        for (int j = 0; j < tmp; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (n - tmp); k++)
        {
            printf("#");
        }
        putchar('\n');
    }
}