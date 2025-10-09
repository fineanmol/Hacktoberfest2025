import random

def hangman():
    # Simple word list
    words = ['python', 'computer', 'programming', 'hangman', 'challenge', 'developer']
    
    # Choose random word
    word = random.choice(words).lower()
    guessed = set()
    wrong_guesses = 0
    max_wrong = 6
    
    print("Welcome to Hangman!")
    
    while wrong_guesses < max_wrong:
        # Display current state
        display = ''.join([char if char in guessed else '_' for char in word])
        print(f"\nWord: {display}")
        print(f"Wrong guesses: {wrong_guesses}/{max_wrong}")
        print(f"Guessed letters: {', '.join(sorted(guessed))}")
        
        # Check if won
        if '_' not in display:
            print(f"\nCongratulations! You won! The word was '{word}'")
            break
        
        # Get user input
        guess = input("Enter a letter: ").lower()
        
        # Validate input
        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a single letter.")
            continue
        
        if guess in guessed:
            print("You already guessed that letter.")
            continue
        
        # Process guess
        guessed.add(guess)
        
        if guess in word:
            print(f"Good guess! '{guess}' is in the word.")
        else:
            wrong_guesses += 1
            print(f"Sorry, '{guess}' is not in the word.")
    
    else:
        print(f"\nGame Over! The word was '{word}'")

# Run the game
if __name__ == "__main__":
    hangman()
