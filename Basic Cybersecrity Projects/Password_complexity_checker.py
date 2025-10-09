import string

score = 0

def char_checker(password):

    lowercase = any([1 if i >= 'a' and i <= 'z' else 0 for i in password])
    uppercase = any([1 if i >= 'A' and i <= 'Z' else 0 for i in password])
    digits = any([1 if i >= '0' and i <= '9' else 0 for i in password])
    special = any([1 if i in string.punctuation else 0 for i in password])
    total = lowercase+uppercase+digits+special
    return total 



def checker(score):
    if score <= 2:
        print(f"Your password strength is Too Weak: {score}/8")
    elif score <= 4:
        print(f"Your password strength is Weak: {score}/8")
    elif score <= 5:
        print(f"Your password strength is Medium: {score}/8")
    elif score <= 7:
        print(f"Your password strength is Strong: {score}/8")
    elif score <= 8:
        print(f"Your password strength is Too Strong: {score}/8")
    else:
        print("Password invalid")



x=True
while(x):
    password = input("Enter your password: ")

    if len(password) > 8:
        score += 1
    if len(password) > 12:
        score += 1
    if len(password) > 16:
        score += 1
    if len(password) > 18:
        score += 1

    score += char_checker(password)
    checker(score)

    again = input("Do you want to check your password strength again? (y/n): ").lower()
    if again == 'n':
        x = False
        print("_____________________________________________________________________________")
    else:
        x = True
        print("_____________________________________________________________________________")

