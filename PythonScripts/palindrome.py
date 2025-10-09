# Palindrome Checker
# This program checks whether a given string or number is a palindrome.

def is_palindrome(value):
    # Convert to string in case a number is given
    value_str = str(value)
    # Check if the string is equal to its reverse
    return value_str == value_str[::-1]

# User input
user_input = input("Enter a string or number to check if it's a palindrome: ")

# Check and print result
if is_palindrome(user_input):
    print(f"'{user_input}' is a palindrome! 🎉")
else:
    print(f"'{user_input}' is not a palindrome. ❌")
