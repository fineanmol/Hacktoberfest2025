# Python3 program to check whether a 
# number is Palindrome or not. 

# Iterative function to reverse
# digits of num
def reverseDigits(num) : 

    rev_num = 0; 
    while (num > 0) :
        rev_num = rev_num * 10 + num % 10
        num = num // 10
    
    return rev_num 

# Function to check if n is Palindrome
def isPalindrome(n) :

    # get the reverse of n 
    rev_n = reverseDigits(n); 

    # Check if rev_n and n are same or not. 
    if (rev_n == n) :
        return 1
    else :
        return 0

# Driver Code
if __name__ == "__main__" :

    n = 4562
    
    if isPalindrome(n) == 1 :
        print("Is", n, "a Palindrome number? ->", True)
        
    else :
        print("Is", n, "a Palindrome number? ->", False)

    n = 2002
    
    if isPalindrome(n) == 1 :
        print("Is", n, "a Palindrome number? ->", True)
        
    else :
        print("Is", n, "a Palindrome number? ->", False)
