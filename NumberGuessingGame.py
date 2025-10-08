import random
number = random.randint(1, 50)
guess = 0
while guess != number:
    guess = int(input("Guess: "))
    if guess < number:
        print("Too low")
    elif guess > number:
        print("Too high")
print("You guessed it!")
