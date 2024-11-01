#include <stdio.h>
#include <cs50.h>

typedef struct
{
    bool valid;
    int prefix;
    int len;
} Card;

Card checksum(long int num);
int sum_of_digits(int n);

int main(void)
{
    long int num = get_long("Please type in your card number: ");

    Card main_card = checksum(num);
    int len = main_card.len;
    int prefix = main_card.prefix;
    bool valid = main_card.valid;

    printf("count is %d", len);
    if (valid && ((prefix >= 34 && prefix <= 37) && len == 15))
    {
        printf("AMEX\n");
    }
    else if (valid && ((prefix >= 51 && prefix <= 55) && len == 16))
    {
        printf("MASTERCARD\n");
    }
    else if (valid && ((prefix >= 40 && prefix <= 49) && (len == 13 || len == 16)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

Card checksum(long int num)
{
    Card currrent_card;
    
    int sum = 0;
    // Get the length of the card number
    int count = 0;
    for (long int tmp = num; tmp != 0; count++)
    {
        tmp /= 10;
    }

    // Store the card number in an array
    int digits[count];
    for (int i = count - 1; i >= 0; i--)
    {
        digits[i] = num % 10;
        num /= 10;
    }

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
    for (int i = count - 2; i >= 0; i -= 2)
    {
        sum += sum_of_digits((digits[i] * 2));
    }

    // Get the sum of digits that weren't multiplied by 2
    for (int i = count - 1; i >= 0; i -= 2)
    {
        sum += digits[i];
    }    

    // Test its last digit if its a valid card number
    if (sum % 10 == 0)
    {
        currrent_card.valid = true;
    }
    else
    {
        currrent_card.valid = false;
    }
    currrent_card.prefix = (digits[0] * 10) + digits[1];
    printf("%d\n", sum);
    currrent_card.len = count;
    return (currrent_card);
}

int sum_of_digits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return (sum);
}