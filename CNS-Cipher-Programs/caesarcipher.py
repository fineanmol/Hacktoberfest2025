def encrypt(text, s):
    result = ""
    for char in text:
        result += chr((ord(char) - 97 + s) % 26 + 97)
    return result

def decrypt(text, s):
    result = ""
    for char in text:
        result += chr((ord(char) - 97 - s) % 26 + 97)
    return result

def main():
    while True:
        text = input("Enter the text to encrypt/decrypt (or 'q' to quit): ").lower()
        if text == 'q':
            print("Exiting the program.")
            break
        
        s = int(input("Enter the shift value (an integer between 0 and 25): "))
        if s < 0 or s > 25:
            print("Error: Shift value must be between 0 and 25.")
            continue
        
        print("\nText     : " + text)
        print("Shift    : " + str(s))
        
        encrypted_text = encrypt(text, s)
        print("Encrypted Text : " + encrypted_text)
        
        decrypted_text = decrypt(encrypted_text, s)
        print("Decrypted Text : " + decrypted_text)

if __name__ == "__main__":
    main()
