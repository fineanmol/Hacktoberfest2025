def generate_spiral_pattern(n):
    # Initialize a 2D array with zeros
    spiral = [[0] * n for _ in range(n)]
    
    # Define the boundaries
    top, bottom, left, right = 0, n - 1, 0, n - 1
    num = 1  # Start with 1

    while top <= bottom and left <= right:
        # Fill the top row
        for i in range(left, right + 1):
            spiral[top][i] = num
            num += 1
        top += 1

        # Fill the right column
        for i in range(top, bottom + 1):
            spiral[i][right] = num
            num += 1
        right -= 1

        # Fill the bottom row
        for i in range(right, left - 1, -1):
            spiral[bottom][i] = num
            num += 1
        bottom -= 1

        # Fill the left column
        for i in range(bottom, top - 1, -1):
            spiral[i][left] = num
            num += 1
        left += 1

    # Print the spiral pattern
    for row in spiral:
        print(" ".join(f"{x:2}" for x in row))

# Example usage
n = 5  # Size of the spiral
generate_spiral_pattern(n)