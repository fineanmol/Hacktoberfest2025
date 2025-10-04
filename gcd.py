def gcd(n, m):
    """Compute the greatest common divisor of n and m using Euclid's algorithm."""
    num1, num2 = abs(n), abs(m)
    while num2:
        num1, num2 = num1, num1 % num2

    if num1 == 0 and num2:
        print("GCD is undefined for both numbers being zero.")
    elif num1 == 0:
        print(abs(num2))
    elif num2 == 0:
        print(abs(num1))
    else:
        print(num1)

if __name__ == "__main__":
    n = int(input("Enter the first number: "))
    m = int(input("Enter the second number: "))
    gcd(n, m)