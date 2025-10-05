"""
random_password.py
------------------
Generate a secure random password.
"""

import random
import string

def generate_password(length: int = 12) -> str:
    chars = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choice(chars) for _ in range(length))

if __name__ == "__main__":
    length = int(input("Enter password length: "))
    print(f"Your random password: {generate_password(length)}")
