from functools import reduce
from random import randint, choice
import string

def gen_matrix(n):
    return [[randint(1, 99) for _ in range(n)] for _ in range(n)]

def spiral_order(matrix):
    res = []
    while matrix:
        res += matrix.pop(0)
        if matrix and matrix[0]:
            for row in matrix:
                res.append(row.pop())
        if matrix:
            res += matrix.pop()[::-1]
        if matrix and matrix[0]:
            for row in matrix[::-1]:
                res.append(row.pop(0))
    return res

def encrypt(text, key):
    return ''.join(chr((ord(c) + key) % 256) for c in text)

def decrypt(text, key):
    return ''.join(chr((ord(c) - key) % 256) for c in text)

def random_string(n):
    return ''.join(choice(string.ascii_letters + string.digits) for _ in range(n))

n = randint(4, 8)
mat = gen_matrix(n)
spiral = spiral_order([row[:] for row in mat])
key = reduce(lambda x, y: x ^ y, spiral)
msg = random_string(n * 2)
enc = encrypt(msg, key)
dec = decrypt(enc, key)
print(f"Matrix: {mat}\nSpiral: {spiral}\nKey: {key}\nMsg: {msg}\nEnc: {enc}\nDec: {dec}")