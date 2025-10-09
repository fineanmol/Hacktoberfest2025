initial_key = "0001001100110100010101110111100110011011101111001101111111001101"
pc1_table = [
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
]
key_rotation_schedule = [
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1
]
pc2_table = [
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
]
initial_key = [int(bit) for bit in initial_key]
key_halves = [initial_key[pc1_table[i] - 1] for i in range(56)]
c0, d0 = key_halves[:28], key_halves[28:]
subkeys = []
for i in range(16):
    c0 = c0[key_rotation_schedule[i]:] + c0[:key_rotation_schedule[i]]
    d0 = d0[key_rotation_schedule[i]:] + d0[:key_rotation_schedule[i]]
    cd = c0 + d0
    subkey = [cd[pc2_table[i] - 1] for i in range(48)]
    subkeys.append(subkey)
for i, subkey in enumerate(subkeys):
    print(f"Subkey {i + 1}: {''.join(map(str, subkey))}")
