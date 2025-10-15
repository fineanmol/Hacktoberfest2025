def print_H():
    print("*   *")
    print("*   *")
    print("*****")
    print("*   *")
    print("*   *")

def print_A():
    print("  *  ")
    print(" * * ")
    print("*****")
    print("*   *")
    print("*   *")

def print_C():
    print(" ****")
    print("*    ")
    print("*    ")
    print("*    ")
    print(" ****")

def print_K():
    print("*   *")
    print("*  * ")
    print("***  ")
    print("*  * ")
    print("*   *")

def print_O():
    print(" *** ")
    print("*   *")
    print("*   *")
    print("*   *")
    print(" *** ")

def print_T():
    print("*****")
    print("  *  ")
    print("  *  ")
    print("  *  ")
    print("  *  ")

def print_E():
    print("*****")
    print("*    ")
    print("**** ")
    print("*    ")
    print("*****")

def print_R():
    print("**** ")
    print("*   *")
    print("**** ")
    print("*  * ")
    print("*   *")

def print_B():
    print("**** ")
    print("*   *")
    print("**** ")
    print("*   *")
    print("**** ")

def print_F():
    print("*****")
    print("*    ")
    print("**** ")
    print("*    ")
    print("*    ")

def print_S():
    print(" ****")
    print("*    ")
    print(" *** ")
    print("    *")
    print("**** ")

def print_letter(letter):
    letters = {
        'h': print_H,
        'a': print_A,
        'c': print_C,
        'k': print_K,
        'o': print_O,
        't': print_T,
        'e': print_E,
        'r': print_R,
        'b': print_B,
        'f': print_F,
        's': print_S,
    }
    func = letters.get(letter.lower())
    if func:
        func()
    else:
        print("     ")  
word = "hackoterbfest"

for ch in word:
    print_letter(ch)
    print()  
