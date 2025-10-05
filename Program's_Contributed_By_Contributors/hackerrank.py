import random
import string

class Cipher:
    def __init__(self, key=None):
        self.key = key or self._generate_key()

    def _generate_key(self):
        chars = string.ascii_letters + string.digits
        return ''.join(random.choice(chars) for _ in range(32))

    def encrypt(self, text):
        encrypted = []
        for i, c in enumerate(text):
            k = self.key[i % len(self.key)]
            encrypted.append(chr((ord(c) + ord(k)) % 256))
        return ''.join(encrypted)

    def decrypt(self, text):
        decrypted = []
        for i, c in enumerate(text):
            k = self.key[i % len(self.key)]
            decrypted.append(chr((ord(c) - ord(k)) % 256))
        return ''.join(decrypted)

def palindrome_magic(s):
    return s == s[::-1]

def random_palindrome(length):
    half = ''.join(random.choice(string.ascii_lowercase) for _ in range(length // 2))
    if length % 2:
        mid = random.choice(string.ascii_lowercase)
        return half + mid + half[::-1]
    return half + half[::-1]

def main():
    cipher = Cipher()
    original = random_palindrome(11)
    encrypted = cipher.encrypt(original)
    decrypted = cipher.decrypt(encrypted)
    print('Key:', cipher.key)
    print('Original:', original)
    print('Encrypted:', encrypted)
    print('Decrypted:', decrypted)
    print('Is palindrome:', palindrome_magic(decrypted))

if __name__ == '__main__':
    main()