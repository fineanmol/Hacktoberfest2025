import math

p = int(input("enter p: "))
q = int(input("enter q: "))
n = p * q
print("n =", n)
phi = (p - 1) * (q - 1)
e = int(input("enter e: "))
while e < phi:
    if math.gcd(e, phi) == 1:
        break
    else:
        e += 1
print("e =", e)
d = pow(e, -1, phi)
print("d =", d)
print(f'Public key: {e, n}')
print(f'Private key: {d, n}')
msg = int(input("enter the message: "))
print(f'Original message: {msg}')
C = pow(msg, e, n)
print(f'Encrypted message: {C}')
M = pow(C, d, n)
print(f'Decrypted message: {M}')
