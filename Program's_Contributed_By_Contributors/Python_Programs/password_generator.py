#!/usr/bin/env python3
"""
Password Generator with Customizable Options
Author: AshutoshMore
GitHub: https://github.com/AshutoshMore142k4
Description: A comprehensive password generator with various customization options
             including length, character sets, and strength indicators.
"""

import random
import string
import secrets
import re

class PasswordGenerator:
    def __init__(self):
        self.lowercase = string.ascii_lowercase
        self.uppercase = string.ascii_uppercase
        self.digits = string.digits
        self.special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?"
        
    def generate_password(self, length=12, use_uppercase=True, use_lowercase=True, 
                         use_digits=True, use_special=True, exclude_ambiguous=False):
        """
        Generate a password with specified criteria
        
        Args:
            length (int): Length of the password (default: 12)
            use_uppercase (bool): Include uppercase letters
            use_lowercase (bool): Include lowercase letters
            use_digits (bool): Include digits
            use_special (bool): Include special characters
            exclude_ambiguous (bool): Exclude ambiguous characters (0, O, l, 1, etc.)
        
        Returns:
            str: Generated password
        """
        if length < 4:
            raise ValueError("Password length must be at least 4 characters")
        
        # Build character set
        char_set = ""
        
        if use_lowercase:
            chars = self.lowercase
            if exclude_ambiguous:
                chars = chars.replace('l', '').replace('o', '')
            char_set += chars
            
        if use_uppercase:
            chars = self.uppercase
            if exclude_ambiguous:
                chars = chars.replace('I', '').replace('O', '')
            char_set += chars
            
        if use_digits:
            chars = self.digits
            if exclude_ambiguous:
                chars = chars.replace('0', '').replace('1', '')
            char_set += chars
            
        if use_special:
            char_set += self.special_chars
        
        if not char_set:
            raise ValueError("At least one character type must be selected")
        
        # Generate password using cryptographically secure random
        password = ''.join(secrets.choice(char_set) for _ in range(length))
        
        # Ensure password contains at least one character from each selected type
        required_chars = []
        if use_lowercase:
            required_chars.append(secrets.choice(self.lowercase))
        if use_uppercase:
            required_chars.append(secrets.choice(self.uppercase))
        if use_digits:
            required_chars.append(secrets.choice(self.digits))
        if use_special:
            required_chars.append(secrets.choice(self.special_chars))
        
        # Replace some random characters with required characters
        if required_chars:
            password_list = list(password)
            for i, req_char in enumerate(required_chars):
                if i < len(password_list):
                    password_list[i] = req_char
            
            # Shuffle to randomize positions
            random.shuffle(password_list)
            password = ''.join(password_list)
        
        return password
    
    def check_password_strength(self, password):
        """
        Check the strength of a password
        
        Args:
            password (str): Password to check
            
        Returns:
            dict: Dictionary containing strength information
        """
        score = 0
        feedback = []
        
        # Length check
        if len(password) >= 12:
            score += 2
        elif len(password) >= 8:
            score += 1
        else:
            feedback.append("Password should be at least 8 characters long")
        
        # Character variety checks
        if re.search(r'[a-z]', password):
            score += 1
        else:
            feedback.append("Add lowercase letters")
            
        if re.search(r'[A-Z]', password):
            score += 1
        else:
            feedback.append("Add uppercase letters")
            
        if re.search(r'[0-9]', password):
            score += 1
        else:
            feedback.append("Add numbers")
            
        if re.search(r'[!@#$%^&*()_+\-=\[\]{}|;:,.<>?]', password):
            score += 1
        else:
            feedback.append("Add special characters")
        
        # Determine strength level
        if score >= 6:
            strength = "Very Strong"
        elif score >= 5:
            strength = "Strong"
        elif score >= 3:
            strength = "Medium"
        elif score >= 2:
            strength = "Weak"
        else:
            strength = "Very Weak"
        
        return {
            'score': score,
            'strength': strength,
            'feedback': feedback
        }
    
    def generate_multiple_passwords(self, count=5, **kwargs):
        """Generate multiple passwords with the same criteria"""
        passwords = []
        for _ in range(count):
            passwords.append(self.generate_password(**kwargs))
        return passwords

def print_password_with_strength(generator, password):
    """Print password with strength analysis"""
    strength_info = generator.check_password_strength(password)
    
    print(f"\n🔐 Generated Password: {password}")
    print(f"📊 Strength: {strength_info['strength']} (Score: {strength_info['score']}/7)")
    
    if strength_info['feedback']:
        print("💡 Suggestions for stronger password:")
        for suggestion in strength_info['feedback']:
            print(f"   • {suggestion}")

def main():
    """Main function to run the password generator"""
    generator = PasswordGenerator()
    
    print("🔒 Advanced Password Generator")
    print("=" * 50)
    
    while True:
        print("\nOptions:")
        print("1. Generate a single password")
        print("2. Generate multiple passwords")
        print("3. Check password strength")
        print("4. Generate passphrase")
        print("5. Exit")
        
        choice = input("\nSelect an option (1-5): ").strip()
        
        if choice == '1':
            # Single password generation
            try:
                length = int(input("Enter password length (default 12): ") or "12")
                
                print("\nCharacter types to include:")
                use_upper = input("Include uppercase letters? (Y/n): ").lower() != 'n'
                use_lower = input("Include lowercase letters? (Y/n): ").lower() != 'n'
                use_digits = input("Include digits? (Y/n): ").lower() != 'n'
                use_special = input("Include special characters? (Y/n): ").lower() != 'n'
                exclude_ambiguous = input("Exclude ambiguous characters (0,O,l,1)? (y/N): ").lower() == 'y'
                
                password = generator.generate_password(
                    length=length,
                    use_uppercase=use_upper,
                    use_lowercase=use_lower,
                    use_digits=use_digits,
                    use_special=use_special,
                    exclude_ambiguous=exclude_ambiguous
                )
                
                print_password_with_strength(generator, password)
                
            except ValueError as e:
                print(f"❌ Error: {e}")
        
        elif choice == '2':
            # Multiple passwords generation
            try:
                count = int(input("How many passwords to generate (default 5): ") or "5")
                length = int(input("Enter password length (default 12): ") or "12")
                
                passwords = generator.generate_multiple_passwords(
                    count=count,
                    length=length
                )
                
                print(f"\n🔐 Generated {count} passwords:")
                for i, password in enumerate(passwords, 1):
                    strength = generator.check_password_strength(password)
                    print(f"{i:2d}. {password} - {strength['strength']}")
                
            except ValueError as e:
                print(f"❌ Error: {e}")
        
        elif choice == '3':
            # Password strength check
            password = input("Enter password to check: ")
            if password:
                strength_info = generator.check_password_strength(password)
                print(f"\n📊 Password Strength: {strength_info['strength']}")
                print(f"Score: {strength_info['score']}/7")
                
                if strength_info['feedback']:
                    print("\n💡 Suggestions for improvement:")
                    for suggestion in strength_info['feedback']:
                        print(f"   • {suggestion}")
                else:
                    print("✅ This is a strong password!")
        
        elif choice == '4':
            # Simple passphrase generator
            words = [
                "apple", "banana", "ocean", "mountain", "river", "forest", "sunset", "rainbow",
                "butterfly", "thunder", "whisper", "breeze", "crystal", "diamond", "golden",
                "silver", "purple", "emerald", "crimson", "azure", "mystic", "cosmic", "stellar"
            ]
            
            word_count = int(input("Number of words (default 4): ") or "4")
            separator = input("Word separator (default -): ") or "-"
            add_numbers = input("Add numbers? (Y/n): ").lower() != 'n'
            
            passphrase_words = random.sample(words, min(word_count, len(words)))
            
            if add_numbers:
                passphrase_words.append(str(random.randint(100, 999)))
            
            passphrase = separator.join(passphrase_words)
            
            print(f"\n🔐 Generated Passphrase: {passphrase}")
            print_password_with_strength(generator, passphrase)
        
        elif choice == '5':
            print("\n👋 Thank you for using the Password Generator!")
            break
        
        else:
            print("❌ Invalid choice. Please select 1-5.")

if __name__ == "__main__":
    main()