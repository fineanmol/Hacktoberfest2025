import time

print("  ██████  █████  ███████ ███████  █████  ██████       ██████ ██ ██████  ██   ██ ███████ ██████  ")
print(" ██      ██   ██ ██      ██      ██   ██ ██   ██     ██      ██ ██   ██ ██   ██ ██      ██   ██ ")
print(" ██      ███████ █████   ███████ ███████ ██████      ██      ██ ██████  ███████ █████   ██████  ")
print(" ██      ██   ██ ██           ██ ██   ██ ██   ██     ██      ██ ██      ██   ██ ██      ██   ██ ")
print("  ██████ ██   ██ ███████ ███████ ██   ██ ██   ██      ██████ ██ ██      ██   ██ ███████ ██   ██ ")
print("                                                                                               ")


constant="abcdefghijklmnopqrstuvwxyz0123456789"
lenght=len(constant)                                                                                             

print("RULES\ne- Encryption\nd- Decryption \ny- Yes\nn- No\nKey must be in number")

def encrypt_decrypt(text, mode, key):
    plaintext=" "
    if mode == "d":
        key = -key

    for letter in text:
        if " " == letter:
            plaintext += " "
        if not letter == " ":
            index = constant.find(letter)
            if index == -1:
                plaintext += letter
            else:
                new_index = index + key
                if new_index >= lenght:
                    new_index -= lenght
                elif new_index < 0:
                    new_index += lenght
                plaintext += constant[new_index]
    return plaintext.casefold()

def load():
    print("loading...")
    for i in range(15):
        print("█",end="")
        time.sleep(0.35)
    print()


x=True
while(x):
    mode=input("Choose your mode (e/d): ").lower()
    if mode == 'e':
        type="decrypt"
        print("____________________ Encrption started ____________________")
        key=int(input(f"Enter the key (1-{lenght}): "))
        text=input("Enter your Plaintext: ").lower()
        final = encrypt_decrypt(text,mode,key)
        load()
        print(f"Encrypted message: {final}")

    if mode == 'd':
        type="encrypt"
        print("____________________ Decrption started ____________________")
        key=int(input(f"Enter the key (1-{lenght}): "))
        text=input("Enter your Ciphertext: ").lower()
        final = encrypt_decrypt(text,mode,key)
        load()
        print(f"Decrypted message: {final}")
    
    try_again=input(f"Want to {type} the message (y/n): ")
    if try_again == "y":
        x=True
    else:
        x=False
