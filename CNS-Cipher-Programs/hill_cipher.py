keyMatrix = [[0] * 3 for i in range(3)]
messageVector = [[0] for i in range(3)]
cipherMatrix = [[0] for i in range(3)]

def getKeyMatrix(key):
    k = 0
    for i in range(3):
        for j in range(3):
            keyMatrix[i][j] = ord(key[k]) % 65
            k += 1

def encrypt(messageVector):
    for i in range(3):
        for j in range(1):
            cipherMatrix[i][j] = 0
            for x in range(3):
                cipherMatrix[i][j] += (keyMatrix[i][x] * messageVector[x][j])
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26

def HillCipher(message, key):
    getKeyMatrix(key)
    for i in range(3):
        messageVector[i][0] = ord(message[i]) % 65
    encrypt(messageVector)
    CipherText = []
    for i in range(3):
        CipherText.append(chr(cipherMatrix[i][0] + 65))
    return "".join(CipherText)

def main():
    message = input("Enter the message to encrypt (3 characters): ").upper()
    if len(message) != 3 or not message.isalpha():
        print("Invalid message. Please enter exactly 3 alphabetical characters.")
        return

    key = input("Enter the key (9 characters): ").upper()
    if len(key) != 9 or not key.isalpha():
        print("Invalid key. Please enter exactly 9 alphabetical characters.")
        return

    ciphertext = HillCipher(message, key)
    print("Ciphertext:", ciphertext)

if __name__ == "__main__":
    main()
