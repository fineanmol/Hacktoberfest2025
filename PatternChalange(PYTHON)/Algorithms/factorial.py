# Contributor: [Your GitHub Username]
# Hacktoberfest 2025 Contribution

def factorial(n):
    """Calculates the factorial of a non-negative integer."""
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Example usage:
number = 5
print(f"The factorial of {number} is: {factorial(number)}")