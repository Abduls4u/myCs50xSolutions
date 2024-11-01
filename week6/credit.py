class Card:
    def __init__(self, valid=False, prefix=0, length=0):
        self.valid = valid
        self.prefix = prefix
        self.length = length

def checksum(num):
    count = 0
    temp_num = num

    # Get the length of the card number
    while temp_num != 0:
        count += 1
        temp_num //= 10

    # Store the card number in a list
    digits = [int(d) for d in str(num).zfill(count)]

    # Calculate the checksum
    sum_digits = 0
    for i in range(count - 2, -1, -2):
        sum_digits += sum_of_digits(digits[i] * 2)
    for i in range(count - 1, -1, -2):
        sum_digits += digits[i]

    # Determine if the card is valid
    valid = (sum_digits % 10 == 0)
    prefix = digits[0] * 10 + digits[1]
    return Card(valid, prefix, count)

def sum_of_digits(n):
    sum_digits = 0
    while n != 0:
        sum_digits += n % 10
        n //= 10
    return sum_digits

def main():
    num = int(input("Please type in your card number: "))

    main_card = checksum(num)
    length = main_card.length
    prefix = main_card.prefix
    valid = main_card.valid

    print("count is", length)
    if valid and ((prefix >= 34 and prefix <= 37) and length == 15):
        print("AMEX")
    elif valid and ((prefix >= 51 and prefix <= 55) and length == 16):
        print("MASTERCARD")
    elif valid and ((prefix >= 40 and prefix <= 49) and (length == 13 or length == 16)):
        print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
