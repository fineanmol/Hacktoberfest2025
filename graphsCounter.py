def create_adjacent_matrix(A, n):
    matrix = [[0] * n for _ in range(n)]

    for u, v in A:
        matrix[u][v] = 1
        matrix[v][u] = 1

    return matrix

A = [(0, 1), (0, 3), (1, 2), (1, 5), (2, 3), (2, 6), (3, 4), (4, 5)]
n = 7


matrix = create_adjacent_matrix(A, n)
for i in range (n):
    print(f"Degree of {i} = {sum(matrix[i])}")
