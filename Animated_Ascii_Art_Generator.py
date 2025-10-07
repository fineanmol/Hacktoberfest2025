#!/usr/bin/env python3
"""
🎨 SIMPLE ASCII ART GENERATOR 🎨
Create ASCII art from user input text
"""

import time

class SimpleAsciiArt:
    def __init__(self):
        # ASCII font dictionary - block style
        self.font = {
            'A': ['██████', '██  ██', '██████', '██  ██', '██  ██'],
            'B': ['██████', '██  ██', '██████', '██  ██', '██████'],
            'C': ['██████', '██    ', '██    ', '██    ', '██████'],
            'D': ['██████', '██  ██', '██  ██', '██  ██', '██████'],
            'E': ['██████', '██    ', '██████', '██    ', '██████'],
            'F': ['██████', '██    ', '██████', '██    ', '██    '],
            'G': ['██████', '██    ', '██  ██', '██  ██', '██████'],
            'H': ['██  ██', '██  ██', '██████', '██  ██', '██  ██'],
            'I': ['██████', '  ██  ', '  ██  ', '  ██  ', '██████'],
            'J': ['██████', '    ██', '    ██', '██  ██', '██████'],
            'K': ['██  ██', '██ ██ ', '████  ', '██ ██ ', '██  ██'],
            'L': ['██    ', '██    ', '██    ', '██    ', '██████'],
            'M': ['██  ██', '██████', '██████', '██  ██', '██  ██'],
            'N': ['██  ██', '██████', '██████', '██████', '██  ██'],
            'O': ['██████', '██  ██', '██  ██', '██  ██', '██████'],
            'P': ['██████', '██  ██', '██████', '██    ', '██    '],
            'Q': ['██████', '██  ██', '██  ██', '██ ███', '██████'],
            'R': ['██████', '██  ██', '██████', '██ ██ ', '██  ██'],
            'S': ['██████', '██    ', '██████', '    ██', '██████'],
            'T': ['██████', '  ██  ', '  ██  ', '  ██  ', '  ██  '],
            'U': ['██  ██', '██  ██', '██  ██', '██  ██', '██████'],
            'V': ['██  ██', '██  ██', '██  ██', ' ████ ', '  ██  '],
            'W': ['██  ██', '██  ██', '██████', '██████', '██  ██'],
            'X': ['██  ██', ' ████ ', '  ██  ', ' ████ ', '██  ██'],
            'Y': ['██  ██', '██  ██', ' ████ ', '  ██  ', '  ██  '],
            'Z': ['██████', '   ██ ', '  ██  ', ' ██   ', '██████'],
            ' ': ['      ', '      ', '      ', '      ', '      '],
            '!': ['  ██  ', '  ██  ', '  ██  ', '      ', '  ██  '],
            '?': ['██████', '    ██', '  ████', '      ', '  ██  '],
            '0': ['██████', '██  ██', '██  ██', '██  ██', '██████'],
            '1': ['  ██  ', ' ███  ', '  ██  ', '  ██  ', '██████'],
            '2': ['██████', '    ██', '██████', '██    ', '██████'],
            '3': ['██████', '    ██', '██████', '    ██', '██████'],
            '4': ['██  ██', '██  ██', '██████', '    ██', '    ██'],
            '5': ['██████', '██    ', '██████', '    ██', '██████'],
            '6': ['██████', '██    ', '██████', '██  ██', '██████'],
            '7': ['██████', '    ██', '   ██ ', '  ██  ', ' ██   '],
            '8': ['██████', '██  ██', '██████', '██  ██', '██████'],
            '9': ['██████', '██  ██', '██████', '    ██', '██████'],
        }
    
    def create_ascii_art(self, text):
        """Convert text to ASCII art"""
        text = text.upper()
        lines = ['', '', '', '', '']  # 5 lines for each character
        
        for char in text:
            if char in self.font:
                char_lines = self.font[char]
                for i in range(5):
                    lines[i] += char_lines[i] + '  '  # Add spacing between characters
            else:
                # Use space for unknown characters
                for i in range(5):
                    lines[i] += '      '  # Empty space
        
        return lines
    
    def print_ascii_art(self, text, animate=False):
        """Print ASCII art to console"""
        ascii_lines = self.create_ascii_art(text)
        
        if animate:
            print("🎬 Creating your ASCII art...")
            time.sleep(0.5)
            for line in ascii_lines:
                for char in line:
                    print(char, end='', flush=True)
                    time.sleep(0.002)
                print()
                time.sleep(0.1)
        else:
            for line in ascii_lines:
                print(line)
    
    def create_banner(self, text):
        """Create a decorative banner"""
        length = len(text) + 4
        border = '═' * (length - 2)
        
        print(f"╔{border}╗")
        print(f"║  {text}  ║")
        print(f"╚{border}╝")


def main():
    """Main function to demonstrate ASCII art creation"""
    art_generator = SimpleAsciiArt()
    
    print("🎨" + "="*60 + "🎨")
    print("    WELCOME TO THE ASCII ART GENERATOR!")
    print("    Transform your text into amazing ASCII art!")
    print("🎨" + "="*60 + "🎨")
    
    while True:
        print("\n" + "─"*50)
        print("What would you like to create?")
        print("1. ASCII Art from text")
        print("2. Decorative banner")
        print("3. See example")
        print("4. Exit")
        print("─"*50)
        
        choice = input("\nEnter your choice (1-4): ").strip()
        
        if choice == '1':
            text = input("\nEnter your text: ").strip()
            if text:
                animate = input("🎬 Add typing animation? (y/n): ").lower().startswith('y')
                print(f"\nCreating ASCII art for: '{text}'")
                print("─" * 60)
                art_generator.print_ascii_art(text, animate)
            else:
                print("Please enter some text!")
        
        elif choice == '2':
            text = input("\nEnter banner text: ").strip()
            if text:
                print(f"\nCreating banner:")
                print("─" * 30)
                art_generator.create_banner(text)
            else:
                print("Please enter some text!")
        
        elif choice == '3':
            print("\nExample ASCII Art:")
            print("─" * 30)
            art_generator.print_ascii_art("HELLO")
            print("\nExample Banner:")
            print("─" * 30)
            art_generator.create_banner("Welcome!")
        
        elif choice == '4':
            print("\nThanks for using ASCII Art Generator!")
            print("Keep creating amazing art!")
            break
        
        else:
            print("Invalid choice! Please enter 1-4.")


if __name__ == "__main__":
    main()
