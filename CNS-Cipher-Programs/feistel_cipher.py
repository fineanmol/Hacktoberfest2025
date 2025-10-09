import binascii
import random

# Random bits key generation
def rand_key(p):
    key1 = ""
    p = int(p)
    for i in range(p):
        temp = random.randint(0, 1)
        temp = str(temp)
        key1 = key1 + temp
    return key1

# Function to implement bit exor
def exor(a, b):
    temp = ""
    for i in range(len(a)):
        if a[i] == b[i]:
            temp += "0"
        else:
            temp += "1"
    return temp

# Defining BinarytoDecimal() function
def BinaryToDecimal(binary):
    string = int(binary, 2)
    return string

# Taking input from the user for Plain Text
PT = input("Enter the Plain Text: ")
print("Plain Text is:", PT)

# Converting the plain text to ASCII
PT_Ascii = [ord(x) for x in PT]

# Converting the ASCII to 8-bit binary format
PT_Bin = [format(y, '08b') for y in PT_Ascii]
PT_Bin = "".join(PT_Bin)
n = len(PT_Bin) // 2
L1 = PT_Bin[0:n]
R1 = PT_Bin[n::]
m = len(R1)

# Generate Key K1 for the first round
K1 = rand_key(m)

# Generate Key K2 for the second round
K2 = rand_key(m)

# first round of Feistel
f1 = exor(R1, K1)
R2 = exor(f1, L1)
L2 = R1

# Second round of Feistel
f2 = exor(R2, K2)
R3 = exor(f2, L2)
L3 = R2

# Cipher text
bin_data = L3 + R3
str_data =' '
for i in range(0, len(bin_data), 7):
    temp_data = bin_data[i:i + 7]
    decimal_data = BinaryToDecimal(temp_data)
    str_data = str_data + chr(decimal_data)
print("Cipher Text:", str_data)

# Decryption
L4 = L3
R4 = R3
f3 = exor(L4, K2)
L5 = exor(R4, f3)
R5 = L4
f4 = exor(L5, K1)
L6 = exor(R5, f4)
R6 = L5
PT1 = L6 + R6
PT1 = int(PT1, 2)
RPT = binascii.unhexlify('%x' % PT1)
print("Retrieved Plain Text is: ", RPT)
