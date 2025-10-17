def gcd(n, m):
    """Compute the greatest common divisor of n and m using Euclid's algorithm."""
    # Input validation
    if not isinstance(n, int) or not isinstance(m, int):
        raise TypeError("Both inputs must be integers")
    
    num1, num2 = abs(n), abs(m)
    
    # Handle edge case where both numbers are zero
    if num1 == 0 and num2 == 0:
        raise ValueError("GCD is undefined for both numbers being zero")
    
    # Handle case where one number is zero
    if num1 == 0:
        return num2
    if num2 == 0:
        return num1
    
    # Euclidean algorithm - FIXED: proper variable assignment
    while num2:
        num1, num2 = num2, num1 % num2
    
    return num1

if __name__ == "__main__":
    try:
        n = int(input("Enter the first number: "))
        m = int(input("Enter the second number: "))
        result = gcd(n, m)
        print(f"GCD of {n} and {m} is: {result}")
    except ValueError as e:
        print(f"Error: {e}")
    except TypeError as e:
        print(f"Error: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")