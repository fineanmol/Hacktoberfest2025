# Author : Raju Das
# Description : Print the letter " H " in pattern style.
# Hacktoberfest 2025 Contribution.

# Height of Letter H
n = 7

# Make sure n is odd
if(n % 2 == 0):
    print("Set n to odd number for a perfect H pattern.")
    
else:
    for rows in range(n):
        for cols in range(n):
            
            # Prints left vertical, right vertical & horizontal bar.
            if cols == 0 or cols == n-1 or rows == n // 2:
                print("*", end = "")
            else:
                print(" ", end = "")
        
        print()
