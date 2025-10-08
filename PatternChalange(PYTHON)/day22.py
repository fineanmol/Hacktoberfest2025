print("Welcome to MeHalogen's Diamond Expo")
print("The number of carats are defined by the number of stars on one side of the diamond.")
print("The rate of diamonds is $1000 per carat.")
print("Enter the number of rows for the diamond pattern:")

n = int(input())
for i in range(2*n-1):
    if i < n:
        spaces = n - i - 1
        stars = i * 2 + 1
    else:
        spaces = i - n + 1
        stars = (2*n - i - 2) * 2 + 1
    print(" " * spaces + "*" * stars)


print("The total carats of the diamond is:", n)
print("The total cost of the diamond is: $", n*1000)
print("Thank you for visiting MeHalogen's Diamond Expo!")