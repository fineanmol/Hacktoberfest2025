import time 

print("  _____                              ______                             _   _      ")       
print(" |_   _|                            |  ____|                           | | (_)      ")      
print("   | |  _ __ ___   __ _  __ _  ___  | |__   _ __   ___ _ __ _   _ _ __ | |_ _  ___  _ __  ")
print("   | | | '_ ` _ \ / _` |/ _` |/ _ \ |  __| | '_ \ / __| '__| | | | '_ \| __| |/ _ \| '_ \  ")
print("  _| |_| | | | | | (_| | (_| |  __/ | |____| | | | (__| |  | |_| | |_) | |_| | (_) | | | |  ")
print(" |_____|_| |_| |_|\__,_|\__, |\___| |______|_| |_|\___|_|   \__, | .__/ \__|_|\___/|_| |_|  ")
print("                         __/ |                               __/ | |                       ")
print("                        |___/                               |___/|_|      ")


print()

def rules():
    print("_____________ RULES _____________")
    print("e - Encryption \nd - Decryption \nKEY must be in number\ny - YES\nn - NO")


def load():
    print("loading...")
    for i in range(15):
        print("█",end="")
        time.sleep(0.35)
    print()

rules()

def encrypt_decrypt():
    try:
        path = input(r'Enter the path of the image: ')

        key = int(input("Enter the key: "))

        fin = open(path,'rb')

        image = fin.read()
        fin.close()

        image = bytearray(image)
        
        for index ,values in enumerate(image):
            image[index] = values ^ key

        fin = open(path,'wb')
        fin.write(image)
        fin.close()

    except Exception:
        print("Error caught: ",Exception._name_)

def choice():
    choice = input("Do you want to encrypt or decrypt the image (e/d): ").lower()
    return choice

X=True
while(X):
    c = choice()
    if c == 'e':
        encrypt_decrypt()
        load()
        print("_____________________ Encryption Done _____________________")
        X=False
    elif c == 'd':
        encrypt_decrypt()
        load()
        print("_____________________ Decryption Done _____________________")
        X=False
    else:
        print("Try again...")
        X=True
