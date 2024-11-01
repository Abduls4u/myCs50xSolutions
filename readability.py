import re
from math import round

class Readability:
    def __init__(self, l_count=0, w_count=0, s_count=0):
        self.l_count = l_count
        self.w_count = w_count
        self.s_count = s_count

def compute_count(text):
    readable = Readability()
    readable.w_count = 1  # Start with 1 to count the first word

    for char in text:
        # Count letters
        if char.isalpha():
            readable.l_count += 1
        # Count sentences
        if char in ['.', '!', '?']:
            readable.s_count += 1
        # Count words
        if char == ' ':
            readable.w_count += 1

    return readable

def main():
    text = input("Text: ")
    readable = compute_count(text)
    
    # Calculate L and S
    L = round((readable.l_count / readable.w_count) * 100)
    S = round((readable.s_count / readable.w_count) * 100)
    
    # Calculate the Coleman-Liau index
    index = round((0.0588 * L) - (0.296 * S) - 15.8)
    
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")

if __name__ == "__main__":
    main()
