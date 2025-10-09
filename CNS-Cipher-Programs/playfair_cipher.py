def playfair_cipher(plaintext, key, mode):
    alphabet = 'abcdefghiklmnopqrstuvwxyz'
    key = key.lower().replace(' ', '').replace('j', 'i')
    key_square = ''
    for letter in key + alphabet:
        if letter not in key_square:
            key_square += letter
            
    plaintext = plaintext.lower().replace(' ', '').replace('j', 'i')
    if len(plaintext) % 2 == 1:
        plaintext += 'x'
    digraphs = [plaintext[i:i+2] for i in range(0, len(plaintext), 2)]
    
    def encrypt(digraph):
        a, b = digraph
        row_a, col_a = divmod(key_square.index(a), 5)
        row_b, col_b = divmod(key_square.index(b), 5)
        if row_a == row_b:
            col_a = (col_a + 1) % 5
            col_b = (col_b + 1) % 5
        elif col_a == col_b:
            row_a = (row_a + 1) % 5
            row_b = (row_b + 1) % 5
        else:
            col_a, col_b = col_b, col_a
        return key_square[row_a*5+col_a] + key_square[row_b*5+col_b]
    
    def decrypt(digraph):
        a, b = digraph
        row_a, col_a = divmod(key_square.index(a), 5)
        row_b, col_b = divmod(key_square.index(b), 5)
        if row_a == row_b:
            col_a = (col_a - 1) % 5
            col_b = (col_b - 1) % 5
        elif col_a == col_b:
            row_a = (row_a - 1) % 5
            row_b = (row_b - 1) % 5
        else:
            col_a, col_b = col_b, col_a
        return key_square[row_a*5+col_a] + key_square[row_b*5+col_b]
    
    result = ''
    for digraph in digraphs:
        if mode == 'encrypt':
            result += encrypt(digraph)
        elif mode == 'decrypt':
            result += decrypt(digraph)
    return result

plaintext = input("Enter the plain text: ")
key = input("Enter the key: ")
ciphertext = playfair_cipher(plaintext, key, 'encrypt')
print("CIPHER TEXT:", ciphertext)
decrypted_text = playfair_cipher(ciphertext, key, 'decrypt')
print("PLAIN TEXT:", decrypted_text)
