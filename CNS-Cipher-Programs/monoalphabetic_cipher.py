keys = {'a': 'z', 'b': 'y', 'c': 'x', 'd': 'w', 'e': 'v', 'f': 'u', 'g': 't', 'h': 's', 'i': 'r', 'j': 'q', 'k': 'p', 'l': 'o', 'm': 'n'}
reverse_keys = {value: key for key, value in keys.items()}

def encrypt(text):
    text = str(text).lower()
    encrypted = [keys.get(char, char) for char in text if char.isalpha()]
    return ''.join(encrypted)

def decipher(text):
    text = str(text).lower()
    decrypted = [reverse_keys.get(char, char) for char in text if char.isalpha()]
    return ''.join(decrypted)

def main():
    text_to_encrypt = input("Enter the text to encrypt: ")
    encrypted_text = encrypt(text_to_encrypt)
    print("Encrypted Text:", encrypted_text)

    decrypted_text = decipher(encrypted_text)
    print("Decrypted Text:", decrypted_text)

if __name__ == "__main__":
    main()
