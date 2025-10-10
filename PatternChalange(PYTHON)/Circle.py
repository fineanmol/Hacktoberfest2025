# Python program to print a circle pattern using ASCII characters

# Set the radius of the circle
radius = 10

# Loop through rows (y-axis)
for y in range(-radius, radius + 1):
    # Loop through columns (x-axis)
    for x in range(-radius, radius + 1):
        # Equation of a circle: x² + y² = r²
        # We check if the point (x, y) lies close to the circle's boundary
        if abs(x**2 + y**2 - radius**2) < radius:
            print("*", end="")  # Print a star for the circle outline
        else:
            print(" ", end="")  # Print a space elsewhere
    print()  # Move to the next line
